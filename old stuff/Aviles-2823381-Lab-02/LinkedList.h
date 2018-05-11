/**
*	@file : LinkedList.h
*	@author : Richard Aviles
*	@date : 2018.09.17
	Purpose: Header file for the linked list class. Creates a linked list that adds onto it Nodes with provided values.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
#include "Node.h"

class LinkedList
{
    public:
        LinkedList(); //@pre None @post Creates a constructor for Linked List with default values @return None
        ~LinkedList(); //@pre None @post Destroyer of elements in the linked list. @return None
        bool isEmpty() const;  //@pre None @post determines whether a linked list is empty of not @return Returns a boolean, true if empty, false if not
        int size() const; //@pre None @post Tells how big the linked list is. @return Returns a int that is the size of the linked list.
        bool search(int value) const; //@pre have to pass in an int for the method to search for. @post It searches through the linked list to see if the given int is inside the linked list. @return Returns a boolean, true if the int is in the list, false if the int is not in the linked list.
        void printList() const; //@pre None @post It displays to the user the values in the linked list. @return None
        void addBack(int value); //@pre Have to pass in an int @post Creates a new node at the back of the linked list with the given value passed in. @return None
        void addFront(int value); //@pre Have to pass in an int @post Creates a new node at the front of the linked list with the given value passed in. @return None
        bool removeBack(); //@pre None @post Will remove the last element in the linked list if there is one. @return Returns boolean, true if there was something to remove, false if the linked list was empty.
        bool removeFront(); //@pre None @post Will remove the first element in the linked list if there is one @return Returns boolean, true if there was something to remove, false if the list was empty.
        
    private:
        Node* m_front; 
        int m_size;
        
        
};

#endif
    
        
    
    