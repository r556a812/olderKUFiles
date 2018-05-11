/**
*	@file : BST.cpp
*	@author :  Richard Aviles
*	@date : 2015.09.23
*	Purpose: Creates the Binary Search Tree and all its methods
*/


#include "BST.h"
using namespace std;

BST::BST()
{
    m_root = nullptr;
    size = 0;
}

BST::~BST()
{
    while(size != 0)
    {
        deletemin();
    }
}


void BST::insert(int num)
{
    if (m_root == nullptr)
    {
        m_root = new Node();
        m_root -> setValue(num);
        size++;
    }
    else
    {
        findInsert(num, m_root);
    }
}

void BST::findInsert(int num, Node *subtree)
{
    /*if (subtree -> getValue() == num)
    {
        std::cout << "Could not insert, Value already exist";
        return;
    }
    else*/ if (subtree -> getValue() > num)
    {
        if (subtree -> getLeft() == nullptr)
        {
            Node* temp = nullptr;
            temp = new Node();
            temp -> setValue(num);
            subtree -> setLeft(temp);
            size++;
        }
        else
        {
            /*Node* temp = nullptr;
            temp = subtree;
            temp = temp -> getLeft();*/

            subtree = subtree -> getLeft();
            findInsert(num, subtree);
        }
    }
    else if (subtree -> getValue() <= num)
    {
        if (subtree -> getRight() == nullptr)
        {
            Node* temp = nullptr;
            temp = new Node();
            temp -> setValue(num);
            subtree -> setRight(temp);
            size++;
        }
        else
        {
            /*Node* temp = nullptr;
            temp = subtree;
            temp = temp -> getRight();*/

            subtree = subtree -> getRight();
            findInsert(num, subtree);
        }
    }
}

void BST::remove(int num)
{
    if (m_root == nullptr)
    {
        //std::cout << "Nothing to delete";
    }
    else if (search(num, m_root) == nullptr)
    {
        //std::cout << "Cannot delete, number not in the tree.";
    }
    else
    {
        while(search(num, m_root) != nullptr)
        {
            findRemove(num, m_root, nullptr);
        }
    }
}

