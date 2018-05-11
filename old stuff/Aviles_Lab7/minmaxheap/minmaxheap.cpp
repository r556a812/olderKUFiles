/**
*	@file : minmaxheap.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.21
*	Purpose: Creates the min-max heap and all its methods
*/


#include "minmaxheap.h"
#include <iostream>
#include <math.h>
using namespace std;

minmaxheap::minmaxheap()
{
    size = 0;
    place = 0;

}
minmaxheap::~minmaxheap()
{
    size = 0;
    place = 0;
}

void minmaxheap::initialInsert(int myArray[], int num)
{
    size++;
    myArray[size] = num;
}

void minmaxheap::bottomUp(int myArray[])
{
    int start = size;

    while (start != 0)
    {
        trickleDown(myArray, start);
        start--;
    }
}

void minmaxheap::insert(int myArray[], int num)
{
    size++;
    myArray[size] = num;
    bubbleUp(myArray, size);
}

void minmaxheap::deletemin(int myArray[])
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        myArray[size] = 0;
        size--;
    }
    else if (size == 2)
    {
        myArray[1] = myArray[2];
        myArray[2] = 0;
        size--;
    }
    else if (size == 3)
    {
        if (myArray[2] > myArray[3])
        {
            myArray[1] = myArray[3];
            myArray[3] = 0;
            size--;
        }
        else
        {
            myArray[1] = myArray[2];
            myArray[2] = myArray[3];
            myArray[3] = 0;
            size--;
        }
    }
    else if (size < 6)
    {
        place = 3;

        for (int i = 4; i < size+1; i++)
        {
            if (myArray[i] < myArray[place])
            {
                place = i;
            }
        }

        myArray[1] = myArray[place];
        myArray[place] = myArray[size];
        myArray[size] = 0;
        size--;
    }
    else
    {
        int index = 7;
        place = 4;

        if (size > 6)
        {
            index = 8;
        }

        for(int i = 5; i < index; i++)
        {
            if (myArray[i] < myArray[place])
            {
                place = i;
            }
        }

        myArray[1] = myArray[place];
        myArray[place] = myArray[size];
        myArray[size] = 0;
        size--;

        int parent = place/2;

        if(myArray[place] > myArray[parent])
        {
            int change = myArray[parent];
            myArray[parent] = myArray[place];
            myArray[place] = change;
        }

        trickleDown(myArray, place);
    }
}

void minmaxheap::deletemax(int myArray[])
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        myArray[1] = 0;
        size--;
    }
    else if (size == 2)
    {
        myArray[size] = 0;
        size--;
    }
    else if (size == 3)
    {
        if (myArray[2] < myArray[3])
        {
            myArray[3] = 0;
            size--;
        }
        else
        {
            myArray[2] = myArray[3];
            myArray[3] = 0;
            size--;
        }
    }
    else if (size < 6)
    {
        if (myArray[2] < myArray[3])
        {
            myArray[3] = myArray[size];
            myArray[size] = 0;
            size--;
        }
        else
        {
            if (size == 5)
            {
                if (myArray[4] > myArray[5])
                {
                    myArray[2] = myArray[4];
                    myArray[4] = myArray[5];
                    myArray[5] = 0;
                    size--;
                }
                else
                {
                    myArray[2] = myArray[5];
                    myArray[5] = 0;
                    size--;
                }
            }
            else
            {
                myArray[2] = myArray[4];
                myArray[4] = 0;
                size--;
            }
        }
    }
    else   //Rewrite to check for if when switch it is smaller than the parent of the grandchild, refer to delete min for tips
    {
        if (myArray[2] < myArray[3])
        {
            int index = 15;
            place = 4;

            for(int i = 5; i < index; i++)
            {
                if (myArray[i] < myArray[place])
                {
                    place = i;
                }
            }

            myArray[1] = myArray[place];
            myArray[place] = myArray[size];
            myArray[size] = 0;
            size--;

            int parent = place/2;

            if(myArray[place] > myArray[parent])
            {
                int change = myArray[parent];
                myArray[parent] = myArray[place];
                myArray[place] = change;
            }

            trickleDown(myArray, place);
        }
        else
        {
            myArray[2] = myArray[size];
            myArray[size] = 0;
            size--;

            trickleDown(myArray, 2);
        }
    }
}

void minmaxheap::trickleDown(int myArray[], int index)
{
    int level = log2(index);

    if (level % 2 == 0)
    {
        trickleDownMin(myArray, index);
    }
    else
    {
        trickleDownMax(myArray, index);
    }
}

