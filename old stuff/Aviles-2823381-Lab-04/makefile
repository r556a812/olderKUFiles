Lab04: main.o PreconditionViolationException.o Test.o
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o Test.o -o Lab04
main.o: main.cpp Stack.hpp Stack.h Node.hpp Node.h StackInterface.h Test.h
	g++ -std=c++11 -g -Wall -c main.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp
clean: 
	rm *.o Lab04
	echo clean done
	 
 
