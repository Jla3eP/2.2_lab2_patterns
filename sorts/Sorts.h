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
	
	Render* render;
	
	virtual void sort() = 0;
	
public:
	bool checkSort(int* mass, int size, int a = -1, int b = -1);
	int* startSort(int* mass, int size, bool _render);
	explicit Sorts(Render* render);
};


class bubbleSort: public Sorts{
public:
	void sort()override;
	bubbleSort(Render* render): Sorts(render){	findBigO();}
};

class shakerSort: public Sorts{
public:
	void sort()override;
	shakerSort(Render* render): Sorts(render){	findBigO();}
};


class insertionSort: public Sorts{
	void insert(int posA, int posB);
public:
	void sort()override;
	insertionSort(Render* render): Sorts(render){	findBigO();}
};

class stupidQuickSort: public Sorts{
protected:
	int quickSortMainLogic(int begin ,int end, int opNumIter);
	virtual void quickSort(int opNumIter, int begin, int end);
public:
	void sort()override;
	explicit stupidQuickSort(Render* render, bool median = 0):
			Sorts(render){if (!median) {findBigO();}}
};

class medianQuickSort: public stupidQuickSort{
	int findMedian(int begin, int end);
	void quickSort(int opNumIter, int begin, int end)override;
public:
	void sort()override;
	explicit medianQuickSort(Render* render): stupidQuickSort(render, true){	findBigO();}
};
#endif //SORTS_SORTS_H
