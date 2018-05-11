 
/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2016.09.23 
*       @modified: 2016.11.18
	Purpose: The header file for Node
*/

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node(); //@pre None @post Creates a Node, with default value of 0 and pointer m_next to nullptr @return None
        void setVertex(int v1, int v2); //@pre Have to pass in two numbers @post Sets the numbers provided to the vertex1 and vertex2 in the Node @return None
        void setEdge(int e); //@pre Have to pass in a number @post Sets the number provided to the edge in the Node @return None
        int getV1() const; //@pre None @post None @return Returns the value of vertex1 in the Node
        int getV2() const; //@pre None @post None @return Returns the value of vertex1 in the Node
        int getEdge() const; //@pre None @post None @return Returns the value of edge in the Node
        void setLeft(Node* left); //@pre Have to pass in a Node* for the next Node in line @post Sets the given Node to the back of the List @return None
        void setRight(Node* right);//@pre Pass in Node pointer @post Sets m_right to pointer @return None
        void setParent(Node* parent); //@pre Pass in a Node pointer to the Nodes parent @post Sets the given node to be the parent @return None
        Node* getLeft() const; //@pre None @post None @return Returns the Node pointer m_Left
        Node* getRight() const;//@pre None @post None @return Returns the Node pointer m_right
        Node* getParent() const; //@pre None @post None @return Returns the Node pointer pointing to the parent
        Node* m_left;//@pre None @post None @return None
        Node* m_right;//@pre None @post None @return None
        Node* m_parent; //@pre None @post None @return None
        int vertex1; //@pre None @post None @return None
        int vertex2; //@pre None @post None @return None
        int edge; //@pre None @post None @return None
        
};

#endif
    
    
