/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file intminheap.cpp
* @assignment 2: Integer Minimum Heap and Priority Queue
*/

#include "intminheap.h"

intMinHeap::intMinHeap(int capacity)
   : capacity(capacity)
   {
      A = new int[capacity];
      size = 0; 
   }

intMinHeap::~intMinHeap() {
   delete[] A;
}

std::pair<int *, int> intMinHeap::heapSort() {
   if (size <= 0) {
      std::cerr << "Out of Range error: Cannot heapSort in heap of size "
      << size << std::endl;
   }
   // Archives `A` and size of `A`
   int storedSize = size; 
   int* storedArray = A; 
   
   // Importantly, ensures size of returned array is not `capacity`
   A = new int[size]; 
   
   // Copies elements in the new array
   for (int i = 0; i < size; ++i) {
      A[i] = storedArray[i];
   }

   // Heapsort algorithim
   for (int i = size - 1; i > 0; i--) {
      swap(0, i);
      size--;
      heapify(0);
   }

   // Preps sorted array for return and restores `A`
   int* sortedArray = A;
   A = storedArray; 
   size = storedSize; 

   return std::pair<int*,int>(sortedArray, size);
}

std::string intMinHeap::toString() {
   std::string output;
   output = std::to_string(size) + ":";
   
   if (size > 0) {
      output += " "; 
      output += std::to_string(A[0]); 
   }
   for (int i = 1; i < size; ++i) {
      output += ", "; 
      output += std::to_string(A[i]);
   }
   return output;
}

bool intMinHeap::heapInsert(int k) {
   if (size >= capacity) {
      std::cerr << "Out of Range error: Cannot insert element in heap of size "
      << size << " at a capacity of " << capacity << std::endl;
      return false; 
   }
   size++;
   A[size - 1] = k + 1;
   decreaseKey(size - 1, k);
   return true;
} 

int intMinHeap::minimum() {
   if (size <= 0) {
      std::cerr << "Out of Range error: Cannot accsess min at heap size of: " 
      << size << std::endl;
      return 0;
   }
   return A[0];
}

int intMinHeap::extractMin() {
   if (size <= 0) {
      std::cerr << "Out of Range error: Cannot extract min at heap size of: " 
      << size << std::endl;
      return 0;
   }
   int min = minimum();
   A[0] = A[size - 1]; // Since size decreases, element pulled from bottom
   size--;
   heapify(0); // Readjusts new value at A[0] so min-heap property satisfied
   return min;
} 

void intMinHeap::decreaseKey(int i, int k) {
   if (i >= size || i < 0) {
      std::cerr << "Out of Range error: Cannot decrease index "
      << i << " in heap size of " << size << std::endl;
      return;
   }   
   if (A[i] <= k) {
      return; // Avoids decrease if `k` is larger rather than smaller
   }
   
   A[i] = k;

   // Pushes element upwards until its parent is less than it 
   // or the root of the min-heap is reached
   while (i > 0 && A[parent(i)] > A[i]) {
      swap(i, parent(i));
      i = parent(i);
   }
}

bool intMinHeap::isFull() {
   if (size >= capacity) {
      return true;
   }
   return false; 
}

void intMinHeap::swap(int i, int j) { 
   int temp = A[j];
   A[j] = A[i];
   A[i] = temp;
}

int intMinHeap::left(int i) {
   return ( ( i * 2 ) + 1 ); 
}

int intMinHeap::right(int i) {
   return ( ( i * 2) + 2 ); 
}

int intMinHeap::parent(int i) {
   return ( ( i - 1) / 2 ); 
}	

int intMinHeap::indexOfMin(int i, int j, int k) { 
   int smallest = i;
   if (j < size) {
      if (A[j] < A[i]) {
         smallest = j; 
      }
   }
   if (k < size) {
      if (A[k] < A[smallest]) {
         smallest = k;
      } 
   }
   return smallest; 
}

void intMinHeap::buildHeap() {
   for (int i = ( size / 2 ) - 1; i >= 0; i--) {
      heapify(i);   
   } 
}

void intMinHeap::heapify(int i) {
   int min = indexOfMin(i, left(i), right(i));
   if (i != min) {
      swap(min, i);
      heapify(min);
   }
}
