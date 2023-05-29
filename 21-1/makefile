p1: main.o list.o stack.o
	g++ -o p1 main.o list.o stack.o

main.o: main.cpp
	g++ -c main.cpp

list.o: list.h list.cpp
	g++ -c list.cpp

stack.o: stack.h stack.cpp
	g++ -c stack.cpp

clean:
	rm -f p1 test *.o *~ 

debug: main.cpp stack.cpp list.cpp
	g++ -o p1 -g main.cpp stack.cpp list.cpp
