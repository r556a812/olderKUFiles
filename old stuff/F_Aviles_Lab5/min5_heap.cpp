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
    for(int i = 0; i < 500; i++)
    {
        myArray[i] = 0;
    }
}
min5_heap::~min5_heap()
{

}

void min5_heap::initialInsert(int num)
{
    myArray[size] = num;
    size++;
}

void min5_heap::heapify()
{
    place = ((size-1)/5)-1;
    int index = 0;
    do
    {
        index = place;
        bool notdone = true;
        while(notdone)
        {
            notdone = switchDown(place);
        }
        place = index;
        place--;

    }while(place >= 0);
}


void min5_heap::insert(int num)
{
    bool notdone = true;
    place = size;
    myArray[size] = num;
    while(notdone)
    {
        notdone = switchUp(place);
    }
    size++;
}

void min5_heap::deletemin()
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
            notdone = switchDown(place);
        }
        size--;
    }
}

void min5_heap::deletemax()
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
                notdone = switchUp(place);
            }
            size--;
        }
    }
}

void min5_heap::remove(int num)
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
                notdone = switchUp(place);
            }
            place = index;
            notdone = true;
            while(notdone)
            {
                notdone = switchDown(place);
            }
            size--;
        }
        index++;
    }
    for(int i = 0; i < size; i++)
    {
        if (myArray[i] == num)
        {
            remove(num);
        }
    }
}

bool min5_heap::switchUp(int index)
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

bool min5_heap::switchDown(int index)
{
    int child = (5*index)+1;

    if(index == 0)
    {
        child = 1;
    }

    if(myArray[child] == 0)
    {
        return false;
    }
    else
    {
        int min = myArray[child];
        int minChild = child;
        for (int i = 1; i < 5; i++)
        {
            if (myArray[child + i] != 0 && myArray[child + i] < min)
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

void min5_heap::levelorder()
{
    int i = 1;
    if (size > 0)
    {
        std::cout << myArray[0] << "\n";
    }
    if (size > 1)
    {
        print5(1);
        std::cout << "\n";
    }
    if (size > 6)
    {
        i = 6;
        do
        {
            print5(i);

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
            print5(i);
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

void min5_heap::print5(int index)
{
    int i = 0;
    while(i < 5 && myArray[index] != 0)
    {
        std::cout << myArray[index] << " ";
        i++;
        index++;
    }
}















































