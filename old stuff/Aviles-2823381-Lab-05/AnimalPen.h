/**
*	@file : AnimalPen.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  Header file for the Animal Pen class. 
*/

#ifndef ANIMAL_PEN_H
#define ANIMAL_PEN_H

#include "Stack.h"
#include "FarmAnimal.h"


class AnimalPen:public Stack<FarmAnimal*>
{
public:
    AnimalPen();    //@pre none  @post none  @return none 
    ~AnimalPen();    //@pre have to have a non-empty pen @post deletes all the FarmAnimal objects @return none
    void addAnimal(FarmAnimal* animal);    //@pre have to pass an animal pointer @post adds a new farm animal object to the list @return none
    FarmAnimal* peakAtNextAnimal();    //@pre have to have a  non empty animal pen @post gives the last animal created in the pen back to the caller @return returns a farm animal pointer to the last animal object created.
    void releaseAnimal();    //@pre have to have a non empty animal pen @post deletes the animal object on the top of the list.  @return none
    bool isPenEmpty();    //@pre have to have an animal pen created @post none  @return returns true if the pen is empty, false if the pen is not empty.
    
};

#endif
