/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file disjoint_set.cpp
* @assignment 6: Maze Generation and Disjoint Sets 
*/
#include "disjoint_set.h"

DisjointSet::DisjointSet(int sets)
   : m_elems(sets), m_sets(sets) {
   m_rank = new int[sets];
   m_parent = new int[sets];
   
   // Set default ranks and parents 
   for (unsigned int i = 0; i < sets; ++i) {
      m_rank[i] = 0;
      m_parent[i] = i; // Default parent of an element is itself
   }
}

DisjointSet::~DisjointSet() {
   delete[] m_parent; 
   delete[] m_rank; 
}

void DisjointSet::merge(int elemA, int elemB) {
   // Bounds check on element indices 
   if (elemA < 0 || elemB < 0 || elemA >= m_elems || elemB >= m_elems ) {
      throw std::out_of_range("Cannot merge sets"); 
   }
   // Link the two sets 
   link(find(elemA), find(elemB)); 
}

int DisjointSet::find(int elem) { 
   if (elem < 0 || elem >= m_elems) {
      throw std::out_of_range("Cannot find element");    
   }
   if (elem != m_parent[elem]) {
      m_parent[elem] = find(m_parent[elem]); 
   }
   return m_parent[elem];
}

void DisjointSet::link(int repElemA, int repElemB) { 
   if (repElemA == repElemB) {
      return;
   }
   m_sets--; 
   if (m_rank[repElemA] > m_rank[repElemB]) {
      m_parent[repElemB] = repElemA;
   }
   else {
      m_parent[repElemA] = repElemB;
      if (m_rank[repElemA] == m_rank[repElemB]) {
         m_rank[repElemB]++;
      }
   }
}

bool DisjointSet::isSameSet(int elemA, int elemB) { 
   return find(elemA) == find(elemB); 
}

int DisjointSet::getSize() { 
   return m_sets; 
}
