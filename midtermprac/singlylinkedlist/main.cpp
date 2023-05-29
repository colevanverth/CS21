#include <iostream>
#include "queue.h"

int main() {
   /* SinglyLinked list; */
   /* list.insertEnd(5); */
   /* list.insertEnd(5); */
   /* list.insertEnd(7); */
   /* list.insertEnd(99); */
   /* list.insert(0, 555); */
   /* list.removeEnd(); */
   /* list.removeStart(); */
   /* list.remove(1); */
  
   /* auto adjust = list.head; */ 
   /* while (adjust != nullptr) { */
   /*    std::cout << adjust->data << std::endl; */ 
   /*    adjust = adjust->right; */
   /* } */

   Queue queue;
   queue.enqueue(123);
   queue.enqueue(456);
   std::cout << queue.dequeue() << std::endl; 



}
