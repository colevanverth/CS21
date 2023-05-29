/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file list.cpp
* @assignment 1: Review; Linked Lists
*/

#include "list.h"

List::List() {}

List::~List() {
    auto deleteListNode = m_head;
    while (m_size > 0) {
        auto nextListNode = deleteListNode->right;
        delete deleteListNode;
        m_size--;
        deleteListNode = nextListNode;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

void List::insertEnd(std::string input) {
    auto newListNode = new ListNode;
    newListNode->data = input;
    if (m_size > 0) {
       auto prevListNode = m_tail;
       prevListNode->right = newListNode;
       newListNode->left = prevListNode;
       m_tail = newListNode;
    }
    else { 
        m_tail = newListNode; 
        m_head = newListNode; 
    }
    m_size++;
}

void List::insertStart(std::string input) {
    auto newListNode = new ListNode;
    newListNode->data = input;
    if (m_size > 0) { 
        auto prevListNode = m_head; 
        prevListNode->left = newListNode;
        newListNode->right = prevListNode;
        m_head = newListNode;
    }
    else { 
        m_tail = newListNode;
        m_head = newListNode;
    }
    m_size++;
}

void List::removeStart() {
    if (m_size >= 1){
        if (m_size == 1) {
            auto deleteListNode = m_head;
            delete deleteListNode;
            m_tail = nullptr;
            m_head = nullptr;
        }
        else { 
            auto deleteListNode = m_tail;
            auto adjustListNode = deleteListNode->right;
            adjustListNode->left = nullptr;
            delete deleteListNode;
            m_head = adjustListNode; 
        }
        m_size--;
    }
}

void List::removeEnd() {
    if (m_size >= 1) {
        if (m_size == 1) {
            auto deleteListNode = m_tail;
            delete deleteListNode;
            m_tail = nullptr;
            m_head = nullptr;
        }
        else { 
            auto deleteListNode = m_tail;
            auto adjustListNode = deleteListNode->left;
            delete deleteListNode;
            adjustListNode->right = nullptr;
            m_tail = adjustListNode; 
        }
        m_size--;
    }
}

std::string List::getData(ListNode* node) {
    if (node != nullptr) {
        return node->data;
    }
    else {
        return "";
    }
}

size_t List::getSize() { 
    return m_size; 
}

List::ListNode* List::removeNode(ListNode* node) { 
   m_size--;
   auto leftNode = node->left; 
   auto rightNode = node->right; 
   if (leftNode == nullptr) {
      m_head = rightNode;
      rightNode->left = nullptr;
   }
   else {
      leftNode->right = rightNode;
   }
   if (rightNode == nullptr) {
      m_tail = leftNode;
      leftNode->right = nullptr;   
   }
   else {
      rightNode->left = leftNode; 
   }
   delete node;
   return rightNode;

}

void List::splice(int pos, int len, List* otherList) {
	if (pos < 0 || pos >= m_size || pos - len + 1 < 0) { return; }
	auto indexer = m_head;
	auto index = 0;
	ListNode* left;
	ListNode* right;
	while (indexer != nullptr) {
		if (index == pos - len + 1) {
			left = indexer;
		}
		if (index == pos) {
			right = indexer;
		}
		indexer = indexer->right;
      index++;
	}
	m_size -= len;
	if (pos - len + 1 == 0) {
		m_head = right->right;
	}
	if (pos + 1 == m_size) {
		m_tail = left->left;
	}
	if (pos + 1 != m_size && pos - len + 1!= 0) {
		left->left->right = right->right;
		right->right->left = left->left;
	}
	left->left = nullptr;
	right->right = otherList->m_head;
	otherList->m_head = left;
}

void List::removeDuplicates() { 
   std::map<std::string, bool> duplicates; 
   auto iterateNode = m_head; 
   while (iterateNode != nullptr) {
      if (duplicates.contains(iterateNode->data)) {
         iterateNode = removeNode(iterateNode);
      } 
      else {
         duplicates[iterateNode->data] = true;
         iterateNode = iterateNode->right;
      } 
   }
}

void List::reverse() {
   auto adjustNode = m_head;
   auto tempHead = m_head;
   m_head = m_tail;
   m_tail = tempHead;
   while (adjustNode != nullptr) {
      auto tempLeft = adjustNode->left;
      adjustNode->left = adjustNode->right;
      adjustNode->right = tempLeft;
      adjustNode = adjustNode->left;
   }
}

List::ListNode* List::getTail() { 
    return m_tail;
}

List::ListNode::ListNode() {}

