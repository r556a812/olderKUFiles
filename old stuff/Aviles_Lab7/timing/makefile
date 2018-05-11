lab7: main.o minmaxheap.o min5_heap.o
	g++ -std=c++11 -g -Wall main.o minmaxheap.o min5_heap.o -o lab7
main.o: main.cpp minmaxheap.h min5_heap.h
	g++ -std=c++11 -g -Wall -c main.cpp
minmaxheap.o: minmaxheap.h minmaxheap.cpp
	g++ -std=c++11 -g -Wall -c minmaxheap.cpp
min5_heap.o: min5_heap.h min5_heap.cpp
	g++ -std=c++11 -g -Wall -c min5_heap.cpp
clean: 
	rm *.o lab7
	echo clean done
	
