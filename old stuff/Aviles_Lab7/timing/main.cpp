/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.10.07
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "min5_heap.h"
#include "minmaxheap.h"
#include "Timer.cpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

int main ()
{
    //Declare variables
    minmaxheap myMMHeap;
    min5_heap myMinHeap;
    Timer tim;
    int n = 50000;
    double myArray[400000];
    int minheapArray[400000];
    int minmaxArray[400000];
    double avgMMHeap = 0;
    double avgMMHeapDelete = 0;
    double avgHeap = 0;
    double avgHeapDelete = 0;
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

        //Start timer for the minmaxHeap
        tim.start();

        //Insert the numbers into the minmaxHeap
        for (int k = 0; k < n; k++)
        {
            int insert = myArray[k];
            myMMHeap.insert(minmaxArray, insert);
        }

        //Stop the timer and print the duration
        double b = tim.stop();
        tim.printTime(b);
        avgMMHeap += b;

        //Start the timer for the min-Heap
        tim.start();

        //Insert the numbers into the min-Heap
        for (int l = 0; l < n; l++)
        {
            myMinHeap.insert(minheapArray, myArray[l]);
        }

        //Stop the timer and print the duration
        double h = tim.stop();
        tim.printTime(h);
        avgHeap += h;
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

        //Start timer for the minmaxHeap deletion and insert
        tim.start();

        //Delete or insert into the minmaxHeap
        for (int y = 0; y < n/10; y++)
        {
            int r = 0;

            if (myArray[y] < 0.25)
            {
                myMMHeap.deletemin(minmaxArray);
            }
            else if (myArray[y] < 0.5)
            {
                myMMHeap.deletemax(minmaxArray);
            }
            else
            {
                myMMHeap.insert(minmaxArray, extras[r]);
                r++;
            }
        }

        //Stop the timer and print the duration
        double b2 = tim.stop();
        tim.printTime(b2);
        avgMMHeapDelete += b2;


        //Start the timer for the min-Heap deletion and insert
        tim.start();

        //Delete or insert into the min-Heap
        for (int z = 0; z < n/10; z++)
        {
            int r = 0;

            if (myArray[z] < 0.25)
            {
                myMinHeap.deletemin(minheapArray);
            }
            else if (myArray[z] < 0.5)
            {
                myMinHeap.deletemax(minheapArray);
            }
            else
            {
                myMinHeap.insert(minheapArray, extras[r]);
                r++;
            }
        }

        //Stop the timer and print the duration
        double h2 = tim.stop();
        tim.printTime(h2);
        avgHeapDelete += h2;
        std::cout << "\n";

        if (i % 5 == 0)
        {
            n = n * 2;
            std::cout << "Average minmaxHeap creation time : " << (avgMMHeap/5);
            std::cout << "\nAverage min-Heap creation time : " << (avgHeap/5) << "\n";
            std::cout << "Average minmaxHeap deletion/insert time : " << (avgMMHeapDelete/5);
            std::cout << "\nAverage min-Heap deletion/insert time : " << (avgHeapDelete/5) << "\n\n-------------------------------------\n";
            avgMMHeap = 0;
            avgHeap = 0;
            avgMMHeapDelete = 0;
            avgHeapDelete = 0;
        }

        myMMHeap.~minmaxheap();
        myMinHeap.~min5_heap();
    }
}

