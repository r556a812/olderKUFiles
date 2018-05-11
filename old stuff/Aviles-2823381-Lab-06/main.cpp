#include "Sorts.h"
#include <random>
#include <ctime>
#include <iostream>
#include "Test.h"



void printMenu()
{
    std::cout << "\n\nSelect a sort:\n"
              << "1) Bubble Sort\n"
              << "2) Insertion Sort\n"
              << "3) Selection Sort\n"
              << "4) Bogo Sort (use only with very small arrays!)\n"
              <<"5) Test\n"
              << "Enter choice: ";
}

void printArray(int arr[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << arr[size-1];
    std::cout << "]" << "\n\n";
}

int main()
{
    int choice = 0;
    Sorts<int> list;
    int* arr;
    int size = 0;
    int upperBound = 0;
    int lowerBound = 0;
    int randomNumber = 0;
    char unsortPrint = 'n';
    char sortPrint = 'n';
    char end = 'n';
    double elapsed = 0.0;
    Test myTest(std::cout);

do
{
    printMenu();
    std::cin >> choice;

    std::cout << "Input a size for the random array: ";
    std::cin >> size;
    std::cout << "Input a lower bound on the range of random numbers: ";
    std::cin >> lowerBound;
    std::cout << "Input an upper bound on the range of random numbers: ";
    std::cin >> upperBound;

    arr = new int[size];
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(lowerBound,upperBound);

    for (int i = 0; i < size; i++)
    {
        randomNumber = distribution(generator);
        arr[i] = randomNumber;
    }

    std::cout << "Do you want to print the unsorted array? (y/n): ";
    std::cin >> unsortPrint;

    if (unsortPrint == 'y')
    {
        std::cout << "Here is the unsorted array: ";
        printArray(arr, size);
    }




    if (choice == 1)
    {
        elapsed = list.sortTimer(Sorts<int>::bubbleSort, arr, size);

        std::cout << "Sorting with bubble sort...\n"
                  <<"Do you want to print the sorted array? (y/n): ";
        std::cin >> sortPrint;

        if (sortPrint == 'y')
        {
            std::cout << "Here is the sorted array: ";
            printArray(arr, size);
        }

        std::cout << size << " numbers were sorted in  " << elapsed << " seconds.";

    }

    if (choice == 2)
    {
        elapsed = list.sortTimer(Sorts<int>::insertionSort, arr, size);

        std::cout << "Sorting with insertion sort...\n"
                  <<"Do you want to print the sorted array? (y/n): ";
        std::cin >> sortPrint;

        if (sortPrint == 'y')
        {
            std::cout << "Here is the sorted array: ";
            printArray(arr, size);
        }

        std::cout << size << " numbers were sorted in  " << elapsed << " seconds.";

    }

    if (choice == 3)
    {
        elapsed = list.sortTimer(Sorts<int>::selectionSort, arr, size);

        std::cout << "Sorting with selection sort...\n"
                  <<"Do you want to print the sorted array? (y/n): ";
        std::cin >> sortPrint;

        if (sortPrint == 'y')
        {
            std::cout << "Here is the sorted array: ";
            printArray(arr, size);
        }

        std::cout << size << " numbers were sorted in  " << elapsed << " seconds.";

    }

    if (choice == 4)
    {
        elapsed = list.sortTimer(Sorts<int>::bogoSort, arr, size);

        std::cout << "Sorting with bogo sort...\n"
                  <<"Do you want to print the sorted array? (y/n): ";
        std::cin >> sortPrint;

        if (sortPrint == 'y')
        {
            std::cout << "Here is the sorted array: ";
            printArray(arr, size);
        }

        std::cout << size << " numbers were sorted in  " << elapsed << " seconds.";


    }

    if (choice == 5)
    {
        myTest.runTests();
    }



    std::cout << "Do you want to quit? (y/n): ";
    std::cin >> end;

}while (end != 'y');

    return (0);
}
