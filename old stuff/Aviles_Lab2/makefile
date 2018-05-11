lab2: main.o Node.o List.o
	g++ -std=c++11 -g -Wall main.o Node.o List.o -o lab2
main.o: main.cpp Node.h List.h
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
List.o: List.h List.cpp Node.h
	g++ -std=c++11 -g -Wall -c List.cpp
clean: 
	rm *.o lab2
	echo clean done
	
