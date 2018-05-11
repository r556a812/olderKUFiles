#include "MazeCreationException.h"
#include "MazeReader.h"
#include "MazeWalker.h"
#include "Position.h"
#include "Test.h"
#include <string>
#include <iostream>

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

