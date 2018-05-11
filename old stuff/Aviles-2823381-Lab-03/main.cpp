#include <iostream>
#include <string>
#include <stdexcept>
#include "Node.h"
#include "DoubleLinkedList.h"


using namespace std;

void printMenu()
{
    std::cout <<"\n\nMake Choice\n"
              <<"1) push value onto the front\n"
              <<"2) push value onto the back\n"
              <<"3) insert behind a value\n"
              <<"4) insert ahead of a value\n"
              <<"5) remove front value\n"
              <<"6) remove back value\n"
              <<"7) remove specific value\n"
              <<"8) print list\n"
              <<"9) Quit\n"
              <<"10) Run Tests\n"
              <<"Your choice: ";
}


int main()
{
    DoubleLinkedList<int> myList;
    int end = 0;
    int search = 0;
    int value = 0;
    bool isTrue = false;




    do
    {
        printMenu();
        std::cin >> end;

        if (end == 1)
        {
            std::cout << "You chose: 1\n" << "Give a value: ";
            std::cin >> value;
            myList.pushFront(value);
            std::cout << value << " added to front of the list.";
        }
        else if (end == 2)
        {
            std::cout << "You chose: 2\n" << "Give a value: ";
            std::cin >> value;
            myList.pushBack(value);
            std::cout << value << " added to back of the list.";
        }
        else if (end == 3)
        {
            try
            {
            std::cout << "You chose: 3\n" << "Give a value to insert: ";
            std::cin >> value;
            std::cout << "Pick a value to insert behind: ";
            std::cin >> search;
            std::cout << "Attempting to insert " << value << " behind " << search << "\n";
            myList.insertBehind(search, value);
            std::cout << value << " inserted behind " << search;
            }
            catch (std::runtime_error& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (end == 4)
        {
            try
            {
            std::cout << "You chose: 4\n" << "Give a value to insert: ";
            std::cin >> value;
            std::cout << "Pick a value to insert ahead of:";
            std::cin >> search;
            std::cout << "Attempting to insert " << value << " ahead of " << search << "\n";
            myList.insertAhead(search, value);
            std::cout << value << "inserted ahead of " << search;
            }
            catch (std::runtime_error& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (end == 5)
        {
            std::cout << "You chose: 5\n";
            isTrue = myList.removeFront();
            if (isTrue)
            {
                std::cout << "Front of list removed";
            }
            else
            {
                std::cout << "List empty";
            }
        }
        else if (end == 6)
        {
            std::cout << "You chose: 6\n";
            isTrue = myList.removeBack();
            if (isTrue)
            {
                std::cout << "Back of list removed";
            }
            else
            {
                std::cout << "List empty";
            }
        }
        else if (end == 7)
        {
            std::cout << "You chose: 7\n" << "Give a value to remove: ";
            std::cin >> value;
            std::cout << "You gave " << value << "\n";
            isTrue = myList.remove(value);
            if (isTrue)
            {
                std::cout << value << " removed from list.";
            }
            else
            {
                std::cout << value << " could not be removed from list";
            }
        }
        else if (end == 8)
        {
            std::cout << "You chose: 8\n";
            myList.printList();
        }
        else if (end == 9)
        {
            std::cout <<"You chose: 9\n";
            std::cout <<"\nProgram ending...";
        }
        else if (end == 10)
        {

        }
        else
        {
            std::cout << "Not a valid choice.";
        }

    }while(end !=9);





    return(0);

}

