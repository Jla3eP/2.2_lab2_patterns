#ifndef SORTS_LAB_18_03_21_SORTS_H
#define SORTS_LAB_18_03_21_SORTS_H

#include "../render/Render.h"
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <cmath>

using std::string;
using std::vector;
using std::list;
using std::iterator;

class Sorts {
public:
	~Sorts ();
	
	int *_mass;
	int _size;
	bool _render = 0;
	
	
	Clock clock;
	float time;
	int operations = 0;
	
	Render *render = new Render;
	
	int *bubbleSort (int *mass, int size, bool render);
	
	int *shakerSort (int *mass, int size, bool render);
	
	int *stupidQuickSort (int *mass, int size, bool render);
	
	int *medianQuickSort(int *mass, int size, bool render);
	
	int *medianQuickSort(int begin, int end);
	
	int quickSortMainLogic(int begin, int end, int opNumIter);
	
	void stupidQuickSort (const int opNumIter, int begin, int end);
	
	bool checkSort (int *mass, int size, int a = -1, int b = -1);
	
	string findO (int *(Sorts::*sortFunc) (int *, int, bool));
	
	int *startSort (int *(Sorts::*sortFunc) (int *, int, bool), int *mass, int size, bool render);//вызов сортировки через указатель на метод, при котором гарантированно не ломается счётчик операций и времени
	
	void checkFuncs ();
	
	int findMedian(int begin, int end);
	
	template <typename T>
	T adapter(int *(Sorts::*sortFunc) (int *, int, bool), T mass, int size, bool render);
	
};


#endif //SORTS_LAB_18_03_21_SORTS_H
