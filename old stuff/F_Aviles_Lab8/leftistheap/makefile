lab8: main.o leftistheap.o Node.o
	g++ -std=c++11 -g -Wall main.o leftistheap.o Node.o -o lab8
main.o: main.cpp leftistheap.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp
leftistheap.o: leftistheap.h leftistheap.cpp Node.h
	g++ -std=c++11 -g -Wall -c leftistheap.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean: 
	rm *.o lab8
	echo clean done
	
