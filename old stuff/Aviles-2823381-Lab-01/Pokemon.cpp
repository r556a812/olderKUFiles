/**
*	@file : Pokemon.cpp
*	@author :  Richard Aviles
*	@date : 2015.08.08
*	Purpose: Implementation of the Pokemon class. Build the constructor and make the methods for the gets and sets.
*/

#include "Pokemon.h"


Pokemon::Pokemon ()
{
	m_hp=0;
	m_attackLevel=0;
	m_defenseLevel=0;
        string m_name="";
}

void Pokemon::reduceHP(int hp)
{
	m_hp=m_hp-hp;
}

int Pokemon::getHP() const
{
	return(m_hp);
}

void Pokemon::setHP(int hp)
{
	m_hp=hp;
}

int Pokemon::getAttackLevel() const
{
	return(m_attackLevel);
}

void Pokemon::setAttackLevel(int attack)
{
	m_attackLevel=attack;
}

int Pokemon::getDefenseLevel() const
{
	return(m_defenseLevel);
}

void Pokemon::setDefenseLevel(int defense)
{
	m_defenseLevel=defense;
}

string Pokemon::getName() const
{
	return(m_name);
}

void Pokemon::setName(string name)
{
	m_name=name;
}

 
