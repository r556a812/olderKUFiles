/**
*	@file : Colosseum.h
*	@author : Richard Aviles
*	@date : 2018.08.08
	Purpose: Header file for the colosseum class.  This is used to have the pokemon "battle" each other and update the new values for each pokemon. 
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include "Pokemon.h"
#include "Dice.h"



class Colosseum
{
    public:
	Colosseum(); //@pre None @post Creates a constructor for the colloseum with default values. @return None.
        
	void userBuild(Pokemon& p); //@pre have to have a premade pokemon to pass in to the method. @post Sets the characteristics for the pokemon passed in. @return None
        
	bool attack(const Pokemon& attacker, Pokemon& defender); //@pre have to pass in two pokemon with HP still above 0. @post Determines if they land attacks, and if so, how much and sets the new value for the hp. @return Returns false if the pokemon attacked still has HP left. Returns true if the Pokemon had no HP left and is dead.
        
	void play(Pokemon& p1, Pokemon& p2); // @pre have to pass in two pokemon already created. @post Runs the game through the 10 rounds or until the pokemon have died. @return Displays to the user all the information about whats going on in the battle. Information displayed is who goes first, round number, dice rolls, if attacks land, and Hp left after each attack.

    private:
	Dice d20;
	Dice d6;
	Dice d2;
	
};


#endif 
