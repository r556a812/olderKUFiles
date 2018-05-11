#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include <string>

using namespace std;



int main()
{

    LinkedList<int> myList;
     bool checkEmpty = false; //Tried with both false and true to make sure isEmpty worked correctly.
     bool findNumber = false;
     Node<int> myNode(10);
     int mySize = 0;


     std::cout << "Checking the list after creation: \n";
     mySize = myList.size();
     checkEmpty = myList.isEmpty();
     if (checkEmpty == false){
         std::cout << "Not Empty, Size: " << mySize << "\n";
     }
     else if (checkEmpty == true) {
         std::cout << "Is Empty, Size: " << mySize << "\n"; //Says it is not empty and that size is 1 when should be empty and size 0
     }





     std::cout << "\n\nChecking the list after adding 10 values to the front: \n";
     mySize = myList.size();
     for (int i = 0; i < 10; i++) { // Knows that is not empty, and shows size is 1 more than should be, due to the start of size at 1 on initiation.
         myList.addFront(i);
         mySize = myList.size();
         checkEmpty = myList.isEmpty();
         if (checkEmpty == false){
             std::cout << "Not Empty, Size: " << mySize << "\n";
         }
         else if (checkEmpty == true) {
             std::cout << "Is Empty, Size: " << mySize << "\n";
         }
     }




     std::cout << "\n\nChecking that all the values added are in the list: \n";
     for (int j = 0; j < 10; j++) { // Shows true for all known values in the list
         findNumber = myList.search(j);
         if (findNumber == false) {
             std::cout << "Could not find value: " << j << " in the list" <<  "\n";
         }
         else if (findNumber == true) {
             std::cout << "Value: " << j << " found" << "\n";
         }
     }




     std::cout << "\n\nChecking the order of the list: ";
     std::vector<int> myVector = myList.toVector();
     std::cout << "\nList contains: ";
     for (int i = 0; i < myVector.size(); i++) { //Prints out all values added, except in reverse.  Therefore addFront really adds to the back.
         std::cout << myVector [i] << " ";
     }
     std::cout << "\nList should contain: ";
     for (int i = 0; i < 10; i++) {
         std::cout << i << " ";
     }




     std::cout << "\n\nChecking list after removing from the Front: ";
     myList.removeFront();//Removes from the back instead of the front
     myList.removeFront();
     myList.removeFront();

     myVector = myList.toVector();
     std::cout << "\n";
     std::cout << "List contains: ";
     for (int i = 0; i < myVector.size(); i++) {
         std::cout << myVector [i] << " ";
     }
     std::cout << "\nList should contain: ";
     for (int i = 6; i >= 0; i--) {
         std::cout << i << " ";
     }


     std::cout << "\n\nDeleting old list... ";
     for (int i = 0; i < 7; i++) {
         myList.removeFront();
     }

     std::cout << "\nList now contains: ";
     for (int i = 0; i < 10; i++) {
         myList.addFront(i);
     }
     myVector = myList.toVector();
     for (int i = 0; i < myVector.size(); i++) {
         std::cout << myVector [i] << " ";
     }






     std::cout << "\n\nChecking list after removing from the Back: ";
     myList.removeBack();//Works, removes from the back like intended.
     myList.removeBack();
     myList.removeBack();

     myVector = myList.toVector();
     std::cout << "\nList contains: ";
     for (int i = 0; i < myVector.size(); i++) {
         std::cout << myVector [i] << " ";
     }
     std::cout << "\nList should contain: ";
     for (int i = 9; i > 2; i--) {
         std::cout << i << " ";
     }




     std::cout << "\n\nChecking list after Adding to the Back: ";
     std::cout << "\nList contains: ";
     for (int i = 2; i >= 0; i--){ //No matter what you pass into addBack, it inserts the number 9. (Tried with different values other than i)
         myList.addBack(i);
     }
     myVector = myList.toVector();
     for (int i = 0; i < myVector.size(); i++) {
         std::cout << myVector [i] << " ";
     }
     std::cout << "\nList should contain: ";
     for (int i = 9; i >= 0; i--) {
         std::cout << i << " ";
     }










    return(0);
}

