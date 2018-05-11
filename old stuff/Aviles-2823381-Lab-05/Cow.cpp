/**
*	@file : Cow.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.08
*	Purpose:
*/


#include "Cow.h"
#include "FarmAnimal.h"

Cow::Cow()
{
    setName("Cow");
    setSound("Moo");
}

double Cow::getMilkProduced() const
{
    return (m_milkProduced);
}

void Cow::setMilkProduced(double gallons)
{
    if (gallons > 0)
    {
        m_milkProduced = gallons;
    }
    else
    {
        m_milkProduced = 0;
    }
}
