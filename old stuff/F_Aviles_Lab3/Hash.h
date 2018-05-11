/**
*	@file : Hash.h
*	@author : Richard Aviles
*	@date : 2016.09.16
        Purpose: The header file for Hash.
*/

#ifndef HASH_H
#define HASH_H

class Hash
{
    public:
        void insert(int x, int length, int list[], bool flags[]); //@pre Have to pass in two ints, x for insert value and value for length, and two arrays, list and flags @post If possible, inserts the number into the list given @return None
        void remove(int x, int length, int list[], bool flags[]); //@pre Have to pass in two ints, x for insert value and value for length, and two arrays, list and flags @post If the number is in the list, removes that value, changes the plave in the list array to a -1, and the place in the flags array to true @return None
        void print(int length, int list[], bool flags[]); //@pre Have to pass in an int for length and two arrays, list and flags @post Displays the contents of the list @return None
        int hash(int x, int m, int i); //@pre Have to pass in three ints, one for value inserting, one for module, and one for the attempt number @post Uses a formula to produce a number to try for the array @return Int that represents the place in the array the number is to try to be inserted at
        bool contains(int x, int length, int list[], bool flags[]); //@pre Have to pass in two ints, x for insert value and value for length, and two arrays, list and flags @post None @return True if the number is in the list, false if the number is not in the list
        bool isFull(int length, int list[]); //@pre Have to pass in an int that is the length of the array, and the array @post None @return True if the array is completely full, false if it is not
};

#endif
