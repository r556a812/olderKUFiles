/**
*	@file : Node.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.05
*	Purpose: Creates the methods for the Node class.
*/


#include "Node.h"

template <typename T>
Node<T>::Node()
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = T();

}


template <typename T>
Node<T>::Node(const Node<T> &other)
{
    m_value = other.m_value;
    m_left = nullptr;
    m_right = nullptr;

    if(other.m_left != nullptr)
    {
        m_left = new Node<T>(*(other.m_left));
    }
    if(other.m_right != nullptr)
    {
        m_right = new Node<T>(*(other.m_right));
    }

}


template <typename T>
T Node<T>::getValue()
{
  return (m_value);
}

template <typename T>
Node<T>* Node<T>::getLeft()
{
    return (m_left);
}

template <typename T>
Node<T>* Node<T>::getRight()
{
    return (m_right);
}

template <typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
void Node<T>::setLeft(Node<T> *left)
{
    m_left = left;
}

template <typename T>
void Node<T>::setRight(Node<T> *right)
{
    m_right = right;
}
