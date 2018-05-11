/**
*	@file : DoubleLinkedList.h
*	@author : Richard Aviles
*	@date : 2015.09.24
	Purpose:  
*/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.h"

template <typename T>

class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool isEmpty() const;
    int size() const;
    void pushFront(T value);
    void pushBack(T value);
    bool removeFront();
    bool removeBack();
    bool remove(T value);
    void insertAhead(T listValue, T newValue) throw (std::runtime_error);
    void insertBehind(T listValue, T newValue) throw (std::runtime_error);
    Node<T>* find(T value) const;
    void printList() const;
    
private:
    Node<T>* m_front;
    Node<T>* m_back;
    int m_size;
    
    
};

#include "DoubleLinkedList.hpp"

#endif
    