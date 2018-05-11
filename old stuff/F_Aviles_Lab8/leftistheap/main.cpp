/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.11.10
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "leftistheap.h"
#include "Node.h"
#include <fstream>

using namespace std;

int main ()
{
       //Declare variables
        int choice = 0;
        leftistheap myHeap;
        int numAdd = 0;

        //Read the file, data.txt, and put into the List, myList.
        int nums = 0;
        ifstream infile;
        infile.open("data.txt");
        while (infile >> nums)
        {
            myHeap.insert(nums);
        }
        infile.close();

        //Loop to ask user what they want to do. Runs until they give choice of 6 to exit.
        do
        {
            std::cout << "\nPlease choose one of the following commands:\n\n"
                         "1- insert\n\n"
                         "2- deletemin\n\n"
                         "3- preorder\n\n"
                         "4- inorder\n\n"
                         "5- levelorder\n\n"
                         "6- end\n\n";
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
                std::cout << "preorder: \n";
                myHeap.preorder(myHeap.head);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 4)
            {
                std::cout << "inorder: \n";
                myHeap.inorder(myHeap.head);
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if(choice == 5)
            {
                std::cout << "levelorder: \n";
                myHeap.levelorder(myHeap.head);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if(choice == 6)
            {
                myHeap.~leftistheap();
            }

        }while (choice != 6);
}

