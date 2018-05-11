/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.10.08
	Purpose:  The header file for the Node class. Creates a Node that consist of a pointer and a value to hold in it.
*/

#ifndef NODE_H
#define NODE_H

template <typename T>

class Node
{
public:
    Node(); //@pre None @post Constructor for the node that sets the pointer to nullptr and the value to 0. @return None
    void setValue(T value); //@pre Have to pass in a value. Can be any value since is a template. @post Sets the value of the node to given value. @return None
    T getValue() const; //@pre None @post Gives the value inside the node. @return Returns the value that is stored in the node. If no value has been given it return default value 0.
    void setNext(Node<T>* next); //@pre Have to pass in a node pointer. @post Sets the node given as the next node in the list. @return None
    Node<T>* getNext(); //@pre Have to have a node next in the list. @post Faces the pointer to the next node in the list. @return Returns the pointer that is next in the list.
    
    
    
private:
    T m_value;
    Node<T>* m_next;

    
};

#include "Node.hpp"

#endif 
