#include "singlylinked.h"

class Queue {
public:

   Queue();
   void enqueue(int val);
   int dequeue();
   bool isEmpty();

private:
   SinglyLinked list;   
};
