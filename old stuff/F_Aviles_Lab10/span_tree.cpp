/**
*	@file : span_tree.cpp
*	@author :  Richard Aviles
*	@date : 2016.11.18
*	Purpose: Creates the spanning tree and all its methods
*/


#include "span_tree.h"
#include "Node.h"
#include "disjoint.h"
#include <iostream>
using namespace std;

span_tree::span_tree(int**  matrix , Node** e, Node ** solution, int s)
{
    myArray = matrix;
    size = s;
    edgeArray = e;
    solutionArray = solution;
}

span_tree::~span_tree()
{
}

void span_tree::kruskal()
{
    skewheap myHeap;
    disjoint disSet(size);

    int numEdges = 0;
    int insert = 0;

    for (int k = 0; k < size; k++)
    {
        for (int l = 0; l < size; l++)
        {
            if (myArray[k][l] != 0)
            {
                insert = myArray[k][l];
                myHeap.insert(k, l, insert);

                Node * temp = new Node();
                temp -> setEdge(insert);
                temp -> setVertex(k, l);
                edgeArray[numEdges] = temp;

                numEdges++;
            }

        }
    }

    Node * temp;
    int count = 0;

    while (count < size -1 && myHeap.head != nullptr)
    {
        temp = myHeap.deletemin();



        if (disSet.find(temp->getV1()) != disSet.find(temp->getV2()))
        {
            disSet.merge(temp->getV1(), temp->getV2());
            solutionArray[count] = temp;
            count++;
        }
    }

    if (count != size-1)
    {
        std::cout << "NO SOLUTION";
        return;
    }
    else
    {
        std::cout << "Kruskal:";
        int v1 = 0;
        int v2 = 0;

        for (int i = 0; i < size - 1; i++)
        {
            v1 = solutionArray[i]->getV1();
            v2 = solutionArray[i]->getV2();
            if (v1 < v2)
            {
                std::cout << " (" << v1 << ", " << v2 << ")";
            }
            else
            {
                std::cout << " (" << v2 << ", " << v1 << ")";
            }
        }
    }



    myHeap.~skewheap();


}

void span_tree::prim()
{
    skewheap myHeap;
    int vArray[size];
    int min = -1;



    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (myArray[i][j] != 0 && min == -1)
            {
                min = j;
            }
            else if (myArray[i][j] != 0 && myArray[i][j] < myArray[i][min])
            {
                min = j;
            }

            vArray[j] = 0;
        }
    }

    myHeap.insert(0, min, myArray[0][min]);
    myArray[0][min] = 0;
    myArray[min][0] = 0;

    Node * temp;
    int count = 0;
    int v1 = 0;
    int v2 = 0;

    while (count < size -1 && myHeap.head != nullptr)
    {
        temp = myHeap.deletemin();
        v1 = temp->getV1();
        v2 = temp->getV2();

        if (vArray[v1] != 1 || vArray[v2] != 1)
        {
            vArray[v1] = 1;
            vArray[v2] = 1;
            solutionArray[count] = temp;
            count++;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == v1 || i == v2)
                    {
                        if (myArray[i][j] != 0)
                        {
                            myHeap.insert(i, j, myArray[i][j]);
                            myArray[i][j] = 0;
                            myArray[j][i] = 0;
                        }
                    }

                }
            }
        }
    }

    if (count != size-1)
    {
        std::cout << "NO SOLUTION";
        return;
    }
    else
    {
        std::cout << "Prim:";
        int v1 = 0;
        int v2 = 0;

        for (int i = 0; i < size - 1; i++)
        {
            v1 = solutionArray[i]->getV1();
            v2 = solutionArray[i]->getV2();
            if (v1 < v2)
            {
                std::cout << " (" << v1 << ", " << v2 << ")";
            }
            else
            {
                std::cout << " (" << v2 << ", " << v1 << ")";
            }
        }
    }

    myHeap.~skewheap();
}

