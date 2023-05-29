/**
* This program implements a hash table using chaining and utilizes a
* multiplication method for generating hash keys. Main provides I/O that allows
* the user to interact with the hash table class. 
*
* The program works to all specifications and compiles with no warnings on
* Pengo. All methods were tested by hand. No memory leaks were found and I/O was
* tested with redirection to ensure it would work for the grading scripts. 
*/
/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 5: Hash Table
*/

#include <iostream>
#include <string>

#include "record.h"
#include "hashtable.h"

int main() {
   std::string input;
   HashTable table(178000);
   bool running = true;

   while (running) {
      // Print menu to user
      std::cout << "(1)load (2)insert (3)delete (4)search (5)clear" 
      << " (6)save (7)quit -- Your choice? "; 

      // Load user input
      std::getline(std::cin, input); 

      switch(std::stoi(input)) {
         // Table merge
         case 1: {
            std::cout << "read hash table - filename? "; 
            std::getline(std::cin, input); 
            table.merge(input);
            break; 
         }
                 
         // Record insert
         case 2: {
            std::cout << "input new record: ";
            std::getline(std::cin, input);
            int spaceIndex = input.find(' '); // Occurs directly after id
            Record record; 
            record.id = std::stoi(input.substr(0, spaceIndex));
            record.data = input.substr(spaceIndex + 1);
            table.insert(record);
            break;
         }

         // Record delete
         case 3: {
            std::cout << "delete record - key? ";
            std::getline(std::cin, input);
            auto recordCopy = table.remove(std::stoi(input));
            if (recordCopy) {
               std::cout << "Delete: " << recordCopy->id << " " << recordCopy->data << std::endl; 
               delete recordCopy;
            }
            else {
               std::cout << "Delete not found: " << input << std::endl; 
            }
            break;
         }

         // Record search 
         case 4: {
            std::cout << "search for record - key? ";
            std::getline(std::cin, input);
            Record* recordCopy = table.search(std::stoi(input));
            if (recordCopy) {
               std::cout << "Found: " << recordCopy->id << " " << recordCopy->data << std::endl;  
               delete recordCopy;
            }
            else {
               std::cout << "Search not found: " << input << std::endl; 
            }
            break;
         }

         // Table clear
         case 5: {
            table.clear();
            std::cout << "clearing hash table." << std::endl; 
            break;
         }

         // Table write
         case 6: { 
            std::cout << "write hash table - filename? "; 
            std::getline(std::cin, input);
            table.write(input);
            break;
         }
         
         // End program
         case 7: {
            running = false; 
            break;
         }
      }
   }
}
