#pragma once

#include <iostream>

class SinglyLinked {
   struct Node; 
public:
   
   SinglyLinked(); 
   
   int get(int index);

   void insertStart(int data);

   void insertEnd(int data);

   void removeStart(); 

   void removeEnd(); 

   void insert(int index, int data);

   void remove(int index); 

   Node* tail = nullptr;
   Node* head = nullptr; 
   int size = 0;

private:

   struct Node { 
      Node* right; 
      int data; 
   };
}; 
