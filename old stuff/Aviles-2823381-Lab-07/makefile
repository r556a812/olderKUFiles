Lab07: main.o Test.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o
	g++ -std=c++11 -g -Wall main.o Test.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o -o Lab07
main.o: main.cpp Sorts.hpp Sorts.h Test.h
	g++ -std=c++11 -g -Wall -c main.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp
NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp NumberFileGenerator.h
	g++ -std=c++11 -g -Wall -c NumberFileDriver.cpp
NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -std=c++11 -g -Wall -c NumberFileGenerator.cpp
SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -std=c++11 -g -Wall -c SortDriver.cpp
clean: 
	rm *.o Lab07
	echo clean done 
