/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 7: Binary Search Tree
*/

/**
* This program implements a Binary Search Tree (BST). A "session trace" is read 
* from STDIN in `main` that allows the user to interact with the BST; the
* results of these operations are outputted to STDOUT. The program was tested by
* hand and with valgrind for memory leaks and appears to be working to all
* specifications. 
*/

#include <iostream>
#include <utility>
#include <string>
#include <sstream>

#include "binary_search_tree.h"

typedef std::pair<std::string, int> Command; // From parsed session trace

typedef BinarySearchTree BST; // For brevity

/**
* Processes a trace into a command. 
* @param `trace` trace of command 
* @return `Command` parsed from trace
*/
Command processTrace(std::string trace); 

/**
* Executes search on BST and prints results. 
* @param `tree` BST 
* @param `key` to search for
*/
void search(BST& tree, int key); 

/**
* Executes insert on BST and prints results. 
* @param `tree` BST
* @param `key` key to insert
*/
void insert(BST& tree, int key); 

/**
* Executes remove on BST and prints results. 
* @param `tree` BST
* @param `key` key to remove 
*/
void remove(BST& tree, int key);

/**
* Executes min on BST and prints the min.
* @param `tree` BST
*/
void min(BST& tree);

/**
* Executes max on BST and prints the max. 
* @param `tree` BST
*/
void max(BST& tree); 

/**
* Executes predecessor and prints results. 
* @param `tree` BST 
* @param `key` key to predecessor of
*/
void predecessor(BST& tree, int key); 

/**
* Executes successor and prints results. 
* @param `tree` BST
* @param `key` key to find successor of 
*/
void successor(BST& tree, int key); 

/**
* Traverses and prints BST in order.
* @param `tree` BST
*/
void inorder(BST& tree); 

/**
* Traverses and prints BST post order. 
* @param `tree` BST
*/
void postorder(BST& tree); 

/**
* Traverses and prints BST pre order. 
* @param `tree` BST 
*/
void preorder(BST& tree); 

/**
* Prints a vector containing traversal elements to STDOUT. 
* @param `vec` vector containing traversal elements
*/
void printTraversal(std::vector<int> vec); 

void insert(BST& tree, int key) {
   tree.insert(key); 
   std::cout << "inserted " << key << "." << std::endl; 
}

void search(BST& tree, int key) { 
   auto status = tree.search(key); 
   if (status == BST::Status::FOUND) {
      std::cout << key << " found." << std::endl; 
      return;
   }
   std::cout << key << " not found." << std::endl; 
}

void min(BST& tree) {
   auto result = tree.min();
   if (result.first == BST::Status::FOUND) {
      std::cout << "min is " << result.second << "." << std::endl;  
      return;
   }
   std::cout << "tree empty." << std::endl; 
}

void max(BST& tree) { 
   auto result = tree.max();
   if (result.first == BST::Status::FOUND) {
      std::cout << "max is " << result.second << "." << std::endl; 
      return;
   }
   std::cout << "tree empty." << std::endl; 
}

void successor(BST& tree, int key) { 
   auto result = tree.successor(key);
   if (result.first == BST::Status::FOUND) {
      std::cout << key << " successor is " << result.second << "."
      << std::endl; 
   }
   else if (result.first == BST::Status::DNE) {
      std::cout << "no successor for " << key << "." << std::endl; 
   }
   else {
      std::cout << key << " not in tree." << std::endl; 
   }
}

void predecessor(BST& tree, int key) { 
   auto result = tree.predecessor(key);
   if (result.first == BST::Status::FOUND) {
      std::cout << key << " predecessor is " << result.second << "."
      << std::endl;  
   }
   else if (result.first == BST::Status::DNE) {
      std::cout << "no predecessor for " << key << "." << std::endl; 
   }
   else {
      std::cout << key << " not in tree." << std::endl; 
   }
}

void preorder(BST& tree) { 
   std::cout << "preorder traversal:";
   printTraversal(tree.preOrderTraverse()); 
}

void postorder(BST& tree) {
   std::cout << "postorder traversal:";
   printTraversal(tree.postOrderTraverse()); 
}

void inorder(BST& tree) {
   std::cout << "inorder traversal:";
   printTraversal(tree.inOrderTraverse()); 
}

void printTraversal(std::vector<int> vec) { 
   std::cout << std::endl; 
   for (size_t i = 0; i < vec.size(); i++) {
      if (i != 0) {
         std::cout << " " << vec[i];
      }
      else {
         std::cout << vec[i];
      }
   }
   std::cout << std::endl; 
}

void remove(BST& tree, int key) {
   auto status = tree.remove(key);
   if (status == BST::Status::FOUND) {
      std::cout << "deleted " << key << "." << std::endl; 
      return;
   }
   std::cout << "delete " << key << " - not found." << std::endl; 
}

Command processTrace(std::string trace) { 
   // Remove after comment if there is one
   size_t commentIndex = trace.find("#"); 
   if (commentIndex != std::string::npos) {
      trace.erase(commentIndex); 
   }

   // Parses command type and argument
   std::stringstream ss(trace);
   std::string commandType;
   int argument;
   ss >> commandType;
   ss >> argument; 

   return {commandType, argument}; 
}

int main() {
   BST tree; 
   std::string trace;  
   while (std::getline(std::cin, trace)) {
      Command command = processTrace(trace); 
      auto commandType = command.first; 
      auto commandArgument = command.second; 
      if (commandType == "search") {
         search(tree, commandArgument); 
      }
      else if (commandType == "insert") {
         insert(tree, commandArgument); 
      }
      else if (commandType == "delete") {
         remove(tree, commandArgument); 
      }
      else if (commandType == "min") {
         min(tree); 
      }
      else if (commandType == "max") {
         max(tree);
      }
      else if (commandType == "predecessor") {
         predecessor(tree, commandArgument);
      }
      else if (commandType == "successor") {
         successor(tree, commandArgument);
      }
      else if (commandType == "inorder") {
         inorder(tree); 
      }
      else if (commandType == "postorder") {
         postorder(tree);
      }
      else if (commandType == "preorder") {
         preorder(tree);
      }
   }
} // End of main
