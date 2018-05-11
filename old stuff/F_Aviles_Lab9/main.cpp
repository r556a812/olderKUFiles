/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.10.07
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "leftistheap.h"
#include "skewheap.h"
#include "Node.h"
#include "Timer.cpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

int main ()
{
    //Declare variables
    leftistheap myLeftistHeap;
    skewheap mySkewHeap;
    Timer tim;
    int n = 50000;
    double myArray[400000];
    double avgLeftist = 0;
    double avgLeftistDelete = 0;
    double avgSkew = 0;
    double avgSkewDelete = 0;
    int extras[40000];

    for (int i = 1; i <= 20; i++)
    {
        //Create the srand
        srand(i);

        /**
         *
         * Run the tests for the creation of the sructures
         *
         * */

        //Fill the array with the values
        for (int j = 0; j < n; j++)
        {
            myArray[j] = (rand() % (4 * n) + 1);
        }

        //Start timer for the leftist-heap
        tim.start();

        //Insert the numbers into the leftist-heap
        for (int k = 0; k < n; k++)
        {
            myLeftistHeap.insert(myArray[k]);
        }

        //Stop the timer and print the duration
        double b = tim.stop();
        tim.printTime(b);
        avgLeftist += b;

        //Start the timer for the skew-heap
        tim.start();

        //Insert the numbers into the skew-heap
        for (int l = 0; l < n; l++)
        {
            mySkewHeap.insert(myArray[l]);
        }

        //Stop the timer and print the duration
        double h = tim.stop();
        tim.printTime(h);
        avgSkew += h;
        std::cout << "\n";


        /**
         *
         * Run the tests for the deletion and insertion functions
         *
         * */

        //Create the values for deciding whether to delete or insert.
        //Create extras array for specific numbers to be deleted and inserted
        for (int a= 0; a< n/10; a++)
        {
            double c = (rand()%101);
            myArray[a] = c/100;
            extras[a] = rand()%(4*n)+1;
        }

        //Start timer for the leftist-heap deletion and insert
        tim.start();

        //Delete or insert into the leftist-heap
        for (int y = 0; y < n/10; y++)
        {
            int r = 0;

            if (myArray[y] < 0.5)
            {
                myLeftistHeap.deletemin();
            }
            else
            {
                myLeftistHeap.insert(extras[r]);
                r++;
            }
        }

        //Stop the timer and print the duration
        double b2 = tim.stop();
        tim.printTime(b2);
        avgLeftistDelete += b2;


        //Start the timer for the skew-heap deletion and insert
        tim.start();

        //Delete or insert into the skew-heap
        for (int z = 0; z < n/10; z++)
        {
            int r = 0;

            if (myArray[z] < 0.5)
            {
                mySkewHeap.deletemin();
            }
            else
            {
                mySkewHeap.insert(extras[r]);
                r++;
            }
        }

        //Stop the timer and print the duration
        double h2 = tim.stop();
        tim.printTime(h2);
        avgSkewDelete += h2;
        std::cout << "\n";

        if (i % 5 == 0)
        {
            n = n * 2;
            std::cout << "Average leftist-heap creation time : " << (avgLeftist/5);
            std::cout << "\nAverage skew-heap creation time : " << (avgSkew/5) << "\n";
            std::cout << "Average leftist-heap deletion/insert time : " << (avgLeftistDelete/5);
            std::cout << "\nAverage skew-heap deletion/insert time : " << (avgSkewDelete/5) << "\n\n-------------------------------------\n";
            avgLeftist = 0;
            avgSkew = 0;
            avgLeftistDelete = 0;
            avgSkewDelete = 0;
        }

        myLeftistHeap.~leftistheap();
        mySkewHeap.~skewheap();
    }
}

