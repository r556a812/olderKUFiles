 
/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2015.09.23
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
        void setLeft(Node* left); //@pre Have to pass in a Node* for the next Node in line @post Sets the given Node to the back of the List @return None
        void setRight(Node* right);//@pre Pass in Node pointer @post Sets m_right to pointer @return None
        Node* getLeft() const; //@pre None @post None @return Returns the Node pointer m_Left
        Node* getRight() const;//@pre None @post None @return Returns the Node pointer m_right
        int m_value; //@pre None @post None @return None
        Node* m_left;//@pre None @post None @return None
        Node* m_right;//@pre None @post None @return None
        int rank;
        void setRank(int a);
        int getRank();
        
};

#endif
    
    
