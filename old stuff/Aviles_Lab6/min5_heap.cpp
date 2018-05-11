/**
*	@file : min5_heap.cpp
*	@author :  Richard Aviles
*	@date : 2015.09.30
*	Purpose: Creates the min5_heap and all its methods
*/


#include "min5_heap.h"
#include <iostream>
using namespace std;

min5_heap::min5_heap()
{
    size = 0;
    place = 0;

}
min5_heap::~min5_heap()
{
    size = 0;
    place = 0;
}

void min5_heap::initialInsert(int myArray[], int num)
{
    myArray[size] = num;
    size++;
}

void min5_heap::heapify(int myArray[])
{
    place = ((size-1)/5)-1;
    int index = 0;
    do
    {
        index = place;
        bool notdone = true;
        while(notdone)
        {
            notdone = switchDown(myArray, place);
        }
        place = index;
        place--;

    }while(place >= 0);
}


void min5_heap::insert(int myArray[], int num)
{
    bool notdone = true;
    place = size;
    myArray[size] = num;
    while(notdone)
    {
        notdone = switchUp(myArray, place);
    }
    size++;
}

void min5_heap::deletemin(int myArray[])
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        myArray[0] = 0;
        size--;
    }
    else
    {
        bool notdone = true;
        int change = myArray[size-1];
        myArray[size-1] = 0;
        myArray[0] = change;
        place = 0;
        while(notdone)
        {
            notdone = switchDown(myArray, place);
        }
        size--;
    }
}

void min5_heap::deletemax(int myArray[])
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        myArray[0] = 0;
        size--;
    }
    else
    {
        int max = 0;
        int spot = 0;
        int index = ((size - 2)/5) + 1;
        while(index < size)
        {
            if (myArray[index] > max)
            {
                max = myArray[index];
                spot = index;
            }
            index++;
        }
        if (myArray[size-1] == max)
        {
            myArray[size-1] = 0;
            size--;
        }
        else
        {
            myArray[spot] = myArray[size-1];
            myArray[size-1] = 0;
            bool notdone = true;
            place = spot;
            while(notdone)
            {
                notdone = switchUp(myArray, place);
            }
            size--;
        }
    }
}

void min5_heap::remove(int myArray[], int num)
{
    int index = 0;
    bool notdone = true;
    while(index < size)
    {
        if (myArray[index] == num)
        {
            myArray[index] = myArray[size-1];
            myArray[size-1] = 0;
            place = index;
            while(notdone)
            {
                notdone = switchUp(myArray, place);
            }
            place = index;
            notdone = true;
            while(notdone)
            {
                notdone = switchDown(myArray, place);
            }
            size--;
        }
        index++;
    }
    for(int i = 0; i < size; i++)
    {
        if (myArray[i] == num)
        {
            remove(myArray, num);
        }
    }
}

bool min5_heap::switchUp(int myArray[], int index)
{
    if (myArray[index] == 0)
    {
        return false;
    }
    else
    {
        int parent = (index-1)/5;
        if (myArray[index] < myArray[parent])
        {
            int change = myArray[parent];
            myArray[parent] = myArray[index];
            myArray[index] = change;
            place = parent;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool min5_heap::switchDown(int myArray[], int index)
{
    int child = (5*index)+1;

    if(index == 0)
    {
        child = 1;
    }

    if(child >= size)
    {
        return false;
    }
    else
    {
        int min = myArray[child];
        int minChild = child;
        for (int i = 1; i < 5; i++)
        {
            if (child + i < size && myArray[child + i] < min)
            {
                min = myArray[child + i];
                minChild = child + i;
            }
        }
        if (myArray[index] > myArray[minChild])
        {
            int change = myArray[minChild];
            int in = myArray[index];

            myArray[minChild] = in;
            myArray[index] = change;
            place = minChild;

            return true;
        }
        else
        {
            return false;
        }

    }
}

void min5_heap::levelorder(int myArray[])
{
    int i = 1;
    if (size > 0)
    {
        std::cout << myArray[0] << "\n";
    }
    if (size > 1)
    {
        print5(myArray, 1);
        std::cout << "\n";
    }
    if (size > 6)
    {
        i = 6;
        do
        {
            print5(myArray, i);

            if(myArray[i+5] != 0 && (i+5) != 31)
            {
                std::cout << "- ";
            }
            i = i + 5;

        }while(i < 31 || myArray[i] == 0);
    }
    if (size > 31)
    {
        i = 31;
        do
        {
            print5(myArray, i);
            if(myArray[i+5] != 0 && (i+5) != 500)
            {
                std::cout << "- ";
            }
            i = i + 5;
        }while(i < 31 || myArray[i] == 0);
    }

    /*for (int i = 0; i< size; i++)
    {
        std::cout << myArray[i] << " ";
    }*/

}

void min5_heap::print5(int myArray[], int index)
{
    int i = 0;
    while(i < 5 && myArray[index] != 0)
    {
        std::cout << myArray[index] << " ";
        i++;
        index++;
    }
}















































