lab9: main.o leftistheap.o skewheap.o Node.o
	g++ -std=c++11 -g -Wall main.o leftistheap.o skewheap.o Node.o -o lab9
main.o: main.cpp leftistheap.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp
leftistheap.o: leftistheap.h leftistheap.cpp Node.h
	g++ -std=c++11 -g -Wall -c leftistheap.cpp
skewheap.o: skewheap.h skewheap.cpp Node.h
	g++ -std=c++11 -g -Wall -c skewheap.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean: 
	rm *.o lab9
	echo clean done
	
