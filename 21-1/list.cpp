/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file list.cpp
* @assignment 1: Review; Linked Lists
*/

#include "list.h"

List::List() {}

List::~List() {
    auto deleteListNode = m_head;
    while (m_size > 0) {
        auto nextListNode = deleteListNode->right;
        delete deleteListNode;
        m_size--;
        deleteListNode = nextListNode;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

void List::insertEnd(std::string input) {
    auto newListNode = new ListNode;
    newListNode->data = input;
    if (m_size > 0) {
       auto prevListNode = m_tail;
       prevListNode->right = newListNode;
       newListNode->left = prevListNode;
       m_tail = newListNode;
    }
    else { 
        m_tail = newListNode; 
        m_head = newListNode; 
    }
    m_size++;
}

void List::insertStart(std::string input) {
    auto newListNode = new ListNode;
    newListNode->data = input;
    if (m_size > 0) { 
        auto prevListNode = m_head; 
        prevListNode->left = newListNode;
        newListNode->right = prevListNode;
        m_head = newListNode;
    }
    else { 
        m_tail = newListNode;
        m_head = newListNode;
    }
    m_size++;
}

void List::removeStart() {
    if (m_size >= 1){
        if (m_size == 1) {
            auto deleteListNode = m_head;
            delete deleteListNode;
            m_tail = nullptr;
            m_head = nullptr;
        }
        else { 
            auto deleteListNode = m_tail;
            auto adjustListNode = deleteListNode->right;
            adjustListNode->left = nullptr;
            delete deleteListNode;
            m_head = adjustListNode; 
        }
        m_size--;
    }
}

void List::removeEnd() {
    if (m_size >= 1) {
        if (m_size == 1) {
            auto deleteListNode = m_tail;
            delete deleteListNode;
            m_tail = nullptr;
            m_head = nullptr;
        }
        else { 
            auto deleteListNode = m_tail;
            auto adjustListNode = deleteListNode->left;
            delete deleteListNode;
            adjustListNode->right = nullptr;
            m_tail = adjustListNode; 
        }
        m_size--;
    }
}

std::string List::getData(ListNode* node) {
    if (node != nullptr) {
        return node->data;
    }
    else {
        return "";
    }
}

size_t List::getSize() { 
    return m_size; 
}

List::ListNode* List::getTail() { 
    return m_tail;
}

List::ListNode::ListNode() {}
