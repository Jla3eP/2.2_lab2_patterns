#ifndef SORTS_LAB_18_03_21_SORTS_H
#define SORTS_LAB_18_03_21_SORTS_H
#include "Render.h"
#include <string>
#include <cmath>
using std::string;

class Sorts {
public:
	Clock clock;
	float time;
	int operations = 0;
	Render* render = new Render;
	int* bubbleSort(int* mass, int size, bool render);
	int* shakerSort(int* mass, int size, bool render);
	bool checkSort(int* mass, int size);
	string findO(int* (Sorts::*sortFunc)(int*, int, bool));
	void checkFuncs();
};


#endif //SORTS_LAB_18_03_21_SORTS_H
