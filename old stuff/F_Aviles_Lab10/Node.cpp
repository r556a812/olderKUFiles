/**
*	@file : Node.cpp
*	@author :  Richard Aviles
*	@date : 2016.08.26
*       @modified : 2016.11.18
*	Purpose: Creates the Node and its set and get methods.
*/


#include "Node.h"


Node::Node()
{
    vertex1 = 0;
    vertex2 = 0;
    edge = 0;
    m_left = nullptr;
    m_right = nullptr;
    m_parent = nullptr;
}

void Node::setVertex(int v1, int v2)
{
    vertex1 = v1;
    vertex2 = v2;
}

void Node::setEdge(int e)
{
    edge = e;
}

int Node::getV1() const
{
    return(vertex1);
}

int Node::getV2() const
{
    return(vertex2);
}

int Node::getEdge() const
{
    return(edge);
}

void Node::setLeft(Node* left)
{
    m_left = left;

}

void Node::setRight(Node* right)
{
    m_right = right;

}

void Node::setParent(Node *parent)
{
    m_parent = parent;
}

Node* Node::getLeft() const
{
    return(m_left);
}

Node* Node::getRight() const
{
    return(m_right);
}

Node* Node::getParent() const
{
    return(m_parent);
}



