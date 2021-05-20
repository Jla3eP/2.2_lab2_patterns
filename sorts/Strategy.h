#ifndef SORTS_STRATEGY_H
#define SORTS_STRATEGY_H
#include "Sorts.h"


using std::map;

class Strategy {
public:
	enum Strats{
		BubbleSort,
		ShakerSort,
		InsertionSort,
		StupidQuickSort,
		MedianQuickSort
	};
private:
	/**
	 * вказівники на об'єкти класів сортувань,
	 * важливо зберігати їх в одному екземплярі,
	 * так як в конструкторі викликається функція обчислення асимптотичної складності
	 */
	static map<Strats, Sorts*> sortsPtrs;
	
	static void initializeSortsPtrs();
public:
	static int* sort (Sorts* sortsPtr,  int*& mass, size_t size, bool _render);//альтернативний варіант виклику через існуючий об'єкт
	static int* sort (Strats strategy, int*& mass, size_t size, bool _render);
};


#endif //SORTS_STRATEGY_H
