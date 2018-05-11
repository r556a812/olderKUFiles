lab8: main.o skewheap.o Node.o
	g++ -std=c++11 -g -Wall main.o skewheap.o Node.o -o lab8
main.o: main.cpp skewheap.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp
skewheap.o: skewheap.h skewheap.cpp Node.h
	g++ -std=c++11 -g -Wall -c skewheap.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean: 
	rm *.o lab8
	echo clean done
	
