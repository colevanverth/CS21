p: main.o singlylinked.o queue.o
	g++ -o p singlylinked.o main.o queue.o

singlylinked.o: singlylinked.cpp singlylinked.h
	g++ -c singlylinked.cpp

main.o: main.cpp
	g++ -c main.cpp

queue.o: queue.cpp queue.h
	g++ -c queue.cpp queue.h

clean: 
	rm *.o p
