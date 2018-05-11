/**
*	@file : List.h
*	@author : Richard Aviles
*	@date : 2016.08.26
	Purpose: The header file for List.
*/

#ifndef LIST_H
#define LIST_H 
#include "Node.h"

class List
{
    public:
        List(); //@pre None @post Creates a constructor for List with m_front pointing to nullptr @return None
        ~List(); //@pre None @post Deletes the List @return None
        void insert(int x); //@pre Have to send in a number @post Inserts the number provided into the back of the List @return None
        void print(); //@pre None @post Displays to the user the numbers in the List @return None
        Node* m_front; //@pre None @post None @return None
};

#endif
