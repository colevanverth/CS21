#include <iostream>

#include "all.h"

int main() {
   All all(100);
   all.insertEnd(5);
   all.removeEnd();
   all.insertEnd(100);
   all.insertEnd(100);
   all.insertEnd(100);

   all.print();

}
