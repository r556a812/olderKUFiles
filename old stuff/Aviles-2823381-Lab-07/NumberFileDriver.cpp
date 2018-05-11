/**
*	@file : NumberFileDriver.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.22
*	Purpose:
*/

#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"

void NumberFileDriver::printHelpMenu()
{
        std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
                        << "./prog -create -a filename amount\n"
                        << "./prog -create -d filename amount\n"
                        << "./prog -create -s filename amount value\n"
                        << "./prog -create -r filename amount min max\n"
                        << "Option explainations:\n"
                        << "\t-a for ascending\n"
                        << "\t-d for descending\n"
                        << "\t-s for a single value\n"
                        << "\t-r for random values\n"
                        << "\tfilename is the ouput file name\n"
                        << "\tamount is the amount of random numbers to place in the file\n"
                        << "\tvalue is the single number that will be written to file in -s mode\n"
                        << "\tmin is the low end of the range of random numbers\n"
                        << "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}


void NumberFileDriver::run(int argc, char **argv)
{
    std::string option = argv[2];
    std::string type = argv[2];
    std::string file = argv[3];

    if (!isValidOption(option))
    {
        printHelpMenu();
        return;
    }

    NumberFileGenerator generator;

    if (argc<5)
    {
        printHelpMenu();
        return;
    }

    if (type == "-a")
    {
        if (argc == 5)
        {
            int amount = std::stoi(argv[4]);
            generator.ascending(file, amount);
        }
        else
        {
            printHelpMenu();
        }
    }
    else if (type == "-d")
    {
        if (argc == 5)
        {
            int amount = std::stoi(argv[4]);
            generator.descending(file, amount);
        }
        else
        {
            printHelpMenu();
        }
    }
    else if (type == "-r")
    {
        if (argc == 7)
        {
            int amount = std::stoi(argv[4]);
            int min = std::stoi(argv[5]);
            int max = std::stoi(argv[6]);
            generator.random(file, amount, min, max);
        }
        else
        {
            printHelpMenu();
        }
    }
    else if (type == "-s")
    {
        if (argc == 6)
        {
            int amount = std::stoi(argv[4]);
            int value = std::stoi(argv[5]);
            generator.singleValue(file, amount, value);
        }
        else
        {
            printHelpMenu();
        }
    }

}



bool NumberFileDriver::isValidOption(std::string option)
{
    if (option == "-a" || "-d" || "-r" || "-s")
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