void minmaxheap::trickleDownMin(int myArray[], int index)
{
    if ((2*index) > size)
    {
        return;
    }
    else
    {
        int min = 0;
        int child = 2*index;

        if (child == size)
        {
            min = myArray[child];
            place = child;
        }
        else if (child+1 == size || 2*child > size)
        {
            if (myArray[child] > myArray[child+1])
            {
                min = myArray[child+1];
                place = child + 1;
            }
            else
            {
                min = myArray[child];
                place = child;
            }
        }
        else if (2*child + 1 >= size)
        {
            min = myArray[child + 1];

            for (int i = 2*child; i < 2*child + 4; i++)
            {
                if (i <= size && myArray[i] < min)
                {
                    min = myArray[i];
                    place = i;
                }
            }
        }
        else
        {
            min = myArray[2*child];
            place = 2*child;

            for (int i = 2*child + 1; i < 2*child + 4; i++)
            {
                if (i <= size && myArray[i] < min)
                {
                    min = myArray[i];
                    place = i;
                }
            }
        }

        if (place > child + 1)
        {
            if (min < myArray[index])
            {
                myArray[place] = myArray[index];
                myArray[index] = min;

                int parent = place/2;

                if (myArray[place] > myArray[parent])
                {
                    myArray[place] = myArray[parent];
                    myArray[parent] = min;
                }

                trickleDownMin(myArray, place);
            }
        }
        else
        {
            if (min < myArray[index])
            {
                myArray[place] = myArray[index];
                myArray[index] = min;
            }
        }
    }
}

void minmaxheap::trickleDownMax(int myArray[], int index)
{
    if ((2*index) > size)
    {
        return;
    }
    else
    {
        int max = 0;
        int child = 2*index;

        if (child == size)
        {
            max = myArray[child];
            place = child;
        }
        else if (child+1 == size || 2*child > size)
        {
            if (myArray[child] < myArray[child+1])
            {
                max = myArray[child+1];
                place = child + 1;
            }
            else
            {
                max = myArray[child];
                place = child;
            }
        }
        else if (2*child + 1 >= size)
        {
            max = myArray[child + 1];

            for (int i = 2*child; i < 2*child + 4; i++)
            {
                if (i <= size && myArray[i] > max)
                {
                    max = myArray[i];
                    place = i;
                }
            }
        }
        else
        {
            max = myArray[2*child];
            place = 2*child;

            for (int i = 2*child + 1; i < 2*child + 4; i++)
            {
                if (i <= size && myArray[i] > max)
                {
                    max = myArray[i];
                    place = i;
                }
            }
        }

        if (place > child + 1)
        {
            if (max > myArray[index])
            {
                myArray[place] = myArray[index];
                myArray[index] = max;

                int parent = place/2;

                if (myArray[place] < myArray[parent])
                {
                    myArray[place] = myArray[parent];
                    myArray[parent] = max;
                }

                trickleDownMax(myArray, place);
            }
        }
        else
        {
            if (max > myArray[index])
            {
                myArray[place] = myArray[index];
                myArray[index] = max;
            }
        }
    }
}

void minmaxheap::bubbleUp(int myArray[], int index)
{
    int level = log2(index);
    int parent = index/2;

    if (level % 2 == 0)
    {
        if (index != 1 && myArray[index] > myArray[parent])
        {
            int swap = myArray[index];

            myArray[index] = myArray[parent];
            myArray[parent] = swap;

            bubbleUpMax(myArray, parent);
        }
        else
        {
            bubbleUpMin(myArray, index);
        }
    }
    else
    {
        if (index != 1 && myArray[index] < myArray[parent])
        {
            int swap = myArray[index];

            myArray[index] = myArray[parent];
            myArray[parent] = swap;

            bubbleUpMin(myArray, parent);
        }
        else
        {
            bubbleUpMax(myArray, index);
        }
    }
}

void minmaxheap::bubbleUpMin(int myArray[], int index)
{
    if (index > 3)
    {
        int grandparent = index/4;

        if(myArray[index] < myArray[grandparent])
        {
            int swap = myArray[index];

            myArray[index] = myArray[grandparent];
            myArray[grandparent] = swap;

            bubbleUpMin(myArray, grandparent);
        }
    }
}

void minmaxheap::bubbleUpMax(int myArray[], int index)
{
    if (index > 3)
    {
        int grandparent = index/4;

        if(myArray[index] > myArray[grandparent])
        {
            int swap = myArray[index];

            myArray[index] = myArray[grandparent];
            myArray[grandparent] = swap;

            bubbleUpMax(myArray, grandparent);
        }
    }
}

void minmaxheap::levelorder(int myArray[])
{
    if (size == 0)
    {
        return;
    }
    else
    {
        int level = 2;

        for (int i = 1; i < size+1; i++)
        {
            std::cout << myArray[i] << " ";

            if (i+1 == level)
            {
                std::cout << "\n";
                level = level * 2;
            }
        }
    }
}
















































