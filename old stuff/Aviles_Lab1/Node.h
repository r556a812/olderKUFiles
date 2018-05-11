 
/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.08.26
	Purpose: The header file for Node
*/

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node(); //@pre None @post Creates a Node, with default value of 0 and pointer m_next to nullptr @return None
        void setValue(int value); //@pre Have to pass in a number @post Sets the number provided to the Node @return None
        int getValue() const; //@pre None @post None @return Returns the value in the Node
        void setNext(Node* next); //@pre Have to pass in a Node* for the next Node in line @post Sets the given Node to the back of the List @return None
        Node* getNext() const; //@pre None @post None @return Returns the Node pointer m_next
        int m_value; //@pre None @post None @return None
        Node* m_next; //@pre None @post None @return None
        
};

#endif
    
    
