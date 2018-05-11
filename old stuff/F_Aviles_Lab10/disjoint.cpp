/**
*	@file : disjoint.cpp
*	@author :  Richard Aviles
*	@date : 2016.11.18
*	Purpose: Creates the disjoint set and all its methods
*/


#include "disjoint.h"
#include "Node.h"
#include <iostream>
using namespace std;


disjoint::disjoint(int size)
{
    m_size = size;

    disSet = new Node*[size];
    for (int i = 0; i < size; i++)
    {
        Node* temp = new Node();
        temp->setEdge(i);
        disSet[i] = temp;
    }
}

int disjoint::find(int v)
{
    Node * temp = nullptr;

    for (int i = 0; i < m_size; i++)
    {
        if (disSet[i] -> getEdge() == v)
        {
            temp = disSet[i];
            break;
        }
    }

    return (findParent(temp));
}

int disjoint::findParent(Node* v)
{
    if(v->getParent() == nullptr)
    {
        return v->getEdge();
    }
    else
    {
        return (findParent(v->getParent()));
    }
}

void disjoint::merge(int v1, int v2)
{
    Node* temp1 = disSet[find(v1)];
    Node* temp2 = disSet[find(v2)];

    if (v1 < v2)
    {
        temp2 -> setParent(temp1);
    }
    else
    {
        temp1 -> setParent(temp2);
    }
}
