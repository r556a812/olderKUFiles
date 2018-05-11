/**
*	@file : StackInterface.h
*	@author : Richard Aviles
*	@date : 2015.10.01
	Purpose: Header file for the StackInterface class. Entries are pure virtual, making this the base class to be inherited by other classes.
*/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include "PreconditionViolationException.h"

template <typename T>

class StackInterface // @pre All methods must be used in the inherited class. @post None @return None
{ 
public:
    virtual ~StackInterface() {}; 
    virtual bool isEmpty() const = 0; //@pre Must be used in inherited class @post None @return Return a boolean
    virtual void push(const T newEntry) = 0; //@pre Must be used in inherited class and take in a value for T @post None @return None
    virtual void pop() throw(PreconditionViolationException) = 0; //@pre Must be used in inherited class @post None @return None
    virtual T peek() const throw(PreconditionViolationException) = 0; //@pre Must be used in inherited class @post has to give back a value T @return Return back a value T
    virtual int size() const = 0; //@pre Must be used in inherited class @post None @return Return an int, preferably the size.
    virtual void print() const = 0; //@pre Must be used in inherited class @post None @return Ideally prints the values.
};

#endif