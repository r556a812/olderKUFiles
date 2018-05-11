lab7: main.o minmaxheap.o
	g++ -std=c++11 -g -Wall main.o minmaxheap.o -o lab7
main.o: main.cpp minmaxheap.h 
	g++ -std=c++11 -g -Wall -c main.cpp
minmaxheap.o: minmaxheap.h minmaxheap.cpp
	g++ -std=c++11 -g -Wall -c minmaxheap.cpp
clean: 
	rm *.o lab7
	echo clean done
	
