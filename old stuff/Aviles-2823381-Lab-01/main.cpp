/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2015.08.08
*	Purpose: This is the main, used to call methods from the included classes and interact with the user.
*/




#include <iostream>
#include "Pokemon.h"
#include "Colosseum.h"
#include "Dice.h"


int main ()
{

    char end = 'n';

    do
    {
    Pokemon player1;
    Pokemon player2;
    Colosseum c;
    std::cout << "Player 1 build your Pokemon!\n";
    std::cout << "=====================\n";
    c.userBuild(player1);

    std::cout << "Player 2 build your Pokemon!\n";
    std::cout << "=====================\n";
    c.userBuild(player2);

    c.play(player1, player2);

    std::cout << "\nDo you want to play again (y/n)? ";
    std::cin >> end;
    std::cout << "\n\n";
    }while (end!='n');

    std::cout << "Thanks for playing!";

}
