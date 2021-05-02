#include "Strategy.h"
#include "Factory.h"
#include <iostream>

map<int, Sorts*> Strategy::sortsPtrs;

int *Strategy::sort (Sorts* sortsPtr, int *mass, int size, bool _render){
	if(sortsPtrs.empty()){
		setSortsPtrs();
	}
	while(!sortsPtr->doesArraySorted(mass, size)) {
		mass = sortsPtr->startSort(mass, size, _render);
	}
	return mass;
}

/**
 *
 * @param strategy смотреть enum в Strategy
 */
int *Strategy::sort (int strategy, int *mass, int size, bool _render){
    if(sortsPtrs.count(strategy) == 0) {
        Sorts* new_sort = SortFactory::CreateSortsObject(strategy);
        if (new_sort != NULL) {
            sortsPtrs.insert(std::pair<int, Sorts*>(strategy, new_sort));
        } else {
            std::cout << "Cannot sort with strategy " << strategy << std::endl;
            return mass;
        }
    }
    if(sortsPtrs.count(strategy)) {
        while ( !sortsPtrs[strategy]->doesArraySorted(mass, size)) {
            mass = sortsPtrs[strategy]->startSort(mass, size, _render);
        }
        sortsPtrs[strategy]->clearOperationsCounter();
        return mass;
    }
}

void Strategy::setSortsPtrs (){
	sortsPtrs.insert(std::pair<int, Sorts*>(BubbleSort, new bubbleSort));
	sortsPtrs.insert(std::pair<int, Sorts*>(ShakerSort, new shakerSort));
	sortsPtrs.insert(std::pair<int, Sorts*>(InsertionSort, new insertionSort));
	sortsPtrs.insert(std::pair<int, Sorts*>(StupidQuickSort, new simpleQuickSort));
    sortsPtrs.insert(std::pair<int, Sorts*>(MedianQuickSort, new medianQuickSort));
}
