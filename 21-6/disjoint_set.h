/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file disjoint_set.h
* @assignment 6: Maze Generation and Disjoint Sets
*/

#pragma once

#include <stdexcept>

/**
* `DisjointSet` implements a disjoint set with heuristics (path compression and
* union with a ranking system) to improve efficiency. Used in `Maze` in the maze
* generation algorithim to check if two squares have a path between them. 
*/
class DisjointSet {
public:
   /**
   * `DisjointSet` constructor.
   * @param `sets` number of sets to instantiate 
   */
   DisjointSet(int sets);

   /**
   * `DisjointSet` deconstructor. 
   */
   ~DisjointSet(); 
   
   /**
   * Merges two sets given elements in these sets by first searching for the
   * representative elements. 
   * @param `elemA` indice of element in first set
   * @param `elemB` indice of element in second set
   */
   void merge(int elemA, int elemB);

   /**
   * Checks if two elements are of the same set. 
   * @param `elemA` indice of first element
   * @param `elemB` indice of second element
   * @return true if `elemA` and `elemB` have the same represenative element
   * (are of the same set), else false
   */
   bool isSameSet(int elemA, int elemB); 

   /**
   * Finds the remaining number of sets. 
   * @return the number of sets
   */
   int getSize();  

   /**
   * Finds the representative element of the set containing an element. As it
   * searches for the representative element it self heals the data structure,
   * connecting elements directly to the representative element. 
   * @param `elem` element in set to find its representative element
   */
   int find(int elem);
   
private:
   /**
   * Unions two sets from two given representative elements and updates their
   * ranks accordingly. 
   * @param `repElemA` first representative element of set to link
   * @param `repElemB` second representative element of set to link
   */
   void link(int repElemA, int repElemB);

   int* m_rank; // Array of ranks (upper bounded height of a set) 
   int* m_parent; // Array of parent element for each element
   int m_elems; // Number of elements (initially the number of sets) 
   int m_sets; // The number of sets; decremented during a merge 
};
