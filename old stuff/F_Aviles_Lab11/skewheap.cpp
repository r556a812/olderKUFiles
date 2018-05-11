/**
*	@file : skewheap.cpp
*	@author :  Richard Aviles
*	@date : 2016.11.10
*       @modified : 2016.11.18
*	Purpose: Creates the skew heap and all its methods
*/


#include "skewheap.h"
#include <iostream>
#include <math.h>
using namespace std;

skewheap::skewheap()
{
    head = nullptr;
}

skewheap::~skewheap()
{
    while(head != nullptr)
    {
        deletemin();
    }
}

void skewheap::insert(int v1, int v2, int e)
{
    Node * temp = new Node();
    temp->setVertex(v1, v2);
    temp->setEdge(e);

    if(head == nullptr)
    {
        head = temp;
    }
    else
    {
        merge(head, temp);
    }
}

Node * skewheap::deletemin()
{
    Node * left;
    Node * right;
    Node * min;

    if (head == nullptr)
    {
        return(nullptr);
    }
    else
    {
        left = head->getLeft();
        right = head->getRight();
        min = head;
        head = merge(left, right);
        return (min);
    }
}

Node * skewheap::merge(Node * a, Node * b)
{
    if(a == nullptr && b == nullptr)
    {
        return(nullptr);
    }
    else if (a == nullptr)
    {
        return b;
    }
    else if (b == nullptr)
    {
        return a;
    }
    else if (a->edge > b->edge)
    {
        if (head == a)
        {
            head = b;
        }

        merge(b, a);
    }
    else if (a->edge <= b->edge)
    {
        Node * swap = a->getRight();
        a->setRight(a->getLeft());
        a->setLeft(swap);

        if (a->getLeft() == nullptr)
        {
            a->setLeft(b);
        }
        else
        {
            a->setLeft(merge(a->getLeft(), b));
        }

        return (a);
    }
}

void skewheap::levelorder(Node * place)
{
    if(head == nullptr)
    {
        return;
    }

    Node * arr[200];
    int index = 0;
    int end = 1;
    arr[0] = place;

    while(index < end)
    {
        Node * temp;
        temp = arr[index];

        if (temp->getLeft()!= nullptr)
        {
            arr[end] = temp->getLeft();
            end++;
        }
        if (temp->getRight() != nullptr)
        {
            arr[end] = temp->getRight();
            end++;
        }

        std::cout << arr[index]->getEdge() << "  ";
        index++;
    }
}

void skewheap::preorder(Node *place)
{
    if (place != nullptr)
    {
        std::cout << place -> getEdge() << " ";
        preorder(place -> getLeft());
        preorder(place -> getRight());
    }
}

void skewheap::inorder(Node *place)
{
    if (place != nullptr)
    {
        inorder(place -> getLeft());
        std::cout << place -> getEdge() << " ";
        inorder(place -> getRight());
    }
}
