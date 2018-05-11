/**
*	@file : leftistheap.cpp
*	@author :  Richard Aviles
*	@date : 2015.11.10
*	Purpose: Creates the leftist heap and all its methods
*/


#include "leftistheap.h"
#include "Node.h"
#include <iostream>
#include <math.h>
using namespace std;

leftistheap::leftistheap()
{
    head = nullptr;
}
leftistheap::~leftistheap()
{
    while(head != nullptr)
    {
        deletemin();
    }
}

void leftistheap::insert(int x)
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

void leftistheap::deletemin()
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

Node * leftistheap::merge(Node *a, Node *b)
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
        if (a->getRight() == nullptr)
        {
            a->setRight(b);
        }
        else
        {
            a->setRight(merge(a->getRight(), b));
        }

        if (a->getLeft() == nullptr && a->getRight() != nullptr)
        {
            a->setLeft(a->getRight());
            a->setRight(nullptr);
            Node *temp = a->getRight();
            delete temp;
            temp = nullptr;
        }
        else if(a->getLeft()->getRank() < a->getRight()->getRank())
        {
            Node * temp = a->getLeft();
            Node * temp2 = a->getRight();
            a->setLeft(temp2);
            a->setRight(temp);
        }

        setRank(a);

        return (a);
    }

}


void leftistheap::setRank(Node *place)
{
    if (place->getRight() != nullptr && place->getLeft() != nullptr)
    {
        place->setRank(place->getRight()->getRank() + 1);
    }
}

void leftistheap::levelorder(Node * place)
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

void leftistheap::preorder(Node * place)
{
    if (place != nullptr)
    {
        std::cout << place -> getValue() << " ";
        preorder(place -> getLeft());
        preorder(place -> getRight());
    }
}

void leftistheap::inorder(Node *place)
{
    if (place != nullptr)
    {
        inorder(place -> getLeft());
        std::cout << place -> getValue() << " ";
        inorder(place -> getRight());
    }
}
