/**
*	@file : Colosseum.cpp
*	@author :  Richard Aviles
*	@date : 2015.08.08
*	Purpose: Implementation of the Colosseum class. Builds a constructor and methods to build the pokemon, attack, and play.
*/



#include <iostream>
#include <string>
#include <sstream>
#include "Colosseum.h"
#include "Pokemon.h"
#include "Dice.h"

using namespace std;


Colosseum::Colosseum()
{
	d20 = Dice(20);
	d6 = Dice(6);
	d2 = Dice(2);
}

void Colosseum::userBuild(Pokemon& p)
{
        string tempName="";
        int tempHP=0;
        bool check = false;
        int tempAttack=0;
        int tempDefense=0;

        std::cout<< "Please name your pokemon: ";
        cin >> tempName;
        p.setName(tempName);


        std::cout<< "How many hit points will it have? (1-50): ";
        cin >> tempHP;
        do
        {
            check = false;

            if (tempHP>50)
            {
                std::cout<< "Sorry. The hit points must be between 1 and 50: ";
                cin>>tempHP;
            }
            else if (tempHP<1)
            {
                std::cout<< "Sorry. The hit points must be between 1 and 50: ";
                cin>>tempHP;
            }
            else
            {
                check = true;
            }

        }while(check==false);

        p.setHP(tempHP);

        std::cout<< "Split fifty points between attack level and defense level";
        std::cout<< "\nEnter your attack level (1-49): ";
        cin >> tempAttack;
        do
        {
            check = false;

            if (tempAttack>49)
            {
                std::cout<< "Sorry. The attack level must be between 1 and 49: ";
                cin>>tempAttack;
            }
            else if (tempAttack<1)
            {
                std::cout<< "Sorry. The attack level must be between 1 and 49: ";
                cin>>tempAttack;
            }
            else
            {
                check = true;
            }

        }while(check==false);

        p.setAttackLevel(tempAttack);


        std::cout<< "Enter your defense level (1-"<<50-tempAttack<<"); ";
        cin >> tempDefense;
        do
        {
            check = false;

            if (tempDefense>50-tempAttack)
            {
                std::cout<< "Sorry. The defense level must be between 1 and "<<50-tempAttack<<": ";
                cin>>tempDefense;
            }
            else if (tempDefense<1)
            {
                std::cout<< "Sorry. The attack level must be between 1 and "<<50-tempAttack<<": ";
                cin>>tempDefense;
            }
            else
            {
                check = true;
            }

        }while(check==false);

        p.setDefenseLevel(tempDefense);
	
}

bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
    bool dead = false;
    int attackBonus = d20.roll();
    int defenseBonus =  d20.roll();
    int damage = 0;
    int roll1 = 0;
    int roll2 = 0;
    int roll3 = 0;

    std::cout << "\n" << attacker.getName() << " rolls an attack bonus of " << attackBonus;
    std::cout << "\n" << defender.getName() << " rolls a defense bonus of " << defenseBonus;

    if (attacker.getAttackLevel() + attackBonus > defender.getDefenseLevel() + defenseBonus)
    {
        roll1 = d6.roll();
        roll2 = d6.roll();
        roll3 = d6.roll();
        damage = roll1 + roll2 + roll3;
        std::cout << "\nThe attack hits dealing 3-D6 damage!";
        std::cout << "\nThe rolls are " << roll1 << ", " << roll2 << ", and " << roll3 << " totaling: " << damage << "!";

        defender.reduceHP(damage);
    }
    else
    {
        std::cout << "\nThe attack missed!";
    }


    if (defender.getHP() < 0)
    {
        dead = true;
    }

    if (defender.getHP() > 0)
    {
        std::cout << "\n" << defender.getName() << " has " << defender.getHP() << " hit points left";
    }




    return(dead);
}


void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
    int turn = d2.roll();
    int round = 1;
    bool dead = false;
    std::cout << "\nChoosing which player to go first:";

    if (turn == 1)
    {
        std::cout << "\nPlayer 1 will go first.\n";
    }
    else
    {
        std::cout << "\nPlayer 2 will go first.\n";
    }

    do
    {

        for (int x=0; x<10; x++)
        {
            if (turn==1)
            {

                std::cout << "\n\nRound " << round << "!\n";
                round++;

                if(attack(p1,p2))
                {
                    std::cout << "\n" << p2.getName() << " has been defeated!";
                    dead = true;
                    break;
                }
                if (attack(p2,p1))
                {
                    std::cout << "\n" << p1.getName() << " has been defeated!";
                    dead = true;
                    break;
                }

            }
            else
            {
                std::cout << "\n\nRound " << round << "!\n";
                round++;

                if(attack(p2,p1))
                {
                    std::cout << "\n" << p1.getName() << " has been defeated!";
                    dead = true;
                    break;
                }
                if(attack(p1,p2))
                {
                    std::cout << "\n" << p2.getName() << " has been defeated!";
                    dead = true;
                    break;

                }


            }

        }
       if(dead==false)
       {
           std::cout << "\nIt's a draw!";
           dead=true;
       }



    }while (dead==false);
}

