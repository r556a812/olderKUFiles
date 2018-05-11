/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.08.26
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "Node.h"
#include "List.h"
#include <fstream>
using namespace std;

int main ()
{
    //Declare variables
    int choice = 0;
    List myList;
    int numAdd = 0;

    //Read the file, data.txt, and put into the List, myList.
    int nums = 0;
    ifstream infile;
    infile.open("data.txt");
    while (infile >> nums)
    {
        myList.insert(nums);
    }

    //Output to the screen what is in the data.txt file.
    std::cout << "\ndata.txt elements: ";
    myList.print();

    //Loop to ask user what they want to do. Runs until they give choice of 3 to exit.
    do
    {
        std::cout << "Please choose one of the following commands:\n\n"
                     "1- insert\n\n"
                     "2- print\n\n"
                     "3- exit\n\n";
        std::cin >> choice;

        //If statements to do what corresponds with the users choice.
        if (choice == 1)
        {
            std::cout << "\nChoose a number to be inserted in the list: ";
            std::cin >> numAdd;
            myList.insert(numAdd);
            std::cout << "\n";
        }
        else if (choice == 2)
        {
            std::cout << "\nList: ";
            myList.print();
        }
        else if (choice == 3)
        {
            myList.~List();
        }

    }while (choice != 3);
}

