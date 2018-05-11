/**
*	@file : NumberFileGenerator.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.22
*	Purpose:
*/

#include "NumberFileGenerator.h"


void NumberFileGenerator::ascending(std::string fileName, int amount)
{
    std::ofstream outFile(fileName);
    outFile << amount << "\n";
    for (int i=1; i<amount; i++)
    {
        if (i == amount)
        {
            outFile << i;
        }
        else
        {
            outFile << i << "\n";
        }

    }
    outFile.close();
}


void NumberFileGenerator::descending(std::string fileName, int amount)
{
    std::ofstream outFile(fileName);
    outFile << amount << "\n";
    for (int i=amount; i>0; i--)
    {
        if (i == 1)
        {
            outFile << i;
        }
        else
        {
            outFile << i << "\n";
        }
    }
    outFile.close();
}


void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min,max);
    std::ofstream outFile(fileName);
    outFile << amount << "\n";
    for (int i=0; i<amount; i++)
    {
        outFile << distribution(generator);
        if (i != amount-1)
        {
            outFile << "\n";
        }
    }
    outFile.close();
}


void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
    std::ofstream outFile(fileName);
    outFile << amount << "\n";

    for (int i=1; i<amount; i++)
    {
        if (i == amount)
        {
            outFile << value;
        }
        else
        {
            outFile << value << "\n";
        }
    }
    outFile.close();
}
