#ifndef SORTS_STRATEGY_H
#define SORTS_STRATEGY_H
#include "Sorts.h"


using std::map;

class Strategy {
	
	static map<int, Sorts*> sortsPtrs;
	static void setSortsPtrs();
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
