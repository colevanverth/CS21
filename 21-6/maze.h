/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file maze.h
* @assignment 6: Maze Generation and Disjoint Sets
*/

#pragma once

#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <random>
#include <ostream> 

#include "disjoint_set.h"

/**
* `Maze` generates an n*n maze on instantiation by randomly selecting squares in
* the Maze and knocking down walls with adjacent squares when there is not a
* path between them already. 
*/
class Maze {
public:
   /**
   * `Maze` constructor. Generates the maze.
   * @param `edge` height and width of the maze
   */
   Maze(const int edge);

   /**
   * `Maze` destructor. 
   */
   ~Maze(); 

   /**
   * Outputs the contents of the `Maze`.
   * @return ostream reference containing maze entries; rows are seperated by
   * whitespace
   */
   friend std::ostream& operator<<(std::ostream& os, Maze& maze); 

private:
   
   /**
   * Iterates through `m_squares` using indices from `m_scrambles` to find a
   * random square, then calls `processCandidates` to attempt a wall removal if
   * applicable. Repeats this iteration until there is only one set remaining in
   * `m_set` (trivial with this particular maze generation algorithim but a
   * safeguard nonetheless). 
   *
   */
   void removeWalls(); 

   /**
   * Scrambles `m_scrambles` vector containing indices of all squares,
   * allowing random connection of squares to be efficient.
   */
   void scramble();

   /**
   * Removes a wall in between a square and a randomly picked adjacent square if
   * it is in bounds and both squares are not in the same set. 
   * @param `index` index of `square` in `m_squares` 
   */
   void processCandidates(uint index); 

   /**
   * Propogates `m_squares` vector with surrounding walls and makes the
   * entrance/exit.
   */
   void initalizeWalls(); 

   /**
   * Creates a random seed using system time for shuffling vectors and stores it
   * in `m_seed`.
   */
   void generateSeed(); 

   /**
   * Finds the index of the square to the right of a square.  
   * @param `index` index of square
   * @return index of square to the right of `index` 
   */
   int toRight(int index) { return index + 1; } 

   /**
   * Finds the index of the square to the left of a square. 
   * @param `index` index of square
   * @return index of square to the left of `index` 
   */
   int toLeft(int index) { return index - 1; } 
   
   /**
   * Finds the index of the square above a square. 
   * @param `index` index of square
   * @return index of square above `index` 
   */
   int toUp(int index) { return index - m_sideLength; } 

   /**
   * Finds the index of the square below a square. 
   * @param `index` index of square
   * @return index of square below `index` 
   */
   int toDown(int index) { return index + m_sideLength; }

   /**
   * Removes the left wall of a square. 
   * @param `index` index of square
   */
   void breakLeft(uint index) { m_squares[index] &= 0xb; } 

   /**
   * Removes the right wall of a square. 
   * @param `index` index of square
   */
   void breakRight(uint index) { m_squares[index] &= 0xe; }

   /**
   * Removes the wall above a square. 
   * @param `index` index of square
   */
   void breakUp(uint index) { m_squares[index] &= 0x7; }

   /**
   * Removes the wall below a square. 
   * @param `index` index of square 
   */
   void breakDown(uint index) { m_squares[index] &= 0xd; } 

   /**
   * Checks if a square exists to the right of a square.
   * @param `index` index of square
   * @return true if square exists to right of `index`, else false 
   */
   bool existsRight(int index) { return (index + 1) % m_sideLength; }

   /**
   * Checks if a square exists to the left of a square. 
   * @param `index` index of square
   * @return true if square exists to the left of `index`, else false 
   */
   bool existsLeft(int index) { return index % m_sideLength; }

   /**
   * Checks if a square exists above a square. 
   * @param `index` index of square
   * @return true if square exists above `index`, else false
   */
   bool existsUp(int index) { return !(index - m_sideLength < 0); }

   /**
   * Checks if a square exists below a square. 
   * @param `index` index of square
   * @return true if squares exists below `index`, else false 
   */
   bool existsDown(int index) { return !(index + m_sideLength >= m_area); } 

   int m_area; // Area of the maze

   int m_sideLength; // Side length of the maze

   DisjointSet* m_set; // Disjoint set containing the indices of squares
   
   std::vector<uint8_t> m_squares; // Array of wall info for the squares

   std::vector<uint> m_scrambles; // Scrambled indices of squares

   // Seed for shuffling vectors randomly
   std::default_random_engine m_seed = std::default_random_engine {};
   
   // Adjacent deletion candidates 
   enum m_candidate : uint8_t {m_up = 0, m_left, m_right, m_down};

   // Vector of adjacent deletion candidates
   std::vector<m_candidate> m_candidates {m_up, m_left, m_right, m_down}; 

   const uint8_t m_block = 0xf; // Walls on every edge
                                    
   const uint8_t m_entrance = 0xb; // No wall on left

   const uint8_t m_exit = 0xe; // No wall on right
};
