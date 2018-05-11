/**
*	@file : NumberFileGenerator.h
*	@author : Richard Aviles
*	@date : 2015.10.22
	Purpose:  Header file for the NumberFileGenerator class. 
*/

#ifndef NUMBER_FILE_GENERATOR_H
#define NUMBER_FILE_GENERATOR_H 

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>


class NumberFileGenerator
{
public:
    static void ascending(std::string fileName, int amount);
    static void descending(std::string fileName, int amount);
    static void random(std::string fileName, int amount, int min, int max);
    static void singleValue(std::string fileName, int amount, int value);
    
};

#endif
