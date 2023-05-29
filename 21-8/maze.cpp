/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file maze.cpp
* @assignment 8: Breadth-First Search 
*/

#include "maze.h"

Maze::Maze(const std::vector<int>& walls)
   : m_walls(walls), m_numWalls(walls.size()), 
   m_sideLength(std::sqrt(walls.size())), m_exit(walls.size() - 1) {} 

void Maze::BreadthFirstSearch() {
   // Initialize vertex info
   m_candidate.assign(m_numWalls, true);
   m_parent.assign(m_numWalls, m_null);

   // Initalize maze exit and place into queue
   m_candidate[m_exit] = false; 
   m_activeCandidates.push(m_exit);

   // Breadth-First Search Algorithim
   while (!m_activeCandidates.empty()) {
      auto vertex = m_activeCandidates.front();
      m_activeCandidates.pop();
      findAdjacents(vertex);
      for (auto adjacent : m_adjacents) {
         if (m_candidate[adjacent]) {
            m_candidate[adjacent] = false; 
            m_parent[adjacent] = vertex; 
            m_activeCandidates.push(adjacent);
         }  
      }
   }
}

void Maze::findAdjacents(int vertex) { 
   m_adjacents.clear(); // Clears past adjacency candidates 
                        
   if (m_connectsLeft(vertex)) { // Path to left adjacent tile
      m_adjacents.push_back(m_toLeft(vertex)); 
   }
   if (m_connectsRight(vertex)) { // Path to right adjacent tile
      m_adjacents.push_back(m_toRight(vertex));
   }
   if (m_connectsUp(vertex)) { // Path to adjacent tile above
      m_adjacents.push_back(m_toUp(vertex));
   }
   if (m_connectsDown(vertex)) { // Path to adjacent tile below
      m_adjacents.push_back(m_toDown(vertex));
   }
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
   auto node = maze.m_entry; // Starting at entry of maze
   while (node != maze.m_null) {
      int y = node / maze.m_sideLength; 
      int x = node - (y * maze.m_sideLength);
      os << "(" << x << ", " << y << ")" << std::endl;
      node = maze.m_parent[node];
   }
   return os; 
}

bool Maze::m_connectsLeft(int vertex) {
   // Ensures adjacent tile is in bounds
   if (vertex % m_sideLength == 0) {
      return false;     
   }

   // Ensures tile has path left
   if ( ( m_walls[vertex] & m_leftWall ) == m_leftWall) {
      return false; 
   }

   return true; 
} 

bool Maze::m_connectsRight(int vertex) {
   // Ensures adjacent tile is in bounds 
   if ( (vertex + 1) % m_sideLength == 0) {
      return false; 
   }

   // Ensures tile has path right
   if ( ( m_walls[vertex] & m_rightWall ) == m_rightWall) {
      return false;  
   }

   return true; 
} 
bool Maze::m_connectsDown(int vertex) {
   // Ensures adjacent tile is in bounds 
   if (vertex + m_sideLength >= m_numWalls) { 
      return false; 
   } 

   // Ensures tile has path down
   if ( ( m_walls[vertex] & m_downWall ) == m_downWall) {
      return false;  
   }

   return true; 
}

bool Maze::m_connectsUp(int vertex) {
   // Ensures adjacent tile is in bounds
   if (vertex - m_sideLength < 0) {
      return false; 
   }

   // Ensures path up
   if ( ( m_walls[vertex] & m_upWall ) == m_upWall) {
      return false; 
   }

   return true; 
} 
