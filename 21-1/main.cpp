/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 1: Review; Linked Lists
*/

/*
* @description This program reads input strings and prints them to standard
* output with a stack data structure that is an extension of a custom
* implemented doubly linked list. 
* @status The program compiles. It has been tested using typed standard
* input and redirection with over 100,000 inputs (no memory leaks found).
*/

#include <iostream>
#include "stack.h"

int main() {
    Stack stack; 
    std::string buffer;
    while(std::getline(std::cin, buffer)) { 
        stack.push(buffer);
    }
    while (!stack.isEmpty()) { 
        auto msg = stack.pop();
        std::cout << msg << std::endl;
    }
}
