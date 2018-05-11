 
/**
*	@file : disjoint.h
*	@author : Richard Aviles
*	@date : 2016.11.18 
	Purpose: The header file for disjoint set
*/

#include "Node.h"

#ifndef DISJOINT_H
#define DISJOINT_H

class disjoint
{
    public:
        disjoint(int size); //@pre Pass in a size for the disjoing set @post Creates disjoint sets depending on the size given @return None
        int find(int v); //@pre Pass in a vertex to search for in the set @post None @return The int representing the parent of the set
        int findParent(Node* v); //@pre Node pointer of the vertex looking for its parent @post None @return Returns the int representing the parent of the set
        void merge(int v1, int v2); //@pre Pass in two vertices @post Merges the two vertices into one set @return None
        Node ** disSet; //@pre None @post None @return None
        int m_size; //@pre None @post None @return None
};

#endif
    
    
