Lab02: main.o Node.o LinkedList.o Test.o
	g++ -std=c++11 -g -Wall main.o Node.o LinkedList.o Test.o -o Lab02
main.o: main.cpp Node.h LinkedList.h Test.h
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -std=c++11 -g -Wall -c LinkedList.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp
clean: 
	rm *.o Lab02
	echo clean done
	 
