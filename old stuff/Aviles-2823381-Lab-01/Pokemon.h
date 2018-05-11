 /**
*	@file : Pokemon.h
*	@author :  Richard Aviles
*	@date : 2015.08.08
*	Purpose: Header file for the Pokemon class. Used to construct a pokemon for the players.
*/

#ifndef POKEMON_H
#define POKEMON_H
#include <string>

using namespace std;


class Pokemon
{
    private:
        int m_hp;
        int m_attackLevel;
        int m_defenseLevel;
        string m_name;

    public:
        Pokemon(); //@pre None @post creates a Pokemon constructor. @return Initialized Pokemon with default values.
        
        void reduceHP(int hp); //@pre has to give a hp value greater than 0. @post reduces the HP by the amount of damage given in. @return None
        
        int getHP() const; //@pre None @post none @return Gives the HP for the pokemon at that moment.
        
        void setHP(int hp); //@pre has to give a value between 1 and 50. @post sets the users HP to the value given. @return None
        
        int getAttackLevel() const; //@pre None @post None @return Returns the value for the attack level
        
        void setAttackLevel(int attack); //@pre has to give a value between 1 and 49. @post sets the users attack level to the value given. @return None
        
        int getDefenseLevel() const; //@pre None @post None @return Returns the defense level value of the pokemon.
        
        void setDefenseLevel(int defense); //@pre has to give value between 1 and 49, that, when added with the attack level, is not greater than 50. @post sets the defense level of the pokemon to the given value. @return None.
        
        string getName() const; //@pre None @post None @return Returns the name of the pokemon.
        
        void setName(string name); //@pre None @post sets the pokemons name to the given name created.  @return None.
        
};

#endif

