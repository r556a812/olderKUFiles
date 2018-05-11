 
/**
*	@file : min5_heap.h
*	@author : Richard Aviles
*	@date : 2015.09.30
	Purpose: The header file for min5-heap
*/

#ifndef MIN5_HEAP
#define MIN5_HEAP

class min5_heap
{
    public:
        min5_heap();
        ~min5_heap();
        void initialInsert(int myArray[], int num);
        void heapify(int myArray[]);
        void insert(int myArray[], int num);
        void deletemin(int myArray[]);
        void deletemax(int myArray[]);
        void remove(int myArray[], int num);
        void levelorder(int myArray[]);
        void print5(int myArray[], int index);
        bool switchUp(int myArray[], int index);
        bool switchDown(int myArray[], int index);
        int size;
        int place;
};
#endif
        
    
