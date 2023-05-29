p7: main.o binary_search_tree.o
	g++ -o p7 main.o binary_search_tree.o

main.o: main.cpp
	g++ -c main.cpp

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
	g++ -c binary_search_tree.cpp 

clean: 
	rm -f p7 *.o *~
