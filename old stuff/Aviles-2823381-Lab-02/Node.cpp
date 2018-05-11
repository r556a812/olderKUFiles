/**
*	@file : Node.cpp
*	@author :  Richard Aviles
*	@date : 2015.09.17
*	Purpose: To implement the Node class. Makes a constructor, and has methods to input a value, get to the next node, set a node next after it, and return the value in the node if it has one.
*/


#include "Node.h"


Node::Node()
{
    m_value = 0;
    m_next = nullptr;
}

void Node::setValue(int value)
{
    m_value = value;
}

int Node::getValue() const
{
    return(m_value);
}

void Node::setNext(Node* prev)
{
    m_next = prev;

}

Node* Node::getNext() const
{
    return(m_next);
}

