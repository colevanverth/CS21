/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 8: Breadth-First Search 
*/

/**
* This program reads a maze from STDIN (see assignment `21-6` for more info).
* The shortest path from the start to the exit of the maze is found and sent to
* STDOUT. This program was tested with mazes of varying sizes that were visually
* inspected with Bergamini's maze viewer. The program was also checked with
* Valgrind for memory leaks. No errors were found and the program appears to be
* working to all specs. 
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "maze.h"

int main() {
   // Load input 
   std::string buffer; 
   std::vector<int> walls; 
   while (std::cin >> buffer) {
      for (size_t i = 0; i < buffer.size(); i++) {
         int wallValue = std::stoi(buffer.substr(i, 1), nullptr, 16); 
         walls.push_back(wallValue);
      }
   }

   // Generate path
   Maze maze(walls);
   maze.BreadthFirstSearch();

   // Output path
   std::cout << maze; 
}
