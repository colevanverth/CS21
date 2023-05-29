p1: main.o list.o
	g++ -std=c++20 -o p1 main.o list.o

main.o: main.cpp
	g++ -std=c++20 -c main.cpp

list.o: list.h list.cpp
	g++ -std=c++20 -c list.cpp

clean:
	rm -f p1 test *.o *~ 
