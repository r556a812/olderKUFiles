#include "Node.h"
#include "BinarySearchTree.h"
#include "Test.h"
#include "BSTI.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
    string a=argv[1];
    if(a=="-test")
    {
        Test myTester;
        myTester.runTests();
    }



    return(0);
}
