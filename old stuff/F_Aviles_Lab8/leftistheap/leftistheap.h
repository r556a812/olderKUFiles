 
/**
*	@file : leftistheap.h
*	@author : Richard Aviles
*	@date : 2015.11.10
	Purpose: The header file for leftistheap
*/
#include "Node.h"

#ifndef LEFTISTHEAP
#define LEFTISTHEAP

class leftistheap
{
    public:
        leftistheap();
        ~leftistheap();
        void insert(int x);
        void deletemin();
        void levelorder(Node *place);
        void preorder(Node *place);
        void inorder(Node *place);
        Node * merge(Node * a, Node * b);
        Node * head;
        void setRank(Node *place);
};
#endif
        
    
