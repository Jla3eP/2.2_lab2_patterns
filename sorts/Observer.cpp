//
// Created by vikid on 01.05.2021.
//
#include "Observer.h"
#include <iostream>

void ObserverPrint::update(int * array, int size)
{
    std::cout << "Finished sorting!!!" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

#include "Observer.h"
