/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file intminheap.cpp
* @assignment 2: Integer Minimum Heap and Priority Queue
*/

/**
* This program implements a min-heap. Extraction and insertion methods are
* provided, allowing the min-heap to be used as a priority queue. Values are
* read and placed into the min-heap from standard input. Some input
* combinations perform special operations (e.g. print min-heap values to
* standard out).
*
* The program compiles with no warnings with the "-Wall" flag. No memory leaks
* were found using Valgrind. Valid input, in addition to negative numbers,
* were tested and appear to generate correct output for all functions. The 
* edge case that occurs when the size of the array is zero was checked: all 
* potential access violations were prevented with bounds checks in the public
* member functions of `IntMinHeap`.
*/

#include <utility>
#include <iostream>

#include "intminheap.h"

int main() { 
   auto heap = intMinHeap(2400000);   
   std::string buffer;

   while(std::cin >> buffer) { 
      auto numInput = std::stoi(buffer);
      if (numInput == 0) {
         std::cout << "heap size " << heap.toString() << std::endl;
      }
      else if (numInput == -1) {
         auto extraction = heap.extractMin();
         if (extraction != 0) {
            std::cout << "extract min: " << extraction << std::endl;
         }
      }
      else if (numInput == -2) {
         auto sortedArrayPair = heap.heapSort(); 
         auto sortedArray = sortedArrayPair.first; 
         auto sortedArraySize = sortedArrayPair.second;

         std::cout << "sorted array: [";
         if (sortedArraySize > 0) {
            std::cout << sortedArray[0];
            for (int i = 1; i < sortedArraySize; ++i) {
               std::cout << ", " << sortedArray[i]; 
            }
         }
         std::cout << "]" << std::endl;
         delete[] sortedArray;
      }
      else if (numInput > 0) {
         if (heap.heapInsert(numInput)) {
            std::cout << "insert: " << numInput << std::endl;
         }
      }
   }
}
