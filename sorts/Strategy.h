#ifndef SORTS_STRATEGY_H
#define SORTS_STRATEGY_H
#include "Sorts.h"
#include "Observer.h"
#include <vector>

using std::map;
using std::vector;

class Strategy {

public:
	enum{
		BubbleSort,
		ShakerSort,
		InsertionSort,
		StupidQuickSort,
		MedianQuickSort
	};
	// static int* sort (Sorts* sortsPtr,  int* mass, int size, bool _render);
	// non-static now because we notify observers here
	int* sort(int strategy, int* mass, int size, bool _render);

	void addObserver(Observer* o );

private:
    vector <Observer*> observers;
    void notify_observers(int * array, int size) const;
};


#endif //SORTS_STRATEGY_H
