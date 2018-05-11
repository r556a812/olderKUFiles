/**
*	@file : Node.cpp
*	@author :  Richard Aviles
*	@date : 2015.08.26
*	Purpose: Creates the Node and its set and get methods.
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

void Node::setNext(Node* next)
{
    m_next = next;

}

Node* Node::getNext() const
{
    return(m_next);
}


