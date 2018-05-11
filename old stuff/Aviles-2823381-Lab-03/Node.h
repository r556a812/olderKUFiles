/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.09.24
	Purpose:  
*/

#ifndef NODE_H
#define NODE_H

template <typename T>

class Node
{
public:
    Node();
    void setValue(T value);
    T getValue() const;
    void setNext(Node<T>* next);
    Node<T>* getNext();
    void setPrevious(Node<T>* prev);
    Node<T>* getPrevious();
    
    
    
private:
    T m_value;
    Node<T>* m_previous;
    Node<T>* m_next;

    
};

#include "Node.hpp"

#endif