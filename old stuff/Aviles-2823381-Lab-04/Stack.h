/**
*	@file : Stack.h
*	@author : Richard Aviles
*	@date : 2015.10.01
	Purpose:  Header file for the Stack class
*/

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
//#include "PreconditionViolationException"

template <typename T>

class Stack:public StackInterface<T>
{
public:
    Stack(); //@pre None @post Creates a Stack that has a pointer and a size @return None
    ~Stack(); //@pre Have to have a Stack to destroy. @post Deletes the Nodes in the stack. @return None
    bool isEmpty() const; //@pre None @post None @return Returns true if stack is empty. Returns false if not empty.
    void push(const T newEntry); //@pre Have to pass in a value to put in. @post Sets the passed in value into the node, changes size by increment of one, sets m_top. @return None
    void pop() throw(PreconditionViolationException); //@pre Stack cannot be empty @post Deletes the top value in the stack @return None
    T peek() const throw(PreconditionViolationException); //@pre Stack cannot be empty @post Shows the value at the top of the list @return Returns the value at the top of the list
    int size() const; //@pre None @post None @return Returns the size of the stack
    void print() const; //@pre None, ideal that stack is not empty. @post Displays all values in the stack @return None
    
private:
    Node<T>* m_top;
    int m_size;
};

#include "Stack.hpp"

#endif
