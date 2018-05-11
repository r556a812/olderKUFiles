/**
*	@file : BST.h
*	@author : Richard Aviles
*	@date : 2015.09.23
	Purpose: The header file for Binar Search Tree
*/

#include "Node.h"
#include <iostream>

#ifndef BST_H
#define BST_H

class BST
{
    public:
        BST();
        ~BST();
        void insert(int num);//@pre pass in an int @post Inserts the number into an empty tree @return None
        void findInsert(int num, Node* subtree);//@pre Pass in int and node pointer @post inserts number into the tree if not already there @return None
        void remove(int num);//@pre Pass in an int @post Removes from tree in only one node @return None
        void findRemove(int num, Node* subtree, Node* parent);//@pre Pass in int and two node pointers @post Removes the int from the tree if it exists @return None
        Node* search(int num, Node* subtree);//@pre Pass in an int and node pointer @post None @return Pointer to the node containing the int if exists
        void deletemin();//@pre None @post Deletes the min number from the tree @return None
        void deletemax();//@pre None @post Deletes the max number from the tree @return None
        void preorder(Node* subtree);//@pre Pass in Node pointer @post Displays the values in the tree in preorder @return None
        void inorder(Node* subtree);//@pre Pass in Node pointer @post Displays the values in the tree in order @return None
        void levelorder(Node* subtree);//@pre Pass in Node pointer @post Displays the values in level order @return None
        Node* m_root;//@pre None @post None @return None
        int size;//@pre None @post None @return None
        
};

#endif
    
