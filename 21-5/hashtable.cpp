/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file hashtable.cpp
* @assignment 5: Hash Table
*/

#include "hashtable.h"

HashTable::HashTable(int size)
   : m_size(size) {
      m_table = new std::vector<Record>[m_size];       
}
                    
HashTable::~HashTable() {
   delete[] m_table;
}

void HashTable::insert(Record record) {
   auto& list = m_table[hash(record)];
   list.push_back(record);
}
                         
void HashTable::clear() { 
   for (int i = 0; i < m_size; ++i) {
      m_table[i].clear(); 
   }
}

void HashTable::write(std::string filename) { 
   // Opens file for write
   std::ofstream fout;
   fout.open(filename);
   if (fout.fail()) {
      std::cerr << "Failed to open " << filename << " for write" << std::endl; 
   }

   // Places data into file
   for (int i = 0; i < m_size; ++i) {
      for (auto record : m_table[i]) {
         fout << std::setfill('0') << std::setw(9) <<
         record.id << " " << record.data << std::endl;    
      }
   }

   fout.close(); // Closes file 
}

void HashTable::merge(std::string filename) {
   std::string input; // Temp input to hold record data when loading records

   // Opens file for read
   std::ifstream fin;
   fin.open(filename);
   if (fin.fail()) {
      std::cerr << "Failed to open " << filename << " for merge" << std::endl;
   }

   // Load data from file
   while (std::getline(fin, input)) {
      int spaceIndex = input.find(' '); // Occurs directly after id
      Record record;  
      record.id = std::stoi(input.substr(0, spaceIndex));
      record.data = input.substr(spaceIndex + 1);
      insert(record);
   }

   fin.close(); // Closes file
}

Record* HashTable::remove(int id) {
   auto& chain = m_table[hash(id)]; // Vector associated with `id`
   auto recordIterator = find(id);
   if (recordIterator != chain.end()) {
      auto recordCopy = new Record(*recordIterator);
      chain.erase(recordIterator);
      return recordCopy;
   }
   return nullptr;
} 
                    
Record* HashTable::search(int id) {
   auto& chain = m_table[hash(id)]; // Vector associated with `id`
   auto recordIterator = find(id);
   if (recordIterator != chain.end()) {
      return new Record(*recordIterator);
   }
   return nullptr;
}

int HashTable::hash(Record record) {
   return hash(record.id);
}

int HashTable::hash(int key) {
   double base = (double)(m_hashConstant * key); // = xxxxx.yyyyy 
   int integer = (int)(base); // xxxxx.00000
   double preHash = (double)(base - integer); // 00000.yyyyy
   return (int)(preHash * m_size); // Returns an index within m_size
}

std::vector<Record>::iterator HashTable::find(int id) { 
   auto& chain = m_table[hash(id)];
   for (auto it = chain.begin(); it != chain.end(); it++) {
      if (it->id == id) {
         return it;
      }
   }
   return chain.end();
}
