/**
*	@file : BSTI.h
*	@author : Richard Aviles
*	@date : 2015.11.05
	Purpose:  Header file for the BSTI class. Serves as an interface for the Binary Search Tree.
*/

#ifndef BSTI_H
#define BSTI_H 
#include <vector>



enum Order
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

template <typename T>

class BSTI
{
public:
    virtual ~BSTI<T>(){};   //@pre A BSTI exists @post Deletes everything in the tree @return none
    virtual BSTI<T>* clone() = 0;   //@pre This is in a valid state @post creates a copy of the entire tree @return Returns a pointer to the copied tree
    virtual bool isEmpty() const = 0;   //@pre none @post none @return Returns true if the tree is empty, false otherwise
    virtual bool add(T value) = 0;   //@pre value is a valid T @post a new Node<T> is created and inserted into the tree based @return Returns true if the value was added, false otherwise (duplicate value)
    virtual bool search(T value) const = 0;   //@pre The type T is comparable by the == operator @post none @return Returns true if the value is in the tree, false otherwise.
    virtual void printTree(Order order) const = 0;   //@pre have to pass in a valid order @post prints all values in the tree in the given order @return none
    virtual std::vector<T> treeToVector(Order order) const = 0;   //@pre have to pass in a valid order @post none @return Returns a vector with the contents of the tree in the specified order 
    
};


#endif