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
    m_left = nullptr;
    m_right = nullptr;
    rank = 1;
}

void Node::setValue(int value)
{
    m_value = value;
}

int Node::getValue() const
{
    return(m_value);
}

void Node::setLeft(Node* left)
{
    m_left = left;

}

void Node::setRight(Node* right)
{
    m_right = right;

}

Node* Node::getLeft() const
{
    return(m_left);
}

Node* Node::getRight() const
{
    return(m_right);
}

void Node::setRank(int a)
{
    rank = a;
}

int Node::getRank()
{
    return(rank);
}


