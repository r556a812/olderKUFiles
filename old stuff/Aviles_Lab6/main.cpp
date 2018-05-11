/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.10.07
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "min5_heap.h"
#include "BST.h"
#include "Timer.cpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

int main ()
{
    //Declare variables
    BST myBST;
    min5_heap myHeap;
    Timer tim;
    int n = 50000;
    double myArray[400000];
    int heapArray[400000];
    double avgBST = 0;
    double avgBSTDelete = 0;
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

        //Start timer for the BST
        tim.start();

        //Insert the numbers into the BST
        for (int k = 0; k < n; k++)
        {
            int insert = myArray[k];
            myBST.insert(insert);
        }

        //Stop the timer and print the duration
        double b = tim.stop();
        tim.printTime(b);
        avgBST += b;

        //Start the timer for the Heap
        tim.start();

        //Insert the numbers into the Heap
        for (int l = 0; l < n; l++)
        {
            myHeap.insert(heapArray, myArray[l]);
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

        //Start timer for the BST deletion and insert
        tim.start();

        //Delete or insert into the BST
        for (int y = 0; y < n/10; y++)
        {
            int r = 0;

            if (myArray[y] < 0.25)
            {
                myBST.deletemin();
            }
            else if (myArray[y] < 0.5)
            {
                myBST.deletemax();
            }
            else if (myArray[y] < 0.75)
            {
                myBST.remove(extras[r]);
                r++;
            }
            else
            {
                myBST.insert(extras[r]);
                r++;
            }
        }

        //Stop the timer and print the duration
        double b2 = tim.stop();
        tim.printTime(b2);
        avgBSTDelete += b2;


        //Start the timer for the Heap deletion and insert
        tim.start();

        //Delete or insert into the Heap
        for (int z = 0; z < n/10; z++)
        {
            int r = 0;

            if (myArray[z] < 0.25)
            {
                myHeap.deletemin(heapArray);
            }
            else if (myArray[z] < 0.5)
            {
                myHeap.deletemax(heapArray);
            }
            else if (myArray[z] < 0.75)
            {
                myHeap.remove(heapArray, extras[r]);
                r++;
            }
            else
            {
                myHeap.insert(heapArray, extras[r]);
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
            std::cout << "Average BST creation time : " << (avgBST/5);
            std::cout << "\nAverage Heap creation time : " << (avgHeap/5) << "\n";
            std::cout << "Average BST deletion/insert time : " << (avgBSTDelete/5);
            std::cout << "\nAverage Heap deletion/insert time : " << (avgHeapDelete/5) << "\n\n-------------------------------------\n";
            avgBST = 0;
            avgHeap = 0;
            avgBSTDelete = 0;
            avgHeapDelete = 0;
        }

        myBST.~BST();
        myHeap.~min5_heap();
    }
}

