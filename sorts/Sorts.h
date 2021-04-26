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
	bool brender = 0;
	
	
	Clock clock;
	float time;
	int operations = 0;
	
	Render *render = new Render;
	
	int *bubbleSort (int *mass, int size, bool render);
	
	int *shakerSort (int *mass, int size, bool render);
	
	int *insertionSort (int *mass, int size, bool render);
	
	void insert(int posA, int posB);
	
	virtual int *graphicalSort (int *mass, int size, bool render) = 0;
	
	int quickSortMainLogic(int begin, int end, int opNumIter);

	
	bool checkSort (int *mass, int size, int a = -1, int b = -1);
	
	string findO (int *(Sorts::*sortFunc) (int *, int, bool));
	
	int *startSort ( int *mass, int size, bool render);//вызов сортировки через указатель на метод, при котором гарантированно не ломается счётчик операций и времени
	
	void checkFuncs ();
	
	int findMedian(int begin, int end);
	
	template <typename T>
	T adapter(T mass, int size, bool render);
	
};
class StupidQuickSort : public Sorts
{
    void sort (int opNumIter, int begin, int end) ;

public:
    int* graphicalSort (int *mass, const int size, bool nrender) override;
};
class MedianQuickSort : public Sorts
{
    void sort (int begin, int end) ;

public:
    int* graphicalSort (int *mass, const int size, bool nrender) override;
};


#endif //SORTS_LAB_18_03_21_SORTS_H
