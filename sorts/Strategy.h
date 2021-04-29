#ifndef SORTS_STRATEGY_H
#define SORTS_STRATEGY_H
#include "Sorts.h"

class Strategy {
	
	static std::map<int, Sorts*> sortsPtrs;
	static std::map<int, Sorts*> getSortsPtrs();
public:
	enum{
		BubbleSort,
		ShakerSort,
		InsertionSort,
		StupidQuickSort,
		MedianQuickSort
	};
	static int* sort (Sorts* sortsPtr,  int* mass, int size, bool _render);
	static int* sort(int strategy, int* mass, int size, bool _render);
};


#endif //SORTS_STRATEGY_H
