/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file stack.cpp
* @assignment 1: Review; Linked Lists
*/

#include "stack.h"

Stack::Stack() {}

void Stack::push(std::string input) {
    m_list.insertEnd(input); 
}

std::string Stack::pop() {
   std::string tail = m_list.getData(m_list.getTail());
   m_list.removeEnd();
   return tail;
}

bool Stack::isEmpty() {
    if (m_list.getSize() == 0) {
        return true;
    }
    return false;
}
