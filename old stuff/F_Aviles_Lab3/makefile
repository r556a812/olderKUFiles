lab3: main.o Hash.o
	g++ -std=c++11 -g -Wall main.o Hash.o -o lab3
main.o: main.cpp Hash.h
	g++ -std=c++11 -g -Wall -c main.cpp
Hash.o: Hash.cpp Hash.h
	g++ -std=c++11 -g -Wall -c Hash.cpp
clean: 
	rm *.o lab3
	echo clean done
	
