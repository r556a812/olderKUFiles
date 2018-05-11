 
/**
*	@file : span_tree.h
*	@author : Richard Aviles
*	@date : 2016.11.18
	Purpose: The header file for span_tree
*/

#include "skewheap.h"
#include "Node.h"

#ifndef SPAN_TREE
#define SPAN_TREE

class span_tree
{
    public:
        span_tree(int** matrix, Node ** e, Node** solution, int s); //@pre Must pass in a matrix, edge, and solution arrays in the form of a double pointer, pass in a size s as well @post Sets default values @return None
        ~span_tree(); //@pre None @post Deletes all information @return None
        void kruskal(); //@pre None @post Outputs minimum spanning tree using the kruskal method @return None
        void prim(); //@pre None @post Outputs the minimum spanning tree using the prim method @return None
        skewheap myHeap; //@pre None @post None @return None
        int** myArray; //@pre None @post None @return None
        Node** solutionArray; //@pre None @post None @return None
        int size; //@pre None @post None @return None
        Node** edgeArray; //@pre None @post None @return None
};
#endif
        
    
 
