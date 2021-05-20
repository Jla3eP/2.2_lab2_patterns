#include "Strategy.h"
#include "Factory.h"

map<Strategy::Strats, Sorts*> Strategy::sortsPtrs;

int *Strategy::sort (Sorts* sortsPtr, int *&mass, size_t size, bool _render){
	if(sortsPtrs.empty()){
		initializeSortsPtrs();
	}
	while(!sortsPtr->doesArraySorted(mass, size)) {
		mass = sortsPtr->startSort(mass, size, _render);
	}
	return mass;
}

/**
 * @param strategy смотреть enum(!!!!!) в Strategy
 */
int *Strategy::sort (Strats strategy, int *&mass, size_t size, bool _render){
	if(sortsPtrs.empty()){//якщо треба, створюємо об'єкти сортувань
		initializeSortsPtrs();
	}
    if(sortsPtrs.count(strategy)) {//якщо існює необхідний, сортуємо
        while ( !sortsPtrs[strategy]->doesArraySorted(mass, size)) {
            mass = sortsPtrs[strategy]->startSort(mass, size, _render);
        }
        sortsPtrs[strategy]->clearOperationsCounter();
        return mass;
    }
	return nullptr;//якщо код стратегії неправильний
}

void Strategy::initializeSortsPtrs (){
	sortsPtrs.insert(std::pair<Strats, Sorts*>(BubbleSort, SortFactory::CreateSortsObject(BubbleSort)));
	sortsPtrs.insert(std::pair<Strats, Sorts*>(ShakerSort, SortFactory::CreateSortsObject(ShakerSort)));
	sortsPtrs.insert(std::pair<Strats, Sorts*>(InsertionSort, SortFactory::CreateSortsObject(InsertionSort)));
	sortsPtrs.insert(std::pair<Strats, Sorts*>(StupidQuickSort, SortFactory::CreateSortsObject(StupidQuickSort)));
    sortsPtrs.insert(std::pair<Strats, Sorts*>(MedianQuickSort, SortFactory::CreateSortsObject(MedianQuickSort)));
}
