#include "singlylinked.h"

SinglyLinked::SinglyLinked() {} 

int SinglyLinked::get(int index) {
   if (index < 0 || index >= size) {
      return -1; // Index is not valid
   } 
   int curIndex = 0; 
   auto adjustNode = head; 
   while (adjustNode != nullptr) {
      if (curIndex == index) {
         return adjustNode->data;
      }
      curIndex++;
      adjustNode = adjustNode->right;
   }
}

void SinglyLinked::insertStart(int data) {
   auto newHead = new Node; 
   newHead->data = data;   
   if (size == 0) {
      tail = newHead;
      head = newHead;
   }
   else {
      newHead->right = head;
      head = newHead;
   }
   size++;
}

void SinglyLinked::insertEnd(int data) {
   auto newTail = new Node;
   newTail->data = data;
   if (size == 0) {
      tail = newTail;
      head = newTail; 
   }
   else {
      tail->right = newTail;
      tail = newTail;
  }
  size++;
}

void SinglyLinked::removeEnd() {
   if (size > 0) {
      if (size == 1) {
         delete tail; 
         head = nullptr;
         tail = nullptr;
      }
      else {
         auto adjustNode = head; 
         while (adjustNode != nullptr) {
            if (adjustNode->right == tail) {
               delete tail;
               tail = adjustNode;
               adjustNode->right = nullptr;
            }
            adjustNode = adjustNode->right;
         }
      }
      size--;
   }
} 

void SinglyLinked::removeStart() {
   if (size > 0) {
      if (size == 1) {
         delete head;
         head = nullptr;
         tail = nullptr;
      }
      else {
         auto alterNode = head->right;
         delete head; 
         head = alterNode;
      }
      size--;
   }
}

void SinglyLinked::remove(int index) {
   if (index < 0 || index >= size) {
      return;
   }
   if (index == 0) {
      removeStart();
   }
   else if (index == size - 1) {
      removeEnd();
   }
   else {
      auto adjustNode = head;
      auto curIndex = 0; 
      while (adjustNode != nullptr) {
         if (curIndex == index - 1) {
            auto deleteNode = adjustNode->right;
            adjustNode->right = adjustNode->right->right;
            delete deleteNode;
            size--;
            return;
         }
         curIndex++;
         adjustNode = adjustNode->right;
      }
   }
} 

void SinglyLinked::insert(int index, int data) { 
   if (index < 0 || index > size) {
      return;
   }
   if (index == 0) {
      insertStart(data);
   }
   else if (index == size) {
      insertEnd(data);
   }
   else {
      auto middleNode = new Node; 
      middleNode->data = data; 

      auto adjustNode = head; 
      int curIndex = 0; 
      while (adjustNode != nullptr) {
         if (curIndex == index) {
            middleNode->right = adjustNode->right;
            adjustNode->right = middleNode;
            size++;
            return;
         }
         curIndex++;
         adjustNode = adjustNode->right; 
      }
   }
}

