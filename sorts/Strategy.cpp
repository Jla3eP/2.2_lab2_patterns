#include "Strategy.h"
#include "Factory.h"

map<int, Sorts*> Strategy::sortsPtrs;

int *Strategy::sort (Sorts* sortsPtr, int *&mass, int size, bool _render){
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
int *Strategy::sort (int strategy, int *&mass, int size, bool _render){
	if(sortsPtrs.empty()){
		setSortsPtrs();
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
	sortsPtrs.insert(std::pair<int, Sorts*>(BubbleSort, SortFactory::CreateSortsObject(BubbleSort)));
	sortsPtrs.insert(std::pair<int, Sorts*>(ShakerSort, SortFactory::CreateSortsObject(ShakerSort)));
	sortsPtrs.insert(std::pair<int, Sorts*>(InsertionSort, SortFactory::CreateSortsObject(InsertionSort)));
	sortsPtrs.insert(std::pair<int, Sorts*>(StupidQuickSort, SortFactory::CreateSortsObject(StupidQuickSort)));
    sortsPtrs.insert(std::pair<int, Sorts*>(MedianQuickSort, SortFactory::CreateSortsObject(MedianQuickSort)));
}
