 
/**
*	@file : skewheap.h
*	@author : Richard Aviles
*	@date : 2016.11.10
*       @modified : 2016.11.18
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
        void insert(int v1, int v2, int e);
        Node * deletemin();
        void levelorder(Node *place);
        void preorder(Node * place);
        void inorder(Node * place);
        Node * merge(Node * a, Node * b);
        Node * head;
};
#endif
        
    
