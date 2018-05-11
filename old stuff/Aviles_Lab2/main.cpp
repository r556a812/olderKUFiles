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
    List myList2;
    int numAdd = 0;
    int numDelete = 0;

    //Read the file, data.txt, and put into the List, myList.
    int nums = 0;
    ifstream infile;
    infile.open("data.txt");
    while (infile >> nums)
    {
        myList.insert(nums);
    }

    //Read the file, data2.txt, and put into the List, myList2.
    int nums2 = 0;
    ifstream infile2;
    infile2.open("data2.txt");
    while (infile2 >> nums2)
    {
        myList2.insert(nums2);
    }

    //Output to the screen what is in the data.txt file.
    std::cout << "\ndata.txt elements: ";
    myList.print();

    //Output to the screen what is in the data2.txt file.
    std::cout << "\ndata2.txt elements: ";
    myList2.print();

    //Loop to ask user what they want to do. Runs until they give choice of 3 to exit.
    do
    {
        std::cout << "Please choose one of the following commands:\n\n"
                     "1- insert\n\n"
                     "2- delete\n\n"
                     "3- reverse\n\n"
                     "4- concatenate\n\n"
                     "5- print\n\n"
                     "6- exit\n\n";
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
            std::cout << "\nChoose a number to be deleted from the list: ";
            std::cin >> numDelete;
            myList.erase(numDelete);
            std::cout << "\n";
        }
        else if (choice == 3)
        {
            myList.reverse(myList.m_front, nullptr);
            std::cout << "\n";
        }
        else if (choice == 4)
        {
            myList.concatenate(myList.m_front, myList2.m_front);
            std::cout << "\n";
        }
        else if (choice == 5)
        {
            std::cout << "\nList: ";
            myList.print();
        }
        else if (choice == 6)
        {
            myList.~List();
        }

    }while (choice != 6);
}

