/**
*	@file : Node.hpp
*	@author :  Richard Aviles
*	@date : 2015.09.24
*	Purpose:
*/


#include "Node.h"

template <typename T>
Node<T>::Node()
{
    m_next = nullptr;
    m_previous = nullptr;
    m_value = T();
}


template <typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}


template <typename T>
T Node<T>::getValue() const
{
    return(m_value);
}


template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}


template <typename T>
Node<T>* Node<T>::getNext()
{
    return (m_next);
}


template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
    m_previous = prev;
}


template <typename T>
Node<T>* Node<T>::getPrevious()
{
    return (m_previous);
}
