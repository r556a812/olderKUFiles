Lab01: main.o Pokemon.o Dice.o Colosseum.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Dice.o Colosseum.o -o Lab01
main.o: main.cpp Pokemon.h Colosseum.h Dice.h
	g++ -std=c++11 -g -Wall -c main.cpp
Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp
Colosseum.o: Colosseum.h Colosseum.cpp Pokemon.h Dice.h
	g++ -std=c++11 -g -Wall -c Colosseum.cpp
Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -Wall -c Dice.cpp
clean: 
	rm *.0 Lab01
	echo clean done
	
