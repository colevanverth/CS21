/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file stack.h
* @assignment 1: Review; Linked Lists
*/

#include "list.h"

/*
 * @brief `Stack` provides methods for interacting with a container with a stack
 * convention. Although this abstraction is hidden from a `Stack` user, its 
 * container is actually built on a `List` object, a doubly linked list. 
*/

class Stack {
public:
    // `Stack` default constructor
    Stack();

    // Places a string at the end of the `Stack` container
    void push(std::string input);

    // Removes and returns string from end of the `Stack` container
    std::string pop();

    // Returns true if the `Stack` is empty
    bool isEmpty();
private:
    List m_list;
};
