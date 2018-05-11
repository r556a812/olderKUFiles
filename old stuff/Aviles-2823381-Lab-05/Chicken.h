/**
*	@file : Chicken.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  Header file for the Chicken class. Creates a new chicken with methods to handle the eggs.
*/

#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"

class Chicken:public FarmAnimal
{
public:
    Chicken();  //@pre none @post creates default chicken object with m_eggs set to 0. @return none
    
    
protected:
    int getEggs() const;  //@pre none @post returns the amount of eggs stored in m_eggs @return returns an int that is the number of eggs stored in m_eggs.
    void setEggs(int eggs);  //@pre have to pass in an int @post sets m_eggs to the int passed in. @return none
    int m_eggs;  
    
};

#endif
