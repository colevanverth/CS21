/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file hashtable.h
* @assignment 5: Hash Table
*/

#pragma once

#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

#include "record.h"
 
/**
* @brief `HashTable` implements a hashtable that stores `Record` objects.
* Hashes are calculated using a multiplication method. Collisions are resolved
* with chaining; thus, `Record` retrieval has linear time complexity
* in the best case, and O(n) time complexity in the worst case. Essential
* methods for manipulating the hashtable are provided, including reading from
* and writing to a file.
*/
class HashTable {
public:
   /**
   * `HashTable` constructor.
   * @param `size` size of hash table (default 100)
   */
   HashTable(int size = 100);
   
   /**
   * `HashTable` deconstructor. Deletes heap allocated array `m_table` of
   * vectors.
   */
   ~HashTable();
                       
   /**
   * Inserts a record into the hashtable
   * @param `record` Record to be inserted into `m_table`
   */
   void insert(Record record); 
                         
   /**
   * Deletes a record from the hashtable.
   * @param `id` int id of record in `m_table` to delete
   * @return pointer to a heap allocated copy of a record that was deleted if
   * there was a record corresponding to `id`, else nullptr
   */
   Record* remove(int id); 
                    
   /*
   * Searchs for a record in the hashtable.
   * @param `id` id of record to search for in `m_table`
   * @return pointer to a heap allocated copy of a record if there was a record
   * corresponding to `id`, else nullptr
   */
   Record* search(int id); 

   /**
   * Clears all entries in all vectors within `m_table`.
   */
   void clear();

   /**
   * Merges a file containg hash entries into the hashtable
   * @param `filename` name of file to load entries from
   */
   void merge(std::string filename);

   /**
   * Writes the hashtable to a file.
   * @param `filename` name of the file to load entries into
   */
   void write(std::string filename);

private:
   /**
   * Helper function that finds the iterator associated with a record.
   * @param `id` id of record to find
   * @return iterator associated with record in vector "chain" 
   * if it was found, else chain.end()
   */
   std::vector<Record>::iterator find(int id); 

   /**
   * Finds the hash value for a record.
   * @param `record` pointer to record
   * @return hash corresponding to the `id` within the `record`
   */
   int hash(Record record);

   /**
   * Finds the hash value for a key using `m_hashConstant` with a
   * multiplication method.
   * @param `key` key to calculate hash from 
   * @return hash value calculated from `key`
   */
   int hash(int key);

   const int m_size; // Capacity of `m_table`
  
   std::vector<Record>* m_table; // Array of vector "chains" 

   const double m_hashConstant = 0.618034; // Hash constant (inverse of golden ratio)

};

