p6: main.o disjoint_set.o maze.o
	g++ -o p6 -std=c++20 main.o disjoint_set.o maze.o

main.o: main.cpp
	g++ -c -std=c++20 main.cpp

disjoint_set.o: disjoint_set.h disjoint_set.cpp
	g++ -c -std=c++20 disjoint_set.cpp

maze.o: maze.h maze.cpp
	g++ -c -std=c++20 maze.cpp

clean: 
	rm -f p6 *.o *~
