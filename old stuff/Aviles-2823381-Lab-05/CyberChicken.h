/**
*	@file : CyberChicken.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  Header file for the Cyber Chicken class. Derived from chicken class.
*/

#ifndef CYBER_CHICKEN_H
#define CYBER_CHICKEN_H

#include "FarmAnimal.h"
#include "Chicken.h"


class CyberChicken:public Chicken
{
public:
    CyberChicken(); //@pre none @post creates a cyber chicken object with default values @return none
    int getCyberEggs() const; //@pre none @post returns the amount of eggs stored @return returns the m_cyberEggsProduced int to the caller
    void setCyberEggs(int eggs); //@pre have to pass in an int @post sets m_cyberEggsProduced to the int passed in. @return none.
    
};

#endif
