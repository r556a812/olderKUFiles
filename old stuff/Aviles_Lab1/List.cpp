/**
*	@file : List.cpp
*	@author :  Richard Aviles
*	@date : 2015.08.26
*	Purpose: Creates the List and has methods to insert a number into the list and print out the list.
*/



#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>

List::List()
{
    m_front = nullptr;
}

List::~List()
{
    while(m_front -> getNext() != nullptr)
    {
        Node* temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        temp = nullptr;
    }
}

void List::insert(int x)
{
    if (m_front == nullptr)
    {
        m_front = new Node();
        m_front -> setValue(x);
    }
    else
    {
        Node* last = m_front;
        while (last->getNext() != nullptr)
        {
            last = last->getNext();
        }
        Node* temp = new Node();
        temp->setValue(x);
        last->setNext(temp);
    }
}

void List::print()
{
    Node* place = m_front;

    while (place != nullptr)
    {
        std::cout << place -> getValue() << " ";
        place = place -> getNext();
    }

    std::cout << "\n\n..........................................................\n\n";
}
