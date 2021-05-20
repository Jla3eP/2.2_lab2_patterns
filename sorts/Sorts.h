#ifndef SORTS_SORTS_H
#define SORTS_SORTS_H

#include <cmath>
#include "../render/Render.h"


class Sorts {
protected:
	int *_array;
	size_t _arraySize;
	bool needVisualise;//1 - необхідна візуалізація, 0 - ні
	
	Clock clock;
	float time;//час, за який відсортується масив
	int operations = 0;
	
	string info = "";//інформація, яка буде пізніше використовуватись в рендері
	bool infoFlag = 0;//для запобігання записування інформації декілька разів
	
	void findBigO ();//пошук асимптотичної складності
	
	virtual void sort () = 0;

	void drawArray(int sleepTime, int redElemIndex, string _info);
public:
	static Render *render;
	
	bool doesArraySorted (int *array, size_t size, int a = -1, int b = -1);
	
	int *startSort (int *array, size_t size, bool _render);
	
	void clearOperationsCounter();
};


class bubbleSort:public Sorts {
public:
	void sort () override;
	
	bubbleSort () : Sorts(){findBigO();}
};

class shakerSort:public Sorts {
public:
	void sort () override;
	
	shakerSort () : Sorts(){findBigO();}
};


class insertionSort:public Sorts {
	void insert (int posA, int posB);

public:
	void sort () override;
	
	insertionSort () : Sorts(){findBigO();}
};

class simpleQuickSort:public Sorts {
protected:
	int quickSortMainLogic (int begin, int end, int opNumIter);
	
	virtual void quickSort (int opNumIter, int begin, int end);

public:
	void sort () override;
	
	explicit simpleQuickSort (bool median = 0) : Sorts(){if (!median) {findBigO();}}
};

class medianQuickSort:public simpleQuickSort {
	int findMedian (int begin, int end);
	
	void quickSort (int opNumIter, int begin, int end) override;

public:
	void sort () override;
	
	explicit medianQuickSort () : simpleQuickSort(true){findBigO();}
};

#endif //SORTS_SORTS_H
