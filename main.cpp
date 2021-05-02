#include "UI/UI.h"
#include "sorts/Strategy.h"
#include <time.h>

int main (){
	srand(time(NULL));
	int size = 720;
	int mass[size];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < size; j++) {
			mass[j] = j;
		}
		
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		Strategy::sort(Strategy::BubbleSort, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(Strategy::ShakerSort, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(Strategy::InsertionSort, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(Strategy::StupidQuickSort, mass, size, 1);
		for (int j = 0; j < size * 5; j++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		Strategy::sort(Strategy::MedianQuickSort, mass, size, 1);
	}
}
