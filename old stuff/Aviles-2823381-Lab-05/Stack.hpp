/**
*	@file : Stack.hpp
*	@author :  Richard Aviles
*	@date : 2015.10.08
*	Purpose: Creates the methods for the Stack class.
*/

#include "Stack.h"
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include <iostream>

template <typename T>
Stack<T>::Stack()
{
    m_top = nullptr;
    m_size = 0;
}


template <typename T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}


template <typename T>
bool Stack<T>::isEmpty() const
{
    if (m_size == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
    Node<T>* temp = nullptr;

    if (isEmpty())
    {
        m_top = new Node<T>();
        m_top -> setValue(newEntry);
        m_size++;
    }
    else
    {
        temp = new Node<T>();
        temp -> setValue(newEntry);
        temp -> setNext(m_top);
        m_top = temp;
        m_size++;
    }
}


template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
    if (!isEmpty())
    {
    Node<T>* temp = m_top;
    m_top = m_top -> getNext();
    delete temp;
    temp = nullptr;
    m_size--;
    }
   else
    {
        throw(PreconditionViolationException("Error"));
    }
}


template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
    if (!isEmpty())
    {
    return (m_top -> getValue());
    }
  else
    {
        throw(PreconditionViolationException("Stack is Empty"));
    }
}

template <typename T>
int Stack<T>::size() const
{
    return (m_size);
}


template <typename T>
void Stack<T>::print() const
{
    Node<T>* temp = m_top;
    if (m_size == 0)
    {
        std::cout << "Empty Stack";
    }
    else if (m_size == 1)
    {
        std::cout << peek();
    }
    else
    {
        std::cout << temp -> getValue() << " ";
        while (temp -> getNext() != nullptr)
        {
            temp = temp -> getNext();
            std::cout << temp -> getValue() << " ";
        }
    }
}

