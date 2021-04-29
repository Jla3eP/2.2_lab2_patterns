#include "UI/UI.h"
#include "sorts/Strategy.h"

int main (){
	srand(time(NULL));
	Strategy* strategy = new Strategy;
	//Render* render = new Render;
	
	Sorts* sqs = new stupidQuickSort;
	Sorts* mqs = new medianQuickSort;
	Sorts* bs = new bubbleSort;
	Sorts* ss = new shakerSort;
	Sorts* is = new insertionSort;
	int size = 720;
	int mass[size];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < size; j++) {
			mass[j] = j;
		}
		
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		strategy->sort(bs, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		strategy->sort(ss, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		strategy->sort(is, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		strategy->sort(sqs, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		strategy->sort(mqs, mass, size, 1);
	}
}
