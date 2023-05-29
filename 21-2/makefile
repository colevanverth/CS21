p2: main.o intminheap.o
	g++ -o p2 main.o intminheap.o

debug: main.o intminheap.o
	g++ -o p2 main.o intminheap.o

main.o: main.cpp 
	g++ -c main.cpp

intminheap.o: intminheap.h intminheap.cpp
	g++ -c intminheap.cpp

clean:
	rm -f p2 *.o *~

