 
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
        void initialInsert(int num);
        void heapify();
        void insert(int num);
        void deletemin();
        void deletemax();
        void remove(int num);
        void levelorder();
        void print5(int index);
        bool switchUp(int index);
        bool switchDown(int index);
        int myArray[500];
        int size;
        int place;
};
#endif
        
    
