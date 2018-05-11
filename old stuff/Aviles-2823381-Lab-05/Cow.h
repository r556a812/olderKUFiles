 
/**
*	@file : Cow.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  Header file for the Cow class. Creates a default cow with variable m_milkProduduced.
*/

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow:public FarmAnimal
{
public:
    Cow();  //@pre none @post creates a default cow object with default value for m_milkProduced to 0. @return none
    double getMilkProduced() const;  //@pre none @post returns the double stored in m_milkProduced @return returns the double in m_milkProduced
    void setMilkProduced(double gallons);  //@pre have to pass in a double @post sets m_milkProduced to the double passed in @return none
    
protected:
    double m_milkProduced;
    
};

#endif