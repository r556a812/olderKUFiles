lab10: main.o span_tree.o skewheap.o Node.o disjoint.o
	g++ -std=c++11 -g -Wall main.o span_tree.o skewheap.o Node.o disjoint.o -o lab10
main.o: main.cpp span_tree.h skewheap.h Node.h disjoint.h
	g++ -std=c++11 -g -Wall -c main.cpp
span_tree.o: span_tree.h span_tree.cpp Node.h disjoint.h
	g++ -std=c++11 -g -Wall -c span_tree.cpp
skewheap.o: skewheap.h skewheap.cpp Node.h
	g++ -std=c++11 -g -Wall -c skewheap.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
disjoint.o: disjoint.h disjoint.cpp
	g++ -std=c++11 -g -Wall -c disjoint.cpp
clean: 
	rm *.o lab10
	echo clean done
	
