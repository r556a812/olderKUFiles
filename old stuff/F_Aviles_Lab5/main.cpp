/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.09.30
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "min5_heap.h"
#include <fstream>
using namespace std;

int main ()
{
    //Declare variables
        int choice = 0;
        min5_heap myHeap;
        int numAdd = 0;
        int numDelete = 0;

        //Read the file, data.txt, and put into the List, myList.
        int nums = 0;
        ifstream infile;
        infile.open("data.txt");
        while (infile >> nums)
        {
            myHeap.initialInsert(nums);
        }
        infile.close();

        myHeap.heapify();

        //Loop to ask user what they want to do. Runs until they give choice of 3 to exit.
        do
        {
            std::cout << "Please choose one of the following commands:\n\n"
                         "1- insert\n\n"
                         "2- deletemin\n\n"
                         "3- deletemax\n\n"
                         "4- remove\n\n"
                         "5- levelorder\n\n"
                         "6- exit\n\n";
            std::cin >> choice;

            //If statements to do what corresponds with the users choice.
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the heap: \n";
                std::cin >> numAdd;
                myHeap.insert(numAdd);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 2)
            {
                myHeap.deletemin();
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 3)
            {
                myHeap.deletemax();
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 4)
            {
                std::cout << "Please insert the number that you want to remove from the 5-Heap: \n";
                std::cin >> numDelete;
                myHeap.remove(numDelete);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 5)
            {
                std::cout << "levelorder: \n";
                myHeap.levelorder();
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if(choice == 6)
            {
                myHeap.~min5_heap();
                std::cout << "\n\n";
            }

        }while (choice != 6);;
}

