/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file record.h
* @assignment 5: Hash Table
*/

#pragma once

#include <string>

/**
* @brief `Record` objects are data containers that store an int id and string
* data. `Record` objects are the unit of storage for `HashTable` objects. 
*/
struct Record {
   /**
   * `Record` default constructor.
   */
   Record();

   /**
   * `Record` constructor with parameters.
   * @param `id` id of the record
   * @param `data` data stored in the record
   */
   Record(int id, std::string data);

   /**
   * `Record` copy constructor.
   * @param `other` reference of Record to copy
   */
   Record(const Record& other);

   int id; // Record key

   std::string data; // Record data
};
