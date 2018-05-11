/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.09.16
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "Hash.h"
#include <fstream>
using namespace std;

int main ()
{
    //Declare variables
    int choice = 0;
    int numAdd = 0;
    int numDelete = 0;
    int length = 0;
    Hash myHash;

    //Read the file, data.txt, create the arrays, and insert numbers into the array list.
    int nums = 0;
    ifstream infile;
    infile.open("data.txt");
    //To read the first only, since the first determines the length
    int stop = 0;
    while (stop == 0 && infile >> nums)
    {
        length = nums;
        stop = 1;
    }
    //Create the arrays with the length read in
    int list[length];
    bool flags[length];
    //Initialize the arrays with default values
    for (int i = 0; i < length; i++)
    {
        list[i] = -1;
        flags[i] = false;
    }
    //Input the rest of the values into the list
    while (infile >> nums)
    {
        myHash.insert(nums, length, list, flags);
    }

    //Loop to ask user what they want to do. Runs until they give choice of 4 to exit.
    do
    {
        std::cout << "Please choose one of the following commands:\n\n"
                     "1- insert\n\n"
                     "2- delete\n\n"
                     "3- print\n\n"
                     "4- exit\n\n";
        std::cin >> choice;

        //If statements to do what corresponds with the users choice.
        if (choice == 1)
        {
            std::cout << "\nWhich number do you want to insert into the hash table?\n";
            std::cin >> numAdd;
            myHash.insert(numAdd, length, list, flags);
            std::cout << "\n";
        }
        else if (choice == 2)
        {
            std::cout << "\nWhich number do you want to remove from the hash table?\n";
            std::cin >> numDelete;
            myHash.remove(numDelete, length, list, flags);
            std::cout << "\n";
        }
        else if (choice == 3)
        {
            std::cout << "\n";
            myHash.print(length,list, flags);
            std::cout << "\n";
        }

    }while (choice != 4);
}

