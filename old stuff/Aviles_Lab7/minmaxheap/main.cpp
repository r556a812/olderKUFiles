/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.10.21
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "minmaxheap.h"
#include <fstream>

using namespace std;

int main ()
{
       //Declare variables
        int choice = 0;
        minmaxheap myHeap;
        int myArray[400000];
        int numAdd = 0;

        //Read the file, data.txt, and put into the List, myList.
        int nums = 0;
        ifstream infile;
        infile.open("data.txt");
        while (infile >> nums)
        {
            myHeap.initialInsert(myArray, nums);
        }
        infile.close();

        myHeap.bottomUp(myArray);

        //Loop to ask user what they want to do. Runs until they give choice of 5 to exit.
        do
        {
            std::cout << "Please choose one of the following commands:\n\n"
                         "1- insert\n\n"
                         "2- deletemin\n\n"
                         "3- deletemax\n\n"
                         "4- levelorder\n\n"
                         "5- exit\n\n";
            std::cin >> choice;

            //If statements to do what corresponds with the users choice.
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> numAdd;
                myHeap.insert(myArray, numAdd);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 2)
            {
                myHeap.deletemin(myArray);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 3)
            {
                myHeap.deletemax(myArray);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 4)
            {
                std::cout << "levelorder: \n";
                myHeap.levelorder(myArray);
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if(choice == 5)
            {
                myHeap.~minmaxheap();
                std::cout << "\n\n";
            }

        }while (choice != 5);
}

