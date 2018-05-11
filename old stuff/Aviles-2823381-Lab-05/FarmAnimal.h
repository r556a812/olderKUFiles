/**
*	@file : FarmAnimal.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  Header file for the Farm Animal class. Has get and set methods for sound and name.
*/

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include <iostream>

class FarmAnimal
{
public: 
    FarmAnimal();   //@pre none @post creates a Farm Animal object with default sound and name as "unset" @return none
    std::string getName() const;   //@pre none @post provides the name of the farm animal object @return returns the string set for m_name.
    void setName(std::string name);   //@pre have to pass in a string @post sets m_name to the string passed in @return none
    std::string getSound() const;   //@pre none @post provides the sound of the farm animal object @return returns the string set for m_sound.
    void setSound(std::string sound);   //@pre have to pass in a string @post sets m_sound to the string passed in @return none
    
protected:
    std::string m_name;
    std::string m_sound;
    
};

#endif
