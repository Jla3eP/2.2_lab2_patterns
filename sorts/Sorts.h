#ifndef SORTS_LAB_18_03_21_SORTS_H
#define SORTS_LAB_18_03_21_SORTS_H
#include "../render/Render.h"
#include <string>
#include <cmath>
using std::string;

class Sorts {
public:
	int *_mass;
	Clock clock;
	float time;
	int operations = 0;
	Render* render = new Render;
	int* bubbleSort(int* mass, int size, bool render);
	int* shakerSort(int* mass, int size, bool render);
	int* quickSort(int* mass, int size, bool render);
	int* quickSort(int size, bool render, const int opNumIter, int begin, int end);
	bool checkSort(int* mass, int size);
	string findO(int* (Sorts::*sortFunc)(int*, int, bool));
	int* startSort(int* (Sorts::*sortFunc)(int*, int, bool), int* mass, int size, bool render);//вызов сортировки через указатель на метод, при котором гарантированно не ломается счётчик операций и времени
	void checkFuncs();//вспомнить, зачем это нужно, upd: пример правильного вызова findO/////////////////////////////////////////////////////////////////
	int* podMass(int* mass, int a, int b);
};


#endif //SORTS_LAB_18_03_21_SORTS_H
