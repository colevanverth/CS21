/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 1: Review; Linked Lists
*/

#include <string>
#include <iostream>
#include "list.h"

int main() {
   List list1;
   List list2;
   for (int i = 0; i < 5; ++i) {
      list1.insertEnd(std::to_string(i));   
   }
   list1.reverse();
   for (auto it = list1.m_head; it != nullptr ; it = it->right ) {
      std::cout << it->data << std::endl;  
   }
}
