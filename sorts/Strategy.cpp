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
		notify_observers(mass, size);
		return mass;
	}
}

void Strategy::notify_observers(int * array, int size) const
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i]->update(array, size);

    }
}

void Strategy::addObserver(Observer* o )
{
    observers.push_back(o);
}

