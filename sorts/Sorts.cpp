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

int *Sorts::quickSort (int *mass, const int size, bool _render){
	_mass=mass;
	const int opNum = mass[size - 1];
	int opNumIter = size - 1;
	int begin = 0;
	int end = size - 1;
	
	for (int i = 0; i < size; i++) {
		if (begin < opNumIter && mass[begin] > mass[opNumIter]) {
			std::swap(mass[begin], mass[opNumIter]);
			opNumIter = begin;
			if (_render) {
				this->render->draw(mass, size, 10);
			}
			operations++;
		}else {
			begin++;
		}
		if (end > opNumIter) {
			if (mass[end] <= mass[opNumIter]) {
				std::swap(mass[opNumIter + 1], mass[end]);
				std::swap(mass[opNumIter], mass[opNumIter + 1]);
				opNumIter++;
				end--;
				if (_render) {
					this->render->draw(mass, size, 10);
				}
				operations++;
			}else {
				end--;
			}
		}
	}
	
	if (!checkSort(mass, size)) {
		mass = quickSort(size, _render, opNumIter - 1, 0, opNumIter);
		mass = quickSort(size, _render, size - 1, opNumIter + 1, size - 1);
	}
	return mass;
	
}

int *Sorts::quickSort (int size, bool _render, int opNumIter, int begin, int end){
	int startBegin = begin;
	int startEnd = end;
	const int opNum = _mass[opNumIter];
	for (int i = 0; i < size; i++) {
		if (begin < opNumIter && _mass[begin] > _mass[opNumIter]) {
			std::swap(_mass[begin], _mass[opNumIter]);
			opNumIter = begin;
			if (_render) {
				this->render->draw(_mass, size, 5);
			}
			operations++;
		}else {
			begin++;
		}
		if (end > opNumIter) {
			if (_mass[end] <= _mass[opNumIter]) {
				std::swap(_mass[opNumIter + 1], _mass[end]);
				std::swap(_mass[opNumIter], _mass[opNumIter + 1]);
				opNumIter++;
				end--;
				if (_render) {
					this->render->draw(_mass, size, 5);
				}
				operations++;
			}else {
				end--;
			}
			
		}
		/*else{
			if (begin < opNumIter) {
				break;
			}
		}*/
		
	}
	if (!checkSort(podMass(_mass, startBegin, startEnd), startEnd - startBegin)) {
		_mass = quickSort(size, _render, opNumIter - 1, startBegin, opNumIter);
		_mass = quickSort(size, _render, size - 1, opNumIter + 1, startEnd);
	}
	return _mass;
	
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
	std::cout << findO(sortFunc) << std::endl;
}

int *Sorts::startSort (int *(Sorts::*sortFunc) (int *, int, bool), int *mass, int size, bool render){
	clock.restart();
	operations = 0;
	while ( this->render->window->isOpen()) {
		
		(this->*sortFunc)(mass, size, render);
		
		if (checkSort(mass, size)) {
			time = clock.getElapsedTime().asMilliseconds();
			return mass;
		}
	}
}

int *Sorts::podMass (int *mass, int a, int b){
	if (b >= a) {
		int *mmass = new int[b - a + 1];
		int iter = 0;
		for (int i = a - 1; i < b; i++) {
			mmass[iter] = mass[i];
			iter++;
		}
		return mmass;
	}else {
		return nullptr;
	}
}








