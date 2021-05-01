#include "Strategy.h"
#include "Factory.h"

/*
 * int *Strategy::sort (Sorts* sortsPtr, int *mass, int size, bool _render){
	while(!sortsPtr->doesArraySorted(mass, size)) {
		mass = sortsPtr->startSort(mass, size, _render);
	}
	return mass;
}
 */

/**
 *
 * @param strategy смотреть enum в Strategy
 */
int *Strategy::sort (int strategy, int *mass, int size, bool _render){
	Sorts* sortPtr = SortFactory::CreateSortsObject(strategy);
	if(sortPtr != NULL) {
		while ( !sortPtr->doesArraySorted(mass, size)) {
			mass = sortPtr->startSort(mass, size, _render);
		}
        sortPtr->clearOperationsCounter();
		return mass;
	}
}

