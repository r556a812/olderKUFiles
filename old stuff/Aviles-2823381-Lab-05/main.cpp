#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

void goodbyeMessage(const FarmAnimal& animal)
{
    std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "\n";
}

int main()
{
    char end = 'n';
    int choice = 0;
    int milk = 0;
    int eggs = 0;
    AnimalPen a1;
    Cow* c = nullptr;
    Chicken* chick = nullptr;
    CyberChicken* cyber = nullptr;
    std::string animal = "";
    int milkProduced = 0;
    int totalMilkProduced = 0;
    int eggsProduced = 0;
    int totalEggsProduced = 0;


try
{

    do
    {
        std::cout << "Select an animal to add to the pen:\n1.) Cow (produces milk)\n2.) Chicken (cannot lay eggs)\n3.) Cyber Chicken (seems dangerous, but lays eggs)\n";
        std::cout << "---------------------------------------------------";
        std::cout << "\nchoice: ";
        std::cin >> choice;


        if (choice == 1)
        {
            std::cout << "How many gallons of milk did this cow produce?: ";
            std::cin >> milk;
            FarmAnimal* a = new Cow();
            c = static_cast<Cow*>(a);
            c -> setMilkProduced(milk);
            a1.addAnimal(a);

        }

        if (choice == 2)
        {
            std::cout << "Add an eggless chicken to the pen? OK. You're the boss. ";
            FarmAnimal* a = new Chicken();
            chick = static_cast<Chicken*>(a);
            a1.addAnimal(chick);
        }

        if (choice == 3)
        {
            std::cout << "How many eggs did this cyber chicken produce?: ";
            std::cin >> eggs;
            FarmAnimal* a = new CyberChicken();
            cyber = static_cast<CyberChicken*>(a);
            cyber -> setCyberEggs(eggs);
            a1.addAnimal(cyber);

        }

        std::cout << "Done adding animals? (y/n): ";
        std::cin >> end;

    }while (end != 'y');

    std::cout << "\nReleasing all animals!";
    std::cout << "\n---------------------------------------------------\n";



   do
    {
        animal = a1.peakAtNextAnimal()->getName();

        if (animal == "Cow")
        {
            FarmAnimal* farmTemp = a1.peakAtNextAnimal();
            Cow* cowTemp = static_cast<Cow*>(farmTemp);
            milkProduced = cowTemp -> getMilkProduced();
            totalMilkProduced = totalMilkProduced + milkProduced;
            std::cout << "This Cow produced " << milkProduced << " gallons of milk. \n";
            goodbyeMessage(*(cowTemp));
            a1.releaseAnimal();
            std::cout << "Cow Destructor called.\n";
        }

        if (animal == "Chicken")
        {
            FarmAnimal* farmTemp = a1.peakAtNextAnimal();
            Chicken* chickTemp = static_cast<Chicken*>(farmTemp);
            std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?\n";
            goodbyeMessage(*(chickTemp));
            a1.releaseAnimal();


        }

        if (animal == "Cyber Chicken")
        {
            FarmAnimal* farmTemp = a1.peakAtNextAnimal();
            CyberChicken* cybTemp = static_cast<CyberChicken*>(farmTemp);
            eggsProduced = cybTemp -> getCyberEggs();
            totalEggsProduced = totalEggsProduced + eggsProduced;
            std::cout << "This Cyber Chicken laid " << eggsProduced << " cyber eggs. Humanity is in trouble.\n";
            goodbyeMessage(*(cybTemp));
            a1.releaseAnimal();
            std::cout << "CyberChicken Destructor called." << "\nChicken Destructor called.\n";
        }


    }while(!a1.isPenEmpty());

    std::cout << "\nYour farm produced " << totalMilkProduced << " gallons of milk and " << totalEggsProduced << " eggs.";
}
catch (std::runtime_error& e)
{
    std::cout << e.what() << std::endl;

}



    return (0);
}
