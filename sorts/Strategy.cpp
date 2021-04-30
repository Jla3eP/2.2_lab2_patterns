#include "Strategy.h"

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
	if(sortsPtrs.empty()){
		setSortsPtrs();
	}
	if(sortsPtrs.count(strategy)) {
		while ( !sortsPtrs[strategy]->doesArraySorted(mass, size)) {
			mass = sortsPtrs[strategy]->startSort(mass, size, _render);
		}
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
