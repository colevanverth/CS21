#include "all.h"
 
All::All(int capacity)
: m_capacity(capacity) {
   lefts = new int[capacity];
   rights = new int[capacity];
   datas = new int[capacity];
   for (int i = 0; i < m_capacity; ++i) {
      lefts[i] = -1;
      rights[i] = -1;
   }
}

int All::findEmpty() {
   for (int i = 0; i < m_capacity; ++i) {
      if (rights[i] == -1 && lefts[i] == -1 && i != m_head) {
         return i;
      }
   }
   return -1;
}

void All::insertEnd(int val) { 
   int emptyIndex = findEmpty(); 
   if (emptyIndex == -1) {
      return; 
   }
   datas[emptyIndex] = val;
   if (m_size == 0) {
      m_head = emptyIndex;
      m_tail = emptyIndex;
   }
   else {
      rights[m_tail] = emptyIndex;
      lefts[emptyIndex] = m_tail;
      m_tail = emptyIndex;
   }
   m_size++;
}

void All::removeEnd() {
   if (m_size <= 0) {
      return;
   }
   if (m_size == 1) {
      reset(m_tail);
      m_tail = -1;
      m_head = -1;
   }
   else {
      int indexLeftOfTail = lefts[m_tail];
      rights[indexLeftOfTail] = -1;
      reset(m_tail);
      m_tail = indexLeftOfTail;
   }
   m_size--;
}

void All::reset(int index) {
   lefts[index] = -1;
   rights[index] -1;
}

void All::print() {
   int adjustNode = m_head;
   while (adjustNode != -1) {
      std::cout << datas[adjustNode] << std::endl; 
      adjustNode = rights[adjustNode];
   }
}

