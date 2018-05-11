/**
*	@file : FarmAnimal.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.08
*	Purpose:
*/


#include "FarmAnimal.h"
#include <iostream>

FarmAnimal::FarmAnimal()
{
    m_name = "unset";
    m_sound = "unset";
}

std::string FarmAnimal::getName() const
{
    return (m_name);
}

void FarmAnimal::setName(std::string name)
{
    m_name = name;
}

std::string FarmAnimal::getSound() const
{
    return (m_sound);
}

void FarmAnimal::setSound(std::string sound)
{
    m_sound = sound;
}
