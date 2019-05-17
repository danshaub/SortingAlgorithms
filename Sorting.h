#ifndef SORTING_H
#define SORTING_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include "GenTree.h"

class Sorting{
    public:
        static void BubbleSort(long double* arr, int length);
        static void InsertionSort(long double* arr, int length);
        static void QuickSort(long double* arr, int length);
        static void TreeSort(long double* arr, int length);
        
        // static void TimSort(long double* arr, int length);

    private:
        static void QuickSortRec(long double* arr, int low, int high);
        static int Partition(long double* arr, int low, int high);

        static int index;
        static void Populate(long double* arr, TreeNode<long double> *node);

        // static void TimSortRec();
        // static void TimInsertion();
        // static void Merge();
};

#endif //SORTING_H