/**
*	@file : NumberFileDriver.h
*	@author : Richard Aviles
*	@date : 2015.10.22
	Purpose:  Header file for the NumberFileDriver class. 
*/

#ifndef NUMBER_FILE_DRIVER_H
#define NUMBER_FILE_DRIVER_H 

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>


class NumberFileDriver
{
public:
    static void run(int argc, char** argv);
    static void printHelpMenu();
    
private:
    static bool isValidOption(std::string option);
    
};

#endif
