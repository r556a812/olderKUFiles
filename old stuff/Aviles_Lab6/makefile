lab6: main.o Node.o BST.o min5_heap.o
	g++ -std=c++11 -g -Wall main.o Node.o BST.o min5_heap.o -o lab6
main.o: main.cpp Node.h BST.h min5_heap.h 
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
BST.o: BST.h BST.cpp Node.h
	g++ -std=c++11 -g -Wall -c BST.cpp
min5_heap.o: min5_heap.h min5_heap.cpp
	g++ -std=c++11 -g -Wall -c min5_heap.cpp
clean: 
	rm *.o lab6
	echo clean done
	
