 
/**
*	@file : minmaxheap.h
*	@author : Richard Aviles
*	@date : 2015.10.21
	Purpose: The header file for minmaxheap
*/

#ifndef MINMAXHEAP
#define MINMAXHEAP

class minmaxheap
{
    public:
        minmaxheap();
        ~minmaxheap();
        void initialInsert(int myArray[], int num);
        void insert(int myArray[], int num);
        void bottomUp(int myArray[]);
        void deletemin(int myArray[]);
        void deletemax(int myArray[]);
        void levelorder(int myArray[]);
        void trickleDown(int myArray[], int index);
        void trickleDownMin(int myArray[], int index);
        void trickleDownMax(int myArray[], int index);
        void bubbleUp(int myArray[], int index);
        void bubbleUpMin(int myArray[], int index);
        void bubbleUpMax(int myArray[], int index);
        int size;
        int place;
};
#endif
        
    
