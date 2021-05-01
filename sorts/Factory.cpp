//
// Created by vikid on 01.05.2021.
//
#include "Factory.h"
#include "Strategy.h"

Sorts* SortFactory::CreateSortsObject(int sortType)
{
    switch (sortType)
    {
        case Strategy::BubbleSort:
            return new bubbleSort();
        case Strategy::ShakerSort:
            return new shakerSort();
        case Strategy::InsertionSort:
            return new insertionSort();
        case Strategy::StupidQuickSort:
            return new simpleQuickSort();
        case Strategy::MedianQuickSort:
            return new medianQuickSort();
        default:
            return NULL;
    }
}
