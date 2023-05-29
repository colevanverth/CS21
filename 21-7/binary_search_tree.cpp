/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file binary_search_tree.cpp
* @assignment 7: Binary Search Tree
*/

#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {} 

BinarySearchTree::~BinarySearchTree() {
   m_destruct(m_root); 
} 

void BinarySearchTree::m_destruct(Node* node) { 
   if (node) {
      auto left = node->left;
      auto right = node->right;
      delete node;
      m_destruct(left);
      m_destruct(right);
   }
}

BinarySearchTree::Status BinarySearchTree::search(int key) {
   if (m_search(m_root, key)) {
      return Status::FOUND; 
   }
   return Status::DNE; 
}

BinarySearchTree::Node* BinarySearchTree::m_search(Node* node, int key) {
   if (!node || node->key == key) {
      return node;  
   }
   if (key < node->key) {
      return m_search(node->left, key); 
   }
   else {
      return m_search(node->right, key); 
   }
} 

BinarySearchTree::Result BinarySearchTree::min() { 
   if (m_root) { // Min value only exists if tree has nodes
      return {Status::FOUND, m_min(m_root)->key}; 
   }
   return {Status::DNE, 0};
}

BinarySearchTree::Result BinarySearchTree::max() { 
   if (m_root) { // Max value only exists if tree has nodes
      return {Status::FOUND, m_max(m_root)->key};
   }
   return {Status::DNE, 0};
}

BinarySearchTree::Node* BinarySearchTree::m_max(Node* node) { 
   while (node->right) {
      node = node->right;
   }
   return node; 
}

BinarySearchTree::Node* BinarySearchTree::m_min(Node* node) {
   while (node->left) {
      node = node->left; 
   }
   return node; 
}

BinarySearchTree::Result BinarySearchTree::predecessor(int key) {
   auto keyNode = m_search(m_root, key); 
   if (!keyNode) { // `key` itself not in tree
      return {Status::INVALID_ARGUMENT, 0};
   }
   auto predecessorNode = m_predecessor(keyNode); 
   if (!predecessorNode) { // no predecessor
      return {Status::DNE, 0};
   }
   return {Status::FOUND, predecessorNode->key}; // predecessor found
}

BinarySearchTree::Result BinarySearchTree::successor(int key) {
   auto keyNode = m_search(m_root, key); 
   if (!keyNode) { // `key` itself not in tree
      return {Status::INVALID_ARGUMENT, 0}; 
   }
   auto successorNode = m_successor(keyNode); 
   if (!successorNode) { // no successor 
      return {Status::DNE, 0}; 
   }
   return {Status::FOUND, successorNode->key}; // successor found
}

BinarySearchTree::Node* BinarySearchTree::m_predecessor(Node* node) { 
   // CASE 1: predecessor is the maximum value "just less" than key of `node`
   if (node->left) { 
      return m_max(node->left); 
   }

   // CASE 2: predecessor is the node whose successor is key of `node`
   auto temp = node->parent;
   while (temp != nullptr && node == temp->left) {
      node = temp;
      temp = temp->parent;
   }
   return temp;
}

BinarySearchTree::Node* BinarySearchTree::m_successor(Node* node) { 
   // CASE 1: successor is the minimum value "just more" than key of `node`
   if (node->right) {
      return m_min(node->right); 
   }

   // CASE 2: successor is the node whose predecessor is key of `node`
   auto temp = node->parent; 
   while (temp != nullptr && node == temp->right) {
      node = temp;
      temp = temp->parent; 
   }
   return temp; 
}

void BinarySearchTree::insert(int key) {
   Node* node = new Node(key); 
   Node* temp = m_root; // used to search for position to place `node`
   Node* prev = nullptr; // trails behind `temp`

   // Search for position to place `node`
   while (temp) {
      prev = temp;
      if (node->key < temp->key) {
         temp = temp->left; 
      }
      else {
         temp = temp->right; 
      }
   }

   node->parent = prev; // `prev` is node above nullptr node
   
   if (!prev) { // tree empty edge case 
      m_root = node; 
      return; 
   }

   // Sets the children of `prev`
   if (node->key < prev->key) {
      prev->left = node; 
   }
   else {
      prev->right = node;  
   }
}

std::vector<int> BinarySearchTree::inOrderTraverse() {
   m_traversalBuffer.clear(); // Clear buffer
   m_inOrderTraverse(m_root); 
   return m_traversalBuffer; 
}

std::vector<int> BinarySearchTree::postOrderTraverse() {
   m_traversalBuffer.clear(); // Clear buffer
   m_postOrderTraverse(m_root);
   return m_traversalBuffer; 
}

std::vector<int> BinarySearchTree::preOrderTraverse() {
   m_traversalBuffer.clear(); // Clear buffer
   m_preOrderTraverse(m_root); 
   return m_traversalBuffer; 
}

void BinarySearchTree::m_inOrderTraverse(Node* node) { 
   if (node) {
      m_inOrderTraverse(node->left); 
      m_traversalBuffer.push_back(node->key); 
      m_inOrderTraverse(node->right);
   }
}

void BinarySearchTree::m_postOrderTraverse(Node* node) { 
   if (node) {
      m_postOrderTraverse(node->left);
      m_postOrderTraverse(node->right);
      m_traversalBuffer.push_back(node->key);
   }
}

void BinarySearchTree::m_preOrderTraverse(Node* node) { 
   if (node) {
      m_traversalBuffer.push_back(node->key);
      m_preOrderTraverse(node->left);
      m_preOrderTraverse(node->right);
   }
}

BinarySearchTree::Status BinarySearchTree::remove(int key) { 
   auto deleteNode = m_search(m_root, key);
   if (!deleteNode) { // `key` to delete does not exist 
      return Status::INVALID_ARGUMENT; 
   }
   m_remove(deleteNode); 
   return Status::FOUND; 
}

void BinarySearchTree::m_remove(Node* node) {
   // CASE 1/2: `node` has zero or one child
   if (!node->left) {
      m_transplant(node, node->right);
   }   
   else if (!node->right) {
      m_transplant(node, node->left); 
   }
   
   // CASE 3: `node` has two children 
   else {
      auto successor = m_successor(node);
      if (successor != node->right) { // `node` has a right subtree > 1 child
         // transplant successor with right child
         m_transplant(successor, successor->right);

         // update successor's new inherited right tree
         successor->right = node->right;
         successor->right->parent = successor; 
      }
      // transplate successor to `node` itself
      m_transplant(node, successor);

      // update successor's new inherited left tree 
      successor->left = node->left; 
      successor->left->parent = successor;
   }
   delete node;
} 

void BinarySearchTree::m_transplant(Node* remove, Node* merge) { 
   if (!remove->parent) { // edge case where `remove` is the root 
      m_root = merge; 
   }
   else if (remove->parent->left == remove) { // `remove` is a left child
      remove->parent->left = merge;
   }
   else { // `remove` is a right child
      remove->parent->right = merge; 
   }
   if (merge) { // `merge` exists 
      merge->parent = remove->parent; 
   }
};
