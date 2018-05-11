/**
*	@file : BinarySearchTree.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.05
*	Purpose:
*/


#include "BinarySearchTree.h"
#include "Node.h"


template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &other)
{
    if (other.m_root == nullptr)
    {
        m_root = nullptr;
    }
    else
    {
        m_root = new Node<T>(*(other.m_root));
    }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteTree (m_root);
}


template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
    BSTI<T>* copy = new BinarySearchTree(*(this));
    return(copy);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    if (m_root == nullptr)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


template <typename T>
bool BinarySearchTree<T>::add(T value)
{
    bool a = false;

    if (isEmpty())
    {
        m_root = new Node<T>();
        m_root -> setValue(value);
        return(true);
    }
    else
    {
        a = add(value, m_root);
        return(a);
    }
}


template <typename T>
bool BinarySearchTree<T>::search(T value) const
{
  return (search(value, m_root));
}


template <typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
    if (m_root == nullptr)
    {
        std::cout << "Tree does not exist";
    }
    else
    {
        printTree(m_root, order);
    }
}


template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
    std::vector<T> vec;
    treeToVector(m_root, order, vec);
    return (vec);
}



template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T> *subtree)
{
    bool a;

    if (subtree -> getValue() == value)
    {
        return (false);
    }
    else if (subtree -> getValue() > value)
    {
       Node<T>* temp = subtree -> getLeft();

        if (temp == nullptr)
        {
            temp = new Node<T>();
            temp -> setValue(value);
            subtree -> setLeft(temp);
            return(true);
        }
        else
        {
            a = add(value, temp);
            return(a);
        }
    }
    else if (subtree -> getValue() < value)
    {
        Node<T>* temp = subtree -> getRight();

        if (temp == nullptr)
        {
            temp = new Node<T>();
            temp -> setValue(value);
            subtree -> setRight(temp);
            return(true);
        }
        else
        {
            a = add(value, temp);
            return(a);
        }
    }

}


template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T> *subtree)
{
    if (subtree == nullptr)
    {
        return;
    }
    else
    {
        if (subtree -> getLeft() != nullptr)
        {
            delete (subtree -> getLeft());
        }
        if (subtree -> getRight() != nullptr)
        {
            delete (subtree -> getRight());
        }
        delete subtree;
        return;
    }
}


template <typename T>
bool BinarySearchTree<T>::search(T value, Node<T> *subtree) const
{
    if (subtree == nullptr)
    {
        return(false);
    }
    else if (value == subtree -> getValue())
    {
        return(true);
    }
    else if (value < subtree -> getValue() && subtree -> getLeft() != nullptr)
    {
        search(value, subtree -> getLeft());
    }
    else if (value > subtree -> getValue() && subtree -> getRight() != nullptr)
    {
        search(value, subtree -> getRight());
    }
    else
    {
        return (false);
    }
}



template <typename T>
void BinarySearchTree<T>::printTree(Node<T> *subtree, Order order) const
{
    if (order == IN_ORDER)
    {
        if (subtree != nullptr)
        {
            if (subtree -> getLeft() != nullptr)
            {
                printTree(subtree -> getLeft(), order);
            }

            std::cout << subtree -> getValue() << " ";

            if (subtree -> getRight() != nullptr)
            {
                printTree(subtree -> getRight(), order);
            }
        }
        else
        {
            return;
        }
    }
    else if (order == PRE_ORDER)
    {
        if (subtree != nullptr)
        {
            std::cout << subtree -> getValue() << " ";

            if (subtree -> getLeft() != nullptr)
            {
                printTree(subtree -> getLeft(), order);
            }
            if (subtree -> getRight() != nullptr)
            {
                printTree(subtree -> getRight(), order);
            }
        }
        else
        {
            return;
        }
    }
    else if (order == POST_ORDER)
    {
        if (subtree != nullptr)
        {
            if (subtree -> getLeft() != nullptr)
            {
                printTree(subtree -> getLeft(), order);
            }
            if (subtree -> getRight() != nullptr)
            {
                printTree(subtree -> getRight(), order);
            }

            std::cout << subtree -> getValue() << " ";
        }
        else
        {
            return;
        }
    }
}

template <typename T>
void BinarySearchTree<T>::treeToVector(Node<T> *subtree, Order order, std::vector<T> &vec) const
{
    if (subtree != nullptr)
    {
        if (order == PRE_ORDER)
        {
            vec.push_back(subtree -> getValue());
            treeToVector(subtree -> getLeft(), order, vec);
            treeToVector(subtree -> getRight(), order, vec);
        }
        else if (order == IN_ORDER)
        {
            treeToVector(subtree -> getLeft(), order, vec);
            vec.push_back(subtree -> getValue());
            treeToVector(subtree -> getRight(), order, vec);
        }
        else if (order == POST_ORDER)
        {
            treeToVector(subtree -> getLeft(), order, vec);
            treeToVector(subtree -> getRight(), order, vec);
            vec.push_back(subtree -> getValue());
        }
    }
}

