/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file main.cpp
* @assignment 6: Maze Generation with Disjoint Sets
*/

/*
* This program creates n*n sized mazes where n is given as a command line
* parameters and outputs the maze to STDOUT. The maze generation algorthim
* begins with all walls "filled" in the maze matrice then breaks them down. A
* disjoint set is used to stop the removal of a wall if there is already a path
* from that tile to the deletion candidates. I tested this program by creating
* mazes and inspecting them visually with Jeff Bergamini's maze viewer
* and by checking for memory leaks. The program appears to be working to all
* specs. 
*/

#include <iostream>

#include "maze.h"

int main(int argc, char** argv) {
   if (argc < 2) {
      throw std::invalid_argument("Missing command line param for maze size");
   }
   
   Maze maze(std::stoi(argv[1])); 
   std::cout << maze;
}
