/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.12.2
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "span_tree.h"
#include "Node.h"
#include "Timer.cpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;





/** Need to erase the wording for no solution on both.
 * Need to fix Prim so that it runs in under 1 sec.
 * Need to make the grapgh and charts.**/




int main ()
{
    //Declare variables
    Timer tim;
    double x = 0.0;
    int n = 500;
    int y = 0;
    int edges = 0;
    double avgKruskal = 0;
    double avgPrim = 0;

    for (int i = 1; i <= 20; i++)
    {
        int ** myArray = new int*[n];

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
            myArray[j] = new int[n-1];

            for (int k = 0; k < n; k++)
            {
                x = (rand()%101)/100;

                if (x >= 0.5)
                {
                    y = (rand() % (4*n) + 1);
                    myArray[j][k] = y;
                    edges++;
                }
                else
                {
                    myArray[j][k] = 0;
                }
            }
        }

        //Create the array to be used in the methods
        Node **edgeArray = new Node*[edges];
        Node ** solution = new Node*[edges];
        for (int l = 0; l < edges; l++)
        {
            solution[l] = nullptr;
            edgeArray[l] = nullptr;
        }

        //Create the graphs
        span_tree *k = new span_tree(myArray, edgeArray, solution, n);
        span_tree *p = new span_tree(myArray, edgeArray, solution, n);

        //Start timer for the minmaxHeap
        tim.start();

        k->kruskal();

        //Stop the timer and print the duration
        double b = tim.stop();
        tim.printTime(b);
        avgKruskal += b;

        //Start the timer for the min-Heap
        tim.start();

        p->prim();

        //Stop the timer and print the duration
        double h = tim.stop();
        tim.printTime(h);
        avgPrim += h;
        std::cout << "\n";

        if (i % 5 == 0)
        {
            n = n * 2;
            std::cout << "Average Kruskal time : " << (avgKruskal/5);
            std::cout << "\nAverage Prim time : " << (avgPrim/5) << "\n";
            avgKruskal = 0;
            avgPrim = 0;
        }

        delete k;
        delete p;
        delete edgeArray;
        delete solution;
        delete myArray;
        edges = 0;
    }
}

