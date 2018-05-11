#include "SortDriver.h"
#include "NumberFileDriver.h"
#include "Test.h"
#include "NumberFileGenerator.h"
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char** argv)
{

    SortDriver sd;
    NumberFileDriver nfd;
    Test myTester(std::cout);
    bool valid = true;

    if (argc>1)
    {
        std::string option = argv[1];

        if (option == "-test")
        {
            myTester.runTests();
        }
        else if (option == "-create")
        {
            nfd.run(argc, argv);
        }
        else if (option == "-sort")
        {
            sd.run(argc, argv);
        }
        else
        {
            valid = false;
        }

    }
    else
    {
        valid = false;
    }



    if (!valid)
    {
        nfd.printHelpMenu();
        sd.printHelpMenu();
    }


    return (0);

}
