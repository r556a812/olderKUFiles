/**
*	@file : SortDriver.h
*	@author : Richard Aviles
*	@date : 
	Purpose:  Header file for the SortDriver class. 
*/

#ifndef SORT_DRIVER_H
#define SORT_DRIVER_H 

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>


class SortDriver
{
public:
    static void run(int argc, char** argv);
    static void printHelpMenu();
    
private:
    static bool isFileAccessible(std::string fileName);
    static bool isSortValid(std::string sortParameter);
    static bool areParametersValid(std::string sortName, std::string inputFileName);
    static int getFileCount(std::ifstream& inputFile);
    static int* createArray(std::ifstream& inputFile, int size);
    static void copyArray(int original[], int copy[], int size);
    
};


#endif
