/**
*	@file : BinarySearchTree.h
*	@author : Richard Aviles
*	@date : 2015.11.05
	Purpose:  The header file for the BinarySearchTree class.
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BSTI.h"
#include "Node.h"
#include <vector>
#include <iostream>

template <typename T>

class BinarySearchTree: public BSTI<T>  //used to derive from the BSTI class
{
public:
    BinarySearchTree(); //@pre none @post creates a constructor for the BinarySearchTree class with m_root set to nullptr @return none
    BinarySearchTree(const BinarySearchTree<T>& other); //@pre have to pass in a valid BinarySearchTree reference @post copies the entire BinarySearchTree @return none
    ~BinarySearchTree(); //@pre have to pass in a BinarySearchTree @post deletes the nodes in the BinarySearchTree @return none
    BSTI<T>* clone(); //@pre none @post creates a copy of the BinarySearchTree using the copy constructor @return Returns a pointer to the copied tree
    bool isEmpty() const; //@pre none @post none @return Returns true if the tree is empty (no nodes), false otherwise
    bool add(T value); //@pre have to pass in a valid value @post adds the value to the tree @return Returns true if the add operation was successful
    bool search(T value) const; //@pre have to pass in a valid value @post none @return Returns true if the value is in the tree, false otherwise
    void printTree(Order order) const; //@pre have to pass in an order as to how you want the tree printed @post Prints all the values in the tree in the given specified order @return none
    std::vector<T> treeToVector(Order order) const; //@pre have to pass in an order as to how you want the tree printed @post none @return Returns a vector with the contents of the tree in the specified order
    
private:
    Node<T>* m_root;
    bool add(T value, Node<T>* subtree); //@pre have to pass in a valid value and a node pointer @post adds the given value to the correct branch of the subtree @return Returns true if the add operation was successful
    void deleteTree(Node<T>* subtree); //@pre have to pass in a valid BinarySearchTree @post deletes all the nodes in the tree @return none
    bool search(T value, Node<T>* subtree) const; //@pre have to pass in a valid value and node pointer to the tree @post searches for the value in the tree @return  Returns true if the value is in the tree, false otherwise
    void printTree(Node<T>* subtree, Order order) const; //@pre have to pass in a valid node pointer to the tree and a specified order that you want it printed in  @post Prints all the values in the tree in the specified order @return none
    void treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const; //@pre have to pass in a valid node pointer and a order that you want the tree in  @post recursive helper function to load the vector, vec, in a given specified order @return none
    
};


#include "BinarySearchTree.hpp"

#endif
