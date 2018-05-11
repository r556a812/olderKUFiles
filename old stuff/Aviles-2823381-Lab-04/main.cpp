/**
*	@file : main.cpp
*	@author : Richard Aviles
*	@date : 2015.10.01
        Purpose: Main class to interact with the Stack and the user.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "Node.h"
#include "StackInterface.h"
#include "Test.h"

void printMenu()
{
    std::cout << "\n\nSelect an action\n"
              << "1) Add to stack 1\n"
              << "2) See what is at the top of stack\n"
              << "3) Print all stack\n"
              << "4) Pop stack\n"
              << "5) Quit\n"
              << "6) Run Tests\n"
              << "Enter choice: ";

}


int main()
{
    int choice = 0;\
    Stack<int> myStack;
    int value = 0;

    do
    {


    choice = 0;
    value = 0;

    printMenu();
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "You chose: " << choice << "\n";
        std::cout << "What is going in stack 1?: ";
        std::cin >> value;
        myStack.push(value);
        std::cout << value << " successfully added to stack 1";
    }
    else if (choice == 2)
    {
        bool empty = myStack.isEmpty();

        myStack.peek();

        if (!empty)
        {
            std::cout << myStack.peek() << " is at the top of stack 1";
        }
    }
    else if (choice == 3)
    {
        myStack.print();
    }
    else if (choice == 4)
    {
        bool empty = myStack.isEmpty();

        if (!empty)
        {
            std::cout << myStack.peek() << " removed from stack 1";
            myStack.pop();
        }
        else
        {
            myStack.pop();
        }
    }
    else if (choice == 5)
    {
        std::cout << "You chose: " << choice << "\n" << "Program Ending...";
    }
    else if(choice == 6)
    {
        Test(myStack());
    }
    else
    {
        std::cout << "Please enter a valid input";
    }


    }while (choice != 5);


    return (0);

}
