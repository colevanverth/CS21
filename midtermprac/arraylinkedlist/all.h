#pragma once

#include <iostream>

class All {
public:

   All(int capacity);
   int findEmpty();
   void insertEnd(int val);
   void removeEnd();
   void reset(int index);
   void print();

private:
   int m_capacity;
   int m_size = 0;
   int m_head = -1;
   int m_tail = -1; 
   int* lefts;
   int* rights;
   int* datas;

}; 
