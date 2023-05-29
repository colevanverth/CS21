/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file record.cpp
* @assignment 5: Hash Table
*/

#include "record.h"

Record::Record() {}

Record::Record(int id, std::string data)
   : id(id), data(data) {}

Record::Record(const Record& other) {
   id = other.id;
   data = other.data;
}
