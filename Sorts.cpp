#include <iostream>
#include "Sorts.h"

bool Sorts::checkSort (int *mass, int size){
	for (int i = 0; i < size - 1; i++) {
		if (mass[i] > mass[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int *Sorts::bubbleSort (int *mass, int size, bool _render){
	clock.restart();
	operations = 0;
	while ( this->render->window->isOpen()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (mass[j] > mass[j + 1]) {
					std::swap(mass[j], mass[j + 1]);
				}
				if (_render) {
					this->render->draw(mass, size, 150);
				}
				operations++;
			}
			if (checkSort(mass, size)) {
				time = clock.getElapsedTime().asMilliseconds();
				return mass;
			}
		}
	}
}


int *Sorts::shakerSort (int *mass, int size, bool _render){
	clock.restart();
	operations = 0;
	while ( this->render->window->isOpen()) {
		int begin = 0;
		int end = size;
		for (int i = 0; i < size; i++) {
			for (int j = begin; j < end; j++) {
				if (mass[j] > mass[j + 1]) {
					std::swap(mass[j], mass[j + 1]);
				}
				if (mass[size - j] < mass[size - (j + 1)]) {
					std::swap(mass[size - j], mass[size - (j + 1)]);
				}
				if (_render) {
					this->render->draw(mass, size, 30);
				}
				operations++;
			}
			begin++;
			end--;
			if (checkSort(mass, size)) {
				time = clock.getElapsedTime().asMilliseconds();
				return mass;
			}
		}
	}
}

string Sorts::findO (int *(Sorts::*sortFunc) (int *, int, bool)){
	int size = 1080;
	int mass[size];
	for (int i = 0; i < size; i++) {
		mass[i] = i;
	}
	for (int i = 0; i < size * 5; i++) {
		std::swap(mass[rand() % size], mass[rand() % size]);
	}
	
	(this->*sortFunc)(mass, size, 0);
	double operations1 = operations;
	
	size *= 0.5;
	int mass2[size];
	for (int i = 0; i < size; i++) {
		mass2[i] = i;
	}
	for (int i = 0; i < size * 5; i++) {
		std::swap(mass2[rand() % size], mass2[rand() % size]);
	}
	(this->*sortFunc)(mass2, size, 0);
	double operations2 = operations;
	
	if (operations1 / operations2 < 2.2 * log10(2)) {
		return "n*log(n)";
	}else if (operations1 / operations2 < 4.2) {
		return "n^2";
	}else {
		return ">n^2";
	}
	
	
}

void Sorts::checkFuncs (){
	int *(Sorts::*sortFunc) (int *, int, bool);
	sortFunc = &Sorts::shakerSort;
	std::cout << findO(sortFunc);
}


