/**
*	@file : AnimalPen.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.08
*	Purpose:
*/



#include "AnimalPen.h"


AnimalPen::AnimalPen()
{

}


AnimalPen::~AnimalPen()
{
    while (!isEmpty())
       {
           pop();
       }
}


void AnimalPen::addAnimal(FarmAnimal* animal)
{
    push(animal);
}


FarmAnimal* AnimalPen::peakAtNextAnimal()
{
    return(peek());
}


void AnimalPen::releaseAnimal()
{
    pop();
}


bool AnimalPen::isPenEmpty()
{
    if (isEmpty() == true)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
