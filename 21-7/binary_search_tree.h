/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file binary_search_tree.h
* @assignment 7: Binary Search Tree
*/

#pragma once

#include <utility>
#include <vector>

class BinarySearchTree {

   struct Node; // Forward declaration
                
public:

   /**
   * `Status` enumerators are returned by public methods and convey information
   * about the result of an operation. 
   */
   enum Status {
      DNE = 0, // The result does not exist
      FOUND, // The result exists 
      INVALID_ARGUMENT // Operation to calculate result could not execute
   };

   /**
   * `Result` objects are returned by public methods and contain an integer
   * output whose validity depends on its associated `Result`.
   */
   typedef std::pair<Status, int> Result; 

   /**
   * `BinarySearchTree` default constructor.
   */
   BinarySearchTree();

   /**
   * `BinarySearchTree` destructor.
   */
   ~BinarySearchTree(); 
  
   /**
   * Finds the smallest key in the tree. 
   * @return `Result` containing min key in tree and found status, else DNE
   * `Result` if tree is empty
   */
   Result min(); 

   /**
   * Finds the largest key in the tree.
   * @return `Result` containing max key in tree and found status, else DNE
   * `Result` if tree is empty
   */
   Result max(); 

   /**
   * Finds the successor.
   * @param `key` key to find successor of
   * @return `Result` indicating if `key` did not exist, if successor to `key`
   * did not exist, or if successor to `key` did exist with the successor key
   */
   Result successor(int key); 

   /**
   * Finds the predeccessor.
   * @param `key` key to find predecessor of
   * @return `Result` indicating if `key` did not exist, if predecessor to
   * `key` did not exist, or if predecessor to `key` did exist with the
   * predecessor key 
   */
   Result predecessor(int key); 

   /**
   * Searchs for a key.
   * @param `key` key to search for
   * @return `Status` object indicating if `key` was found 
   */
   Status search(int key); 

   /**
   * Removes a key from the tree.   
   * @param `key` key to remove  
   * @return `Status` objecting indicating if `key` did not exist or if it was
   * removed
   */
   Status remove(int key); 

   /**
   * Inserts a key into the tree.
   * @param `key` key to insert 
   */
   void insert(int key); 

   /**
   * Invokes an in order traversal from `m_root`.
   * @return `std::vector` containing the keys of the tree in order
   */
   std::vector<int> inOrderTraverse();

   /**
   * Invokes a pre order traversal from `m_root`.
   * @return `std::vector` containing the keys of the tree pre order
   */
   std::vector<int> preOrderTraverse();

   /**
   * Invokes a post order traversal from `m_root`.
   * @return `std::vector` containing the keys of the tree post order
   */
   std::vector<int> postOrderTraverse();

private:

   /**
   * Searchs for a `Node`.
   * @param `node` node of root of valid binary search tree
   * @param `key` key of node to find
   * @return `Node*` of node with `key` in `node`, else nullptr if it does not
   * exist
   */
   Node* m_search(Node* node, int key); 

   /**
   * Finds a `Node` with the smallest key. 
   * @param `node` node of root of valid binary search tree
   * @return `Node*` of node with smallest key in `node`
   */
   Node* m_min(Node* node); 

   /**
   * Finds a `Node` with the largest key.
   * @param `node` node of root of valid binary search tree
   * @return `Node*` of node with smallest key in `node`
   */
   Node* m_max(Node* node); 

   /**
   * Finds the successor of a `Node`. 
   * @param `node` node to find successor of
   * @return `Node*` successor to `node`
   */
   Node* m_successor(Node* node); 

   /**
   * Finds the predecessor of a `Node`.
   * @param `node` node to find predecessor of
   * @return `Node*` predecessor to `node`
   */
   Node* m_predecessor(Node* node);

   /**
   * Removes all `Node` objects including and under a provided `Node`; 
   * invoked by `Binary Search Tree` destructor.
   * @param `node` base node to destruct from
   */ 
   void m_destruct(Node* node);

   /**
   * Connects the parent of a `Node` to another `Node`.  
   * @param `remove` pointer to Node to connect its parent to `merge`   
   * @param `merge` pointer to Node to connect itself to the parent of
   * 'upper'
   */
   void m_transplant(Node* remove, Node* merge); 

   /**
   * Deletes a node.
   * @param `node` node to delete
   */
   void m_remove(Node* node); 

   /**
   * Traverses the tree in order, filling `m_traversalBuffer`.
   * @param `node` node to begin traversal at
   */
   void m_inOrderTraverse(Node* node);

   /**
   * Traverses the tree pre order, filling `m_traversalBuffer`.
   * @param `node` node to begin traversal at
   */
   void m_preOrderTraverse(Node* node);

   /**
   * Traverses the tree post order, filling `m_traversalBuffer`.
   * @param `node` node to begin traversal at 
   */
   void m_postOrderTraverse(Node* node); 

   std::vector<int> m_traversalBuffer; // Temp array storage for traversals
                                       
   Node* m_root = nullptr; // Root of `Binary Search Tree`

   /**
   * `Node` objects are units that compose a `Binary Search Tree`; they contain
   * keys and can connect to their parent and children `Node` objects. 
   */
   struct Node { 
      Node() = default; 
      Node(int key) : key(key) {}
      Node* left = nullptr; 
      Node* right = nullptr; 
      Node* parent = nullptr; 
      int key; 
   };
};
