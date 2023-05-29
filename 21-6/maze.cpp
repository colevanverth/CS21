/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file maze.cpp
* @assignment 6: Maze Generation and Disjoint Sets
*/

#include "maze.h"

Maze::Maze(const int edge) {
   if (edge < 3) {
      throw std::invalid_argument("Maze cannot have side length less than 3"); 
   }

   m_area = edge * edge; 
   m_sideLength = edge; 
   m_set = new DisjointSet(m_area); 

   generateSeed(); 
   scramble();
   initalizeWalls();
   removeWalls();
}

Maze::~Maze() { 
   delete m_set; 
}

void Maze::removeWalls() {
   while (m_set->getSize() > 1) {
      for (size_t i = 0; i < m_area; i++) {
         processCandidates(m_scrambles[i]); 
      }
   }
}

void Maze::scramble() {
   // Fills vector with indices
   for (size_t i = 0; i < m_area; i++) {
      m_scrambles.push_back(i); 
   }

   // Shuffles `m_scrambles` 
   std::shuffle(m_scrambles.begin(), m_scrambles.end(), m_seed);
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
   int totalIndex = 0; 
   for (size_t i = 0; i < maze.m_sideLength; i++) {
      for (size_t j = 0; j < maze.m_sideLength; j++) {
         os << std::hex << (int)maze.m_squares[totalIndex];
         totalIndex++;
      }
      os << std::endl;
   }
   return os; 

} 

void Maze::processCandidates(uint index) {
   std::shuffle(m_candidates.begin(), m_candidates.end(), m_seed);
   for (size_t i = 0; i < m_candidates.size(); i++) {
      switch(m_candidates[i]) { 
         case m_left: {
            int indexOfLeft = toLeft(index); 
            if (existsLeft(index) && !m_set->isSameSet(index, indexOfLeft)) {
               breakLeft(index); 
               breakRight(indexOfLeft); 
               m_set->merge(index, indexOfLeft); 
            }
            break; 
         }
         case m_right: {
            int indexOfRight = toRight(index); 
            if (existsRight(index) && !m_set->isSameSet(index, indexOfRight)) {
               breakRight(index); 
               breakLeft(indexOfRight); 
               m_set->merge(index, indexOfRight); 
            }
            break;
         }
         case m_down: { 
            int indexOfDown = toDown(index); 
            if (existsDown(index) && !m_set->isSameSet(index, indexOfDown)) {
               breakDown(index); 
               breakUp(indexOfDown); 
               m_set->merge(index, indexOfDown); 
            }
            break;
         }
         case m_up: {
            int indexOfUp = toUp(index); 
            if (existsUp(index) && !m_set->isSameSet(index, indexOfUp)) {
               breakUp(index); 
               breakDown(indexOfUp); 
               m_set->merge(index, indexOfUp); 
            }
            break;
         }
      }
   }
} 

void Maze::generateSeed() { 
   // std::duration::chrono object from current sys time to sys epoch
   auto epochDuration = std::chrono::system_clock::now().time_since_epoch();

   // Number of ticks in this duration
   auto seed = epochDuration.count(); 

   // Meets "UniformRandomBitGenerator" requirements for std::shuffle
   m_seed.seed(seed);
}

void Maze::initalizeWalls() {
   m_squares.push_back(m_entrance);
   for (size_t i = 0; i < m_area - 2; i++) {
      m_squares.push_back(m_block);
   }
   m_squares.push_back(m_exit); 
} 
