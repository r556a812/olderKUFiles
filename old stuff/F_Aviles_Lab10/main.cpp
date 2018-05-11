/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.11.18
*	Purpose: The main that interacts with the user.
*/

#include <iostream>
#include "span_tree.h"
#include "skewheap.h"
#include "Node.h"
#include "disjoint.h"
#include <fstream>

using namespace std;

int main ()
{
    //Declare variables
    int numTimes = 0;
    int size = 0;
    int input = 0;
    int edges = 0;


    //Open the file "data.txt"
    ifstream infile;
    infile.open("data.txt");

    //Get the number of test cases
    numTimes = infile.get() - '0';

    //Run the test cases using the variable numTimes
    for (int a = 0; a < numTimes; a++)
    {
        //Get the size of the adjacency matrix
        size = infile.get();
        while (!(isdigit(size)))
        {
            size = infile.get();
        }
        size -= '0';

        //Create the two dimensional array to hold the matrix data
        int** myArray = new int*[size];

        //Populate the array
        for (int i = 0; i < size; i++)
        {
            myArray[i] = new int[size];

            for (int j = 0; j < size; j++)
            {
                infile >> input;
                myArray[i][j] = input;
                if (myArray[i][j] != 0)
                {
                    edges++;
                }
            }
        }

        //Create the array to be used in the methods
        Node** edgeArray = new Node*[edges];
        Node** solution = new Node*[edges];
        for (int k = 0; k < edges; k++)
        {
            solution[k] = nullptr;
            edgeArray[k] = nullptr;
        }

        std::cout << "Graph" << a+1 << ":\n";

        /** KUSKAL METHOD  **/
        span_tree * k = new span_tree(myArray, edgeArray, solution, size);
        k->kruskal();
        std::cout << "\n";

        /** PRIM METHOD **/
        k->prim();
        std::cout << "\n\n";

        delete k;
    }
    infile.close();

}

