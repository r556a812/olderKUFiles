/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.11.05
	Purpose:  The header file for the Node class. Creates a Node that consist of a pointer and a value to hold in it.
*/

#ifndef NODE_H
#define NODE_H

template <typename T>

class Node
{
public:
    Node(); //@pre none @post creates a constuctor for the node class. Sets m_left and m_right to nullptr, and m_value to T() (default T value) @return none
    Node(const Node<T>& other); //@pre have to pass in a valid Node @post creates a copy of the Node and its branches @return none
    T getValue();   //@pre none @post none @return Returns the value, m_value.
    Node<T>* getLeft(); //@pre none @post none @return returns the pointer, m_left
    Node<T>* getRight();    //@pre none @post none @return returns the pointer, m_right
    void setValue(T value); //@pre have to pass in a valid value @post sets the given value to m_value @return none
    void setLeft(Node<T>* left);    //@pre have to pass in the node pointer m_left of the node @post sets the next node for the left side, m_left @return none
    void setRight(Node<T>* right);  //@pre have to pass in the node pointer m_right of the node @post sets the next node for the right side, m_right @return none
    
private:
    Node<T>* m_left;
    Node<T>* m_right;
    T m_value;
    
};

#include "Node.hpp"

#endif
