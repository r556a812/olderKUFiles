Lab08: main.o Test.o
	g++ -std=c++11 -g -Wall main.o Test.o -o Lab08
main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp Node.h Node.hpp Test.h BSTI.h
	g++ -std=c++11 -g -Wall -c main.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp
clean: 
	rm *.o Lab08
	echo clean done 
 
