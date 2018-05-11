#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Test.h"
#include <string>

using namespace std;

int main()
{
    LinkedList myList;
    int choice = 0;
    int value = 0;
    bool remove = false;
    int search = 0;
    bool found = false;

    do
    {
         std::cout << "Select from the following menu:\n1) Add to the front of the list\n2) Add to the end of the list\n3) Remove from front of the list\n4) Remove from back of the list\n5) Print the list\n6) Search for value\n7) Exit\n8) Run tests\nEnter your choice: You choose: ";
         std::cin >> choice;

        if(choice < 1)
        {
            std::cout << "Invalid choice.";
        }
        if(choice > 8)
        {
            std::cout << "Invalid choice.";
        }
        if(choice == 1)
        {
            std::cout << "Input a value to add: ";
            std::cin >> value;
            std::cout << "Adding " << value << " to the list\n\n";
            myList.addFront(value);
        }
        if(choice == 2)
        {
            std::cout << "Input a value to add: ";
            std::cin >> value;
            std::cout << "Adding " << value << " to the list\n\n";
            myList.addBack(value);
        }
        if(choice == 3)
        {
            std::cout << "Attempting removal from front of list.";
            remove = myList.removeFront();
            if (remove == false)
            {
                std::cout << "There are no values to remove\n\n";
            }
            else
            {
                std::cout << "Removal successful\n\n";
            }
        }
        if(choice == 4)
        {
            std::cout << "Attempting removal from back of list.";
            remove = myList.removeBack();
            if (remove == false)
            {
                std::cout << "There are no values to remove\n\n";
            }
            else
            {
                std::cout << "Removal successful\n\n";
            }
        }
        if(choice == 5)
        {
            std::cout << "Printing list:\n";
            myList.printList();
            std::cout << "\n\n";
        }
        if(choice == 6)
        {
            std::cout << "Enter a value to search for: ";
            std::cin >> search;
            std::cout << "Searching for " << search <<"...\n";
            found = myList.search(search);

            if(found == false)
            {
                std::cout << search << " is not in the list.\n\n";
            }
            else
            {
                std::cout << search << " is in the list.\n\n";
            }
        }
        if(choice == 8)
        {
            Test myTester(std::cout);
            myTester.runTests();
        }

    }while(choice!=7);



    return(0);
}
