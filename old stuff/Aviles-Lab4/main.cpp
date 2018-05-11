/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.09.23
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "Node.h"
#include "BST.h"
#include <fstream>
using namespace std;

int main ()
{
    //Declare variables
        int choice = 0;
        BST myBST;
        int numAdd = 0;
        int numDelete = 0;

        //Read the file, data.txt, and put into the List, myList.
        int nums = 0;
        ifstream infile;
        infile.open("data.txt");
        while (infile >> nums)
        {
            myBST.insert(nums);
        }
        infile.close();

        //Loop to ask user what they want to do. Runs until they give choice of 3 to exit.
        do
        {
            std::cout << "Please choose one of the following commands:\n\n"
                         "1- insert\n\n"
                         "2- remove\n\n"
                         "3- deletemin\n\n"
                         "4- deletemax\n\n"
                         "5- preorder\n\n"
                         "6- inorder\n\n"
                         "7- levelorder\n\n"
                         "8- exit\n\n";
            std::cin >> choice;

            //If statements to do what corresponds with the users choice.
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> numAdd;
                myBST.insert(numAdd);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 2)
            {
                std::cout << "\nWhich number do you like to remove from the tree? \n";
                std::cin >> numDelete;
                myBST.remove(numDelete);
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 3)
            {
                myBST.deletemin();
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 4)
            {
                myBST.deletemax();
                std::cout << "\n" << "..............................................................\n\n";
            }
            else if (choice == 5)
            {
                std::cout << "preorder: ";
                myBST.preorder(myBST.m_root);
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if (choice == 6)
            {
                std::cout << "inorder: ";
                myBST.inorder(myBST.m_root);
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if (choice == 7)
            {
                std::cout << "levelorder: ";
                myBST.levelorder(myBST.m_root);
                std::cout << "\n\n" << "..............................................................\n\n";
            }
            else if(choice == 8)
            {
                myBST.~BST();
                std::cout << "\n\n";
            }

        }while (choice != 8);;
}

