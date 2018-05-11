/**
*	@file : LinkedList.cpp
*	@author :  Richard Aviles
*	@date : 2015.09.17
*	Purpose: To implement the LinkedList class. Starts a linked list to add nodes to. Has methods to check for the amount, add and delete from the front and the back.
*/



#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;


LinkedList::LinkedList()
{
    m_front = nullptr;
    m_size = 0;
}

LinkedList::~LinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
}


bool LinkedList::isEmpty() const
{
    if (m_size==0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int LinkedList::size() const
{
    return (m_size);
}

bool LinkedList::search(int value) const
{
    Node* search = m_front;
    bool isThere = false;

    if (isEmpty())
    {
        return (false);
    }
    else if (search->getValue() == value)
    {
         isThere = true;
    }
    else
    {
        while(search->getNext() != nullptr)
        {
           search = search->getNext();
           if (search->getValue() == value)
           {
               isThere = true;
           }
        }


     }
    search->getNext();
    return (isThere);
}

void LinkedList::printList() const
{
    if (isEmpty())
    {
        std::cout << "";
    }
    else
    {
        Node* last = m_front;

        while(last != nullptr)
        {
            std::cout << last->getValue() << " ";
            last = last->getNext();
        }

    }
}

void LinkedList::addBack(int value)
{
    Node* temp = nullptr;
    Node* last = nullptr;

    if (isEmpty())
    {
        m_front = new Node();
        m_front->setValue(value);
        m_size++;
    }
    else
    {
        last = m_front;
        while (last->getNext() != nullptr)
        {
            last = last->getNext();
        }
        temp = new Node();
        temp->setValue(value);
        last->setNext(temp);
        m_size++;

    }

}

void LinkedList::addFront(int value)
{
    Node* temp = nullptr;

    if (isEmpty())
    {
        m_front = new Node();
        m_front -> setValue(value);
        m_size++;
    }
    else
    {
        temp = new Node();
        temp -> setValue(value);
        temp ->setNext(m_front);
        m_front = temp;
        m_size++;
    }

}

bool LinkedList::removeFront()
{
    if (isEmpty())
    {
        return(false);
    }
    else
    {
        Node* temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        temp = nullptr;
        m_size--;
        return(true);
    }
}

bool LinkedList::removeBack()
{
    if (isEmpty())
    {
        return (false);
    }
    else
    {
        Node* last = nullptr;
        last = m_front;

        while (last->getNext() != nullptr)
        {
            last = last->getNext();
        }
        delete last;
        last = nullptr;
        m_size--;
        return (true);

    }
}

