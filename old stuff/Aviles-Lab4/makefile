lab4: main.o Node.o BST.o
	g++ -std=c++11 -g -Wall main.o Node.o BST.o -o lab4
main.o: main.cpp Node.h BST.h
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
BST.o: BST.h BST.cpp Node.h
	g++ -std=c++11 -g -Wall -c BST.cpp
clean: 
	rm *.o lab4
	echo clean done
	
