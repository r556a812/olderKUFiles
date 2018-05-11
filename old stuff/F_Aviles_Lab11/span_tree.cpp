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
    int cost = 0;

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

            cost += temp->getEdge();
        }
    }

    /*if (count != size-1)
    {
        std::cout << "NO SOLUTION\n";
        return;
    }
    else
    {
        std::cout << "Kruskal cost: " << cost << "\n";
    }*/


    std::cout << "Kruskal cost: " << cost << "\n";

    myHeap.~skewheap();


}

void span_tree::prim()
{
    skewheap myHeap;
    int vArray[size];
    int min = 0;
    int cost = 0;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (myArray[i][j] != 0 && myArray[i][j] < myArray[i][min])
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

            cost += temp->getEdge();

            for (int i = 0; i < size; i++)
            {
                if (myArray[v1][i] != 0)
                {
                    myHeap.insert(v1, i, myArray[v1][i]);
                    myArray[v1][i] = 0;
                    myArray[i][v1] = 0;
                }
                if (myArray[v2][i] != 0)
                {
                    myHeap.insert(v2, i, myArray[v2][i]);
                    myArray[v2][i] = 0;
                    myArray[i][v2] = 0;
                }
            }
        }
    }

    /*if (count != size-1)
    {
        std::cout << "NO SOLUTION size is " << count << "\n";
        return;
    }
    else
    {
        std::cout << "Prim cost: " << cost << "\n";
    }*/

    myHeap.~skewheap();
}

