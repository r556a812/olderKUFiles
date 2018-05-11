 
/**
*	@file : Hash.cpp
*	@author :  Richard Aviles
*	@date : 2015.09.16
*	Purpose: Uses methods to insert and delete numbers from the hash table, as well as print
*/



#include "Hash.h"
#include <iostream>
#include <string>

void Hash::insert(int x, int length, int list[], bool flags[])
{
    if (contains(x, length, list, flags) == false)
    {
        bool done = false;
        int i = 0;
        int place = 0;
        while (done == false)
        {
            place = hash(x, length, i);
            if (list[place] == -1)
            {
                list[place] = x;
                done = true;
            }
            else
            {
                i += 1;
                if (i == length)
                {
                    done = true;
                    std::cout << "Insertion could not be done for the value " << x;
                }
            }
        }
    }
}

void Hash::remove(int x, int length, int list[], bool flags[])
{
    if (contains(x, length, list, flags) == true)
    {
        int i = 0;
        int place = 0;
        bool done = false;
        while (done == false && i < length)
        {
            place = hash(x, length, i);
            if (list[place] == x)
            {
                list[place] = -1;
                flags[place] = true;
                done = true;
            }

            i += 1;
        }
    }
    else
    {
        std::cout << "Value " << x << " is not in the hash table.";
    }
}

void Hash::print(int length, int list[], bool flags[])
{
    for (int i = 0; i < length; i++)
    {
        std::cout << i << ": " << list[i] << " flag = ";
        if (flags[i] == false)
        {
            std::cout << "false\n";
        }
        else
        {
            std::cout << "true\n";
        }
    }
}

int Hash::hash(int x, int m, int i)
{
    int h_x = x % m;
    int hi_x = (h_x + (i * i)) % m;
    return (hi_x);
}


bool Hash::contains(int x, int length, int list[], bool flags[])
{
    bool found = false;
    int i = 0;
    while (found == false && i < length)
    {
        int place = hash(x, length, i);

        if (list[place] != x && flags[place] == false)
        {
            i = length;
        }
        else if (list[place] == x)
        {
            found = true;
        }
        else
        {
            i += 1;
        }
    }
    return(found);
}

bool Hash::isFull(int length, int list[])
{
    bool full = true;
    bool done = false;
    int place = 0;

    while (done == false && place < length)
    {
        if (list[place] == -1)
        {
            done = true;
            full = false;
        }

        place += 1;
    }

    return (full);
}
