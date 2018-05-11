/**
*	@file : skewheap.cpp
*	@author :  Richard Aviles
*	@date : 2015.11.10
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

void skewheap::insert(int x)
{
    Node * temp = new Node();
    temp->setValue(x);

    if(head == nullptr)
    {
        head = temp;
    }
    else
    {
        merge(head, temp);
    }
}

void skewheap::deletemin()
{
    Node * left;
    Node * right;
    Node * min;

    if (head == nullptr)
    {
        return;
    }
    else
    {
        left = head->getLeft();
        right = head->getRight();
        min = head;
        head = nullptr;

        delete min;
        min = nullptr;

        head = merge(left, right);
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
    else if (a->m_value > b->m_value)
    {
        Node * temp = a;
        head = b;
        merge(b, temp);
    }
    else if (a->m_value <= b->m_value)
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

        std::cout << arr[index]->getValue() << "  ";
        index++;
    }
}

void skewheap::preorder(Node *place)
{
    if (place != nullptr)
    {
        std::cout << place -> getValue() << " ";
        preorder(place -> getLeft());
        preorder(place -> getRight());
    }
}

void skewheap::inorder(Node *place)
{
    if (place != nullptr)
    {
        inorder(place -> getLeft());
        std::cout << place -> getValue() << " ";
        inorder(place -> getRight());
    }
}
