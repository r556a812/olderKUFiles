 
/**
*	@file : skewheap.h
*	@author : Richard Aviles
*	@date : 2015.11.10
	Purpose: The header file for skewheap
*/

#include "Node.h"

#ifndef SKEWHEAP
#define SKEWHEAP

class skewheap
{
    public:
        skewheap();
        ~skewheap();
        void insert(int x);
        void deletemin();
        void levelorder(Node *place);
        void preorder(Node * place);
        void inorder(Node * place);
        Node * merge(Node * a, Node * b);
        Node * head;
};
#endif
        
    
