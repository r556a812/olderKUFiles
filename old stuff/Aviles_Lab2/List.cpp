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
        Node* search = m_front;
        bool isFound = false;
        if (search->getValue() == x)
        {
            isFound = true;
        }
        while (search->getNext() != nullptr && isFound == false)
        {
            search = search->getNext();
            if (search->getValue() == x)
            {
                isFound = true;
            }
        }

        if (isFound == false)
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

void List::erase(int x)
{
    if (m_front == nullptr)
    {
        return;
    }
    else
    {
        Node* search = m_front;
        while (search->getValue() != x && search->getNext() != nullptr)
        {
            search= search->getNext();
        }

        if (search->getValue() == x)
        {
            if (search == m_front)
            {
                if (m_front->getNext() == nullptr)
                {
                    m_front = nullptr;
                    delete search;
                    search = nullptr;
                }
                else
                {
                    m_front = m_front->getNext();
                    delete search;
                    search = nullptr;
                    erase(x);
                }
            }
            else
            {
                Node* temp = m_front;
                while (temp->getNext() != search)
                {
                    temp = temp->getNext();
                }

                if (search->getNext() == nullptr)
                {
                    temp->setNext(nullptr);
                    delete search;
                    search = nullptr;
                }
                else
                {
                    temp->setNext(search->getNext());
                    delete search;
                    search = nullptr;
                    erase(x);
                }

            }
        }
    }
}

void List::reverse(Node* front, Node* prev)
{
    Node* rest = front;

    if (front->getNext() != nullptr)
    {
        rest = front->getNext();
        reverse(rest, front);
    }

    if (front->getNext() == nullptr)
    {
        m_front = front;
        return;
    }

    while (rest->getNext() != nullptr)
    {
        rest = rest->getNext();
    }

    rest->setNext(front);
    front->setNext(nullptr);
    if(prev != nullptr)
    {
        prev->setNext(rest);
    }
}


void List::concatenate(Node* my1, Node* my2)
{
    while(my1->getNext() != nullptr)
    {
        my1 = my1->getNext();
    }

    if (my2 != nullptr)
    {
        Node* temp = new Node();
        temp->setValue(my2->getValue());
        my1->setNext(temp);
        my2 = my2->getNext();
        concatenate(my1, my2);
    }
}
