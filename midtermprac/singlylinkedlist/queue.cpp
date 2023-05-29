#include "queue.h"
/* bool SinglyLinked::isEmpty() { */ 
/*    return !(size); */ 
/* } */

Queue::Queue() {}
void Queue::enqueue(int val) {
   list.insertStart(val);   
}

int Queue::dequeue() {
   int val = list.get(list.size - 1);   
   list.removeEnd();
   return val;
}

bool Queue::isEmpty() {
   return !(list.size);
}
