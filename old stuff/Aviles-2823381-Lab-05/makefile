Lab05: main.o Cow.o FarmAnimal.o Chicken.o CyberChicken.o AnimalPen.o PreconditionViolationException.o 
	g++ -std=c++11 -g -Wall main.o Cow.o FarmAnimal.o Chicken.o CyberChicken.o AnimalPen.o PreconditionViolationException.o -o Lab05
main.o: main.cpp Cow.h FarmAnimal.h Chicken.h CyberChicken.h Stack.h Stack.hpp StackInterface.h Node.h Node.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -std=c++11 -g -Wall -c FarmAnimal.cpp
Cow.o: Cow.h Cow.cpp FarmAnimal.h
	g++ -std=c++11 -g -Wall -c Cow.cpp
Chicken.o: FarmAnimal.h Chicken.h Chicken.cpp
	g++ -std=c++11 -g -Wall -c Chicken.cpp
CyberChicken.o: CyberChicken.h CyberChicken.cpp FarmAnimal.h Chicken.h
	g++ -std=c++11 -g -Wall -c CyberChicken.cpp
AnimalPen.o: Stack.h AnimalPen.h AnimalPen.cpp FarmAnimal.h Chicken.h Cow.h
	g++ -std=c++11 -g -Wall -c AnimalPen.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp
clean: 
	rm *.o Lab05
	echo clean done
	 
 
 
