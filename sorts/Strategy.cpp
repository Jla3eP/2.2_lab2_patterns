#include "Strategy.h"

std::map<int, Sorts*> Strategy::sortsPtrs = getSortsPtrs();


int *Strategy::sort (Sorts* sortsPtr, int *mass, int size, bool _render){
	while(!sortsPtr->checkSort(mass, size)) {
		mass = sortsPtr->startSort(mass, size, _render);
	}
	return mass;
}


/**
 *
 * @param strategy смотреть enum в Strategy
 */
int *Strategy::sort (int strategy, int *mass, int size, bool _render){
	if(sortsPtrs.count(strategy)) {
		while ( !sortsPtrs[strategy]->checkSort(mass, size)) {
			mass = sortsPtrs[strategy]->startSort(mass, size, _render);
		}
		return mass;
	}
	else{
		throw std::exception();
	}
}

std::map<int, Sorts*> Strategy::getSortsPtrs (){
	std::map<int, Sorts*> strats;
	strats.insert(std::pair<int, Sorts*>(BubbleSort, new bubbleSort));
	strats.insert(std::pair<int, Sorts*>(ShakerSort, new shakerSort));
	strats.insert(std::pair<int, Sorts*>(InsertionSort, new insertionSort));
	strats.insert(std::pair<int, Sorts*>(StupidQuickSort, new simpleQuickSort));
	strats.insert(std::pair<int, Sorts*>(MedianQuickSort, new medianQuickSort));
	return strats;
}
