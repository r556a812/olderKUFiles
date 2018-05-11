/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.09.17
	Purpose: Header file for the Node class. Creates a Node that consist of a value and a pointer. 
*/

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node(); //@pre None @post Constructor for the node that sets the pointer to nullptr and the value to 0. @return None
        void setValue(int value); //@pre Have to pass in an int. @post Sets the value of the node to given value. @return None
        int getValue() const; //@pre None @post Gives the value inside the node. @return Returns the int that is stored in the node. If no value has been given it return default value 0.
        void setNext(Node* prev); //@pre Have to pass in a node pointer. @post Sets the node given as the next node in the list. @return None
        Node* getNext() const; //@pre Have to have a node next in the list. @post Faces the pointer to the next node in the list. @return Returns the pointer that is next in the list.
        
    private:
        int m_value;
        Node* m_next;
        
};

#endif
    
    