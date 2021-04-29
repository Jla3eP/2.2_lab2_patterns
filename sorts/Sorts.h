#ifndef SORTS_SORTS_H
#define SORTS_SORTS_H

#include <cmath>
#include "../render/Render.h"



class Sorts {
protected:
	int* _mass;
	int _size;
	bool brender;
	
	Clock clock;
	float time;
	int operations = 0;
	
	string info = "";
	bool infoFlag = 0;
	
	void findBigO();
	
	virtual void sort() = 0;
	
public:
	static Render* render;
	bool checkSort(int* mass, int size, int a = -1, int b = -1);
	int* startSort(int* mass, int size, bool _render);
	Sorts();
};


class bubbleSort: public Sorts{
public:
	void sort()override;
	bubbleSort(): Sorts(){	findBigO();}
};

class shakerSort: public Sorts{
public:
	void sort()override;
	shakerSort(): Sorts(){	findBigO();}
};


class insertionSort: public Sorts{
	void insert(int posA, int posB);
public:
	void sort()override;
	insertionSort(): Sorts(){	findBigO();}
};

class simpleQuickSort:public Sorts{
protected:
	int quickSortMainLogic(int begin ,int end, int opNumIter);
	virtual void quickSort(int opNumIter, int begin, int end);
public:
	void sort()override;
	explicit simpleQuickSort(bool median = 0): Sorts(){if (!median) {findBigO();}}
};

class medianQuickSort: public simpleQuickSort{
	int findMedian(int begin, int end);
	void quickSort(int opNumIter, int begin, int end)override;
public:
	void sort()override;
	explicit medianQuickSort(): simpleQuickSort(true){	findBigO();}
};


#endif //SORTS_SORTS_H
