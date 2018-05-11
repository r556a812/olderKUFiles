/**
*	@file : Sorts.hpp
*	@author :  Richard Aviles
*	@date : 2015.10.22
*	Purpose: Creates the methods for the Sorts class.
*/

#include <chrono>
#include "Sorts.h"

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    int change = 0;

    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                change = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = change;
            }
        }
    }

    assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
    bool sorted = false;
    std::default_random_engine generator(time(nullptr));

    do
    {
        shuffle(arr, size, generator);
        sorted = isSorted(arr, size);

    }while (sorted == false);

    assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    int change = 0;
    int location = 0;

    for (int i = 0; i < size; i++)
    {
        location = i;

        while (location > 0 && arr[location] < arr[location - 1])
        {
            change = arr[location];
            arr[location] = arr[location - 1];
            arr[location - 1] = change;
            location--;
        }
    }

    assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    int small = 0;
    int change = 0;

    for (int i = 0; i < size - 1; i++)
    {
        small = i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }

        if (small != i)
        {
            change = arr[i];
            arr[i] = arr[small];
            arr[small] = change;
        }
    }

    assert( Sorts<T>::isSorted(arr, size) );

}


template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    bool sort = true;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            sort = false;
        }
    }

    return (sort);
}


template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine &generator)
{
    int randomNumber = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {

        std::uniform_int_distribution<int> distribution(0,size);
        randomNumber = distribution(generator);

        temp = arr[i];
        arr[i] = arr[randomNumber];
        arr[randomNumber] = temp;
    }
}


template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
    int randomNumber = 0;

    int* arr = new int[size];
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min,max);
    for (int i = 0; i < size; i++)
    {
        randomNumber = distribution(generator);
        arr[i] = randomNumber;
    }

    return (arr);
}


template <typename T>
double Sorts<T>::sortTimer(std::function<void (T[], int)> sort, T arr[], int size)
{
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;

    start = std::chrono::system_clock::now();

    sort(arr, size);

    end = std::chrono::system_clock::now();
    elapsed = (end - start);

    return(elapsed.count());
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    int middle = size/2;
    T* left = arr+0;
    T* right = arr+middle;

    if (size == 0 || size == 1)
    {
       return;
    }
    else
    {
        mergeSort(left, middle);
        mergeSort(right, middle);
    }

}


template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    int pivot = arr[size/2];
    int temp = 0;
    int left = 0;
    int right = size-1;


}


template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{

}

template <typename T>
void Sorts<T>::merge(T *a1, T *a2, int size1, int size2)
{

}


template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{

}


template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{

}


template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    return(5);
}


template <typename T>
void Sorts<T>::shuffle(T arr[], int size)
{

}