void BST::findRemove(int num, Node *subtree, Node* parent)
{
    if (subtree -> getValue() == num)
    {
        if (subtree -> getRight() == nullptr && subtree -> getLeft() == nullptr)
        {
            if(parent -> getRight() == subtree)
            {
                parent -> setRight(nullptr);
            }
            else
            {
                parent -> setLeft(nullptr);
            }

            delete subtree;
            subtree = nullptr;
            size--;
        }
        else if (subtree -> getLeft() == nullptr)
        {
            Node* temp = nullptr;
            temp = subtree;
            subtree = subtree -> getRight();
            if (parent != nullptr)
            {
                if (parent -> getLeft() == temp)
                {
                    parent -> setLeft(subtree);
                }
                else
                {
                    parent -> setRight(subtree);
                }
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (subtree -> getRight() == nullptr)
        {
            Node* temp = nullptr;
            temp = subtree;
            subtree = subtree -> getLeft();
            if (parent != nullptr)
            {
                if (parent -> getLeft() == temp)
                {
                    parent -> setLeft(subtree);
                }
                else
                {
                    parent -> setRight(subtree);
                }

            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp = nullptr;
            temp = subtree -> getRight();
            while (temp -> getLeft() != nullptr)
            {
                temp = temp -> getLeft();
            }
            int change = temp -> getValue();

            if (temp -> getRight() != nullptr)
            {
                if (subtree -> getRight() == temp)
                {
                    subtree -> setRight(temp -> getRight());
                    delete temp;
                    temp = nullptr;
                }
                else
                {
                    Node* temp2 = nullptr;
                    temp2 = subtree -> getRight();
                    while (temp2 -> getLeft() != temp)
                    {
                        temp2 = temp2 -> getLeft();
                    }
                    temp2 -> setLeft(temp -> getRight());
                    delete temp;
                    temp = nullptr;
                }

                subtree -> setValue(change);
                size--;
            }
            else
            {
                Node* temp2 = nullptr;
                temp2 = subtree -> getRight();
                while (temp2 -> getLeft() != temp)
                {
                    temp2 = temp2 -> getLeft();
                }
                temp2 -> setLeft(nullptr);
                delete temp;
                temp = nullptr;
                subtree -> setValue(change);
                size--;
            }
        }
    }
    else if (subtree -> getValue() > num)
    {
        findRemove(num, subtree -> getLeft(), subtree);
    }
    else if (subtree -> getValue() < num)
    {
        findRemove(num, subtree -> getRight(), subtree);
    }
}

Node* BST::search(int num, Node* subtree)
{
    if (subtree == nullptr)
    {
        return (subtree);
    }
    else if (subtree -> getValue() == num)
    {
        return (subtree);
    }
    else if (subtree -> getValue() > num)
    {
        search(num, subtree -> getLeft());
    }
    else if (subtree -> getValue() < num)
    {
        search(num, subtree -> getRight());
    }
}

void BST::deletemin()
{
    if (m_root == nullptr)
    {
        return;
    }
    else if (m_root -> getLeft() == nullptr && m_root -> getRight() == nullptr)
    {
       delete m_root;
       m_root = nullptr;
       size--;
    }
    else if (m_root -> getLeft() == nullptr)
    {
        Node* temp = nullptr;
        temp = m_root;
        m_root = m_root -> getRight();
        delete temp;
        temp = nullptr;
        size--;
    }
    else
    {
        Node* temp = nullptr;
        temp = m_root;
        while (temp -> getLeft() != nullptr)
        {
            temp = temp -> getLeft();
        }
        if (m_root -> getLeft() == temp)
        {
            if (temp -> getRight() != nullptr)
            {
                m_root -> setLeft(temp -> getRight());
            }
            else
            {
                m_root -> setLeft(nullptr);
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (temp -> getRight() != nullptr)
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getLeft() != temp)
            {
                temp2 = temp2 -> getLeft();
            }
            temp2 -> setLeft(temp -> getRight());
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getLeft() != temp)
            {
                temp2 = temp2 -> getLeft();
            }
            temp2 -> setLeft(nullptr);
            delete temp;
            temp = nullptr;
            size--;
        }
    }
}

void BST::deletemax()
{
    if (m_root == nullptr)
    {
        return;
    }
    else if (m_root -> getRight() == nullptr && m_root -> getLeft() == nullptr)
    {
        delete m_root;
        m_root = nullptr;
        size--;
    }
    else if(m_root ->getRight() == nullptr)
    {
        Node* temp = nullptr;
        temp = m_root;
        m_root = m_root ->getLeft();
        delete temp;
        temp = nullptr;
        size--;
    }
    else
    {
        Node* temp = nullptr;
        temp = m_root;
        while(temp -> getRight() != nullptr)
        {
            temp = temp -> getRight();
        }
        if (m_root -> getLeft() == temp)
        {
            if (temp -> getLeft() != nullptr)
            {
                m_root -> setRight(temp -> getLeft());
            }
            else
            {
                m_root ->setRight(nullptr);
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (temp -> getLeft() != nullptr)
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getRight() != temp)
            {
                temp2 = temp2 -> getRight();
            }
            temp2 -> setRight(temp -> getLeft());
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getRight() != temp)
            {
                temp2 = temp2 -> getRight();
            }
            temp2 -> setRight(nullptr);
            delete temp;
            temp = nullptr;
            size--;
        }
    }
}

void BST::preorder(Node *subtree)
{
    if (subtree != nullptr)
    {
        std::cout << subtree -> getValue() << " ";
        preorder(subtree -> getLeft());
        preorder(subtree -> getRight());
    }
}

void BST::inorder(Node* subtree)
{
    if (subtree != nullptr)
    {
        inorder(subtree -> getLeft());
        std::cout << subtree -> getValue() << " ";
        inorder(subtree -> getRight());
    }
}


void BST::levelorder(Node *subtree)
{
    if (m_root == nullptr)
    {
        return;
    }
    else
    {
        Node* myArray[size];
        for(int i = 0; i < size; i++)
        {
            myArray[i] = nullptr;
        }
        int place = 0;
        int insert = 1;
        myArray[place] = subtree;
        bool notdone = true;
        while (notdone)
        {
            Node* temp = nullptr;
            temp = myArray[place];
            std::cout << temp -> getValue() << " ";
            place++;
            if(temp -> getLeft() != nullptr)
            {
                myArray[insert] = temp -> getLeft();
                insert++;
            }
            if(temp -> getRight() != nullptr)
            {
                myArray[insert] = temp -> getRight();
                insert++;
            }
            if(place == size)
            {
                notdone = false;
            }
            else if (myArray[place] == nullptr)
            {
                notdone = false;
            }


        }
    }

}

