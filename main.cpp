#include "UI/UI.h"
#include "sorts/Strategy.h"

int main (){
	srand(time(NULL));
	//Strategy* strategy = new Strategy;
	//Render* render = new Render;
	
	/*Sorts* sqs = new simpleQuickSort;
	Sorts* mqs = new medianQuickSort;
	Sorts* bs = new bubbleSort;
	Sorts* ss = new shakerSort;
	Sorts* is = new insertionSort;*/
	int size = 720;
	int mass[size];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < size; j++) {
			mass[j] = j;
		}
		
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		Strategy::sort(0, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(1, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(2, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(3, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(4, mass, size, 1);
	}
}
