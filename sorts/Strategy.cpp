#include "Strategy.h"

int *Strategy::sort (Sorts* sortsPtr, int *mass, int size, bool _render){
	while(!sortsPtr->checkSort(mass, size)) {
		mass = sortsPtr->startSort(mass, size, _render);
	}
	return mass;
}
