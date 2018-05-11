lab5: main.o min5_heap.o
	g++ -std=c++11 -g -Wall main.o min5_heap.o -o lab5
main.o: main.cpp min5_heap.o
	g++ -std=c++11 -g -Wall -c main.cpp
min5_heap.o: min5_heap.h min5_heap.cpp
	g++ -std=c++11 -g -Wall -c min5_heap.cpp
clean: 
	rm *.o lab5
	echo clean done
	
