p5: main.o hashtable.o record.o
	g++ -o p5 main.o hashtable.o record.o

main.o: main.cpp
	g++ -c main.cpp

hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp

record.o: record.cpp record.h
	g++ -c record.cpp

clean: 
	rm -f p5 *.o *~
