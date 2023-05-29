/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file intminheap.h
* @assignment 2: Integer Minimum Heap and Priority Queue
*/

#pragma once

#include <utility>
#include <string>
#include <iostream>

/*
* @brief `intMinHeap` is a minimum heap that has methods that allow it to be
* used as a priority queue.
*/
class intMinHeap{
public:

   /**
   * `intMinHeap` constructor.
   * @param `capacity` size of heap array `A`
   */
   intMinHeap(int capacity);

   /**
   * `intMinHeap` destructor. Frees `A` array.
   */
   ~intMinHeap();

   /**
   * Sorts the heap in `A` that satisfies the min-heap property.
   * @return std::pair with a pointer to sorted array and size of the sorted
   * array
   */
   std::pair<int *, int> heapSort();

   /**
   * Converts elements in heap to a string.
   * @return Comma and space separated list of elements in `A`.
   */
   std::string toString();  

   /**
   * Inserts a value into the heap.
   * @param `k` value of element to be be inserted into the heap.
   * @return True if insertion was successful (`capacity` not exceeded). 
   */
   bool heapInsert(int k);

   /**
   * Finds minimum value in heap.
   * @return `A[0]`, else 0 if `size` is zero
   */
   int minimum();  // return value of A[root]

   /**
   * Finds minimum value and removes it from heap.
   * @return `A[0]`, else 0 if `size` is zero
   */
   int extractMin(); // return and remove A[root]

   /**
   * Decreases an element in the heap.
   * @param `i` element index in heap
   * @param `k` value to decrease to, must be less than `A[i]`
   */
   void decreaseKey(int i, int k);

   /**
   * Checks if the heap is empty.
   * @return True if `size` is 0
   */
   bool isEmpty() {return size==0;}

   /**
   * Checks if the heap is full.  
   * @return True if `size` is equal to `capacity`
   */
   bool isFull();  

private: 

   /**
   * Swaps two elements in the heap.
   * @param `i` index of first element
   * @param `j` index of second element
   */
   void swap(int i, int j);

   /**
   * Calculates left child of an element.
   * @param `i` index of element
   * @return index of left child of `i`
   */
   int left(int i); 

   /**
   * Calculates the right child of an element.
   * @param `i` index of element
   * @return index of right child of `i`
   */
   int right(int i); 

   /**
   * Calculates parent of an element.
   * @param `i` index of child element
   * @return index of parent element of `i`
   */
   int parent(int i); 
                    
   /**
   * Converts an array in `A` to a heap. Currently it is impossible for
   * an array in `A` to not satisfy the min-heap property, but this method was
   * required for the assignment.
   */
   void buildHeap();

   /**
   * Maintains heap.
   * @param `i` index to begin heapify algorithim
   */
   void heapify(int i);

   /**
   * Finds the index of the minimum value
   * @param `i` valid index of element
   * @param `j` potentially valid index of element
   * @param `k` potentially valid index of element
   * @return Index of element with smallest value. Note that the bounds of `i`
   * and `j` do not BOTH need to be valid, only one. This ensures that `heapify`
   * can traverse down a "nearly complete" heap where there is only one element
   * on the final level.
   */
   int indexOfMin(int i, int j, int k);

   int *A; // Array of integers that stores the min-heap  

   int capacity; // Total space in `A`

   int size; // Occupied elements in `A` that satisfy the min-heap property
 };
