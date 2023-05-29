/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file maze.h
* @assignment 8: Breadth-First Search
*/

#pragma once

#include <vector>
#include <ostream>
#include <queue>
#include <cmath>

/**
* `Maze` reads in a maze and uses a breadth-first search algorithim to solve the
* shortest path from start to finish; the interface allows the user to view the
* solution. 
*/
class Maze {

public:

   /**
   * `Maze` constuctor. 
   * @param `walls` vector containing wall values for all tiles
   */
   Maze(const std::vector<int>& walls); 

   /**
   * Outputs `Maze` solution.
   * @param `os` ostream reference to insert maze solution into   
   * @param `maze` maze containing solution
   */
   friend std::ostream& operator<<(std::ostream& os, Maze& maze);

   /**
   * Executes breadth first search algorithim. 
   */
   void BreadthFirstSearch();

private:

   /**
   * Finds adjacent tiles that have a path between them and places them into
   * `m_adjacents`. 
   * @param `vertex` index of tile
   */
   void findAdjacents(int vertex); 

   /**
   * Determines if there is a path to tile directly to the right. 
   * @param `vertex` index of tile
   * @return true if path to tile directly right, else false 
   */
   bool m_connectsRight(int vertex);

   /**
   * Determines if there is a path to tile directly above. 
   * @param `vertex` index of tile
   * @return true if path to tile directly above, else false
   */
   bool m_connectsUp(int vertex);

   /**
   * Determines if there is a path to tile directly below. 
   * @param `vertex` index of tile
   * @return true if path to tile directly below, else false 
   */
   bool m_connectsDown(int vertex);

   /**
   * Determines if there is a path to tile directly left
   * @param `vertex` index od tile
   * @return true if path to tile directly below, else false
   */
   bool m_connectsLeft(int vertex);

   /**
   * Calculates index of tile directly to right. 
   */
   int m_toRight(int vertex) { return vertex + 1; }

   /**
   * Calculates index of tile directly to left. 
   */
   int m_toLeft(int vertex) { return vertex - 1; }
   
   /**
   * Calculates index of tile directly above. 
   */
   int m_toUp(int vertex) { return vertex - m_sideLength; } 

   /**
   * Calculates index of tile directly below. 
   */
   int m_toDown(int vertex) { return vertex + m_sideLength; } 

   std::vector<int> m_walls; // The values of all walls

   std::vector<int> m_adjacents; // Vector of adjacents walls (see findAdjacents)

   std::vector<bool> m_candidate; // Whether a tile has been discovered or not 
   
   std::vector<int> m_parent; // The parent index of a tile

   std::queue<int> m_activeCandidates; // Tiles who will be explored with BFS
                                      
   const int m_null = -1; // Flag value for `m_parent` when no parent exists
                          
   const int m_exit; // Index of tile that exits maze

   const int m_entry = 0; // Index of tile that enters maze

   const int m_rightWall = 0x1; // Value of only a right wall 

   const int m_leftWall = 0x4; // Value of only a left wall 

   const int m_upWall = 0x8; // Value of only a wall above

   const int m_downWall = 0x2; // Value of only a wall below

   int m_numWalls; // The total number of tiles (entries in maze matrice) 

   int m_sideLength; // Side length of maze matrice
};
