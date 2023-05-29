VERSION = -std=c++20

p8: main.o maze.o
	g++ $(VERSION) -o p8 main.o maze.o

main.o: main.cpp
	g++ $(VERSION) -c main.cpp

maze.o: maze.cpp maze.h
	g++ $(VERSION) -c maze.cpp

clean: 
	rm -f p8 *.o *~
