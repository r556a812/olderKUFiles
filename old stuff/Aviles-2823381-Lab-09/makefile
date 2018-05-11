Lab09: main.o Test.o MazeCreationException.o MazeReader.o MazeWalker.o Position.o 
	g++ -std=c++11 -g -Wall main.o Test.o MazeCreationException.o MazeReader.o MazeWalker.o Position.o -o Lab09
main.o: main.cpp Test.h MazeCreationException.h MazeReader.h MazeWalker.h Position.h
	g++ -std=c++11 -g -Wall -c main.cpp
Test.o: Test.h Test.cpp ArrayHelper.hpp
	g++ -std=c++11 -g -Wall -c Test.cpp
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp
MazeReader.o: MazeReader.h MazeReader.cpp MazeCreationException.h
	g++ -std=c++11 -g -Wall -c MazeReader.cpp
MazeWalker.o: MazeWalker.h MazeWalker.cpp Position.h
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp
Position.o: Position.h Position.cpp
	g++ -std=c++11 -g -Wall -c Position.cpp
clean: 
	rm *.o Lab09
	echo clean done 
 
 
