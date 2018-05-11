/**
*	@file : Sorts.h
*	@author : Richard Aviles
*	@date : 2015.10.22
	Purpose:  Header file for the Sorts class. 
*/

#ifndef SORTS_H
#define SORTS_H 

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>

template <typename T>

class Sorts
{
public:
    static void bubbleSort(T arr[], int size);  //@pre have to have pass in an array and an int for the size of the array @post sorts the array using the bubble sort method @return none
    static void bogoSort(T arr[], int size);    //@pre have to have pass in an array and an int for the size of the array @post sorts the array using the bogo sort mehod @return none
    static void insertionSort(T arr[], int size);   //@pre have to have pass in an array and an int for the size of the array @post sorts the array using the insertion method @return none
    static void selectionSort(T arr[], int size);   //@pre have to have pass in an array and an int for the size of the array @post sorts the array using the selection method @return none
    static bool isSorted(T arr[], int size);    //@pre have to have pass in an array and an int for the size of the array @post determines if the array is sorted @return returns true if the array is sorted, false otherwise
    static void shuffle(T arr[], int size, std::default_random_engine& generator);  //@pre have to have pass in an array and an int for the size of the array @post shuffles the values in the array, doesnt change any of the values in the array @return none
    static int* createTestArray(int size, int min, int max);    //@pre have to pass in ints that represent the size and the minimum and maximum amounts for the random number generator @post creates an array with given size and puts random values into the array @return returns an int pointer to the array.
    static double sortTimer(std::function<void(T[], int)> sort, T arr[], int size); //@pre @post @return
    static void mergeSort(T arr[], int size);
    static void quickSort(T arr[], int size);
    static void quickSortWithMedian(T arr[], int size);
    
private:
    static void merge(T* a1, T* a2, int size1, int size2);
    static void quickSortRec(T arr[], int first, int last, bool median);
    static void setMedianPivot(T arr[], int first, int last);
    static int partition(T arr[], int first, int last, bool median);
    static void shuffle(T arr[], int size);
    
};

#include "Sorts.hpp"

#endif