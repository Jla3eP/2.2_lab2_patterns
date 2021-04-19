#include <iostream>
#include "Sorts.h"

bool Sorts::checkSort (int *mass, int size, int a, int b){
	if (a == -1 && b == -1) {
		a = 0;
		b = size - 1;
	}
	if (size > 0) {
		for (int i = a; i < b; i++) {
			if (mass[i + 1] < mass[i]) {
				return 0;
			}
		}
	}
	
	mass = nullptr;
	//delete mass;
	return 1;
}

int *Sorts::bubbleSort (int *mass, int size, bool _render){
	clock.restart();
	operations = 0;
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


int *Sorts::shakerSort (int *mass, int size, bool _render){
	clock.restart();
	operations = 0;
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

int Sorts::quickSortMainLogic (int begin, int end, int opNumIter){
	if(begin == end){
		return opNumIter;
	}
	for (int i = 0; i <= _size * _size; i++) {
		if (begin < opNumIter && _mass[begin] > _mass[opNumIter]) {
			std::swap(_mass[begin], _mass[opNumIter]);
			opNumIter = begin;
			if (this->_render) {
				this->render->draw(_mass, _size, 2);
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
				end++;
				if (this->_render) {
					this->render->draw(_mass, _size, 2);
				}
				operations++;
			}else {
				end--;
			}
		}
		else if(begin > opNumIter){
			break;
		}
	}
	return opNumIter;
}

int *Sorts::stupidQuickSort (int *mass, const int size, bool nrender){
	this->_mass = mass;
	this->_size = size;
	this->_render = nrender;
	
	int opNumIter = size - 1;
	int begin = 0;
	int end = size - 1;
	
	quickSortMainLogic(begin, end, opNumIter);
	
	while (!checkSort(_mass, size)) {
		stupidQuickSort(opNumIter - 1, 0, opNumIter);
		stupidQuickSort(size - 1, opNumIter + 1, size - 1);
	}
	
	return _mass;
	
}

void Sorts::stupidQuickSort (int opNumIter, int begin, int end){
	quickSortMainLogic(begin, end, opNumIter);
	while (!checkSort(_mass, end - begin, begin, end)) {
		stupidQuickSort(opNumIter - 1, begin, opNumIter);
		stupidQuickSort(_size - 1, opNumIter, end);
	}
}

int *Sorts::medianQuickSort (int *mass, int size, bool render){
	_mass = mass;
	_size = size;
	this->_render = render;
	
	int opNumIter = findMedian(0, size - 1);
	int begin = 0;
	int end = size - 1;
	
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	
	//while (!checkSort(_mass, size)) {
		
	while (!checkSort(_mass, opNumIter + 1, 0, opNumIter)) {
		medianQuickSort(0, opNumIter);
	}
	while (!checkSort(_mass, (size - 1) - (opNumIter + 1) + 1)) {
		medianQuickSort(opNumIter + 1, size - 1);
	}
	
	
	return _mass;
}

int *Sorts::medianQuickSort (int begin, int end){
	int opNumIter = findMedian(begin, end);
	quickSortMainLogic(begin, end, opNumIter);
	while (!checkSort(_mass, end - begin, begin, end)) {
		//if(!checkSort(_mass, opNumIter - begin + 1, begin, opNumIter))
			medianQuickSort(begin, opNumIter);
		
		//if(!checkSort(_mass, end - opNumIter, opNumIter, end))
			medianQuickSort(opNumIter + 1, end);
	}
}

int Sorts::findMedian (int begin, int end){
	if(end == begin){
		return begin;
	}
	int opNumIter = begin + ((end - begin) / 2);
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	if (opNumIter > (end + begin) / 2) {
		return findMedian(opNumIter, end);
	}
	else{
		return findMedian(begin, opNumIter);
	}
}

string Sorts::findO (int *(Sorts::*sortFunc) (int *, int, bool)){
	int size = 720;
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
	
	if (operations1 / operations2 < 2.2 * log2(1.5)) {
		return "N*log(N)";
	}else if (operations1 / operations2 < 4.2) {
		return "N^2";
	}else {
		return ">N^2";
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
	
	(this->*sortFunc)(mass, size, render);
	
	time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	if(render) {
		while ( clock.getElapsedTime().asSeconds() < 1 ) {}
	}
	return mass;
	
}


/*int *Sorts::podMass (int *mass, int a, int b){
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
}*/

Sorts::~Sorts (){
	delete render;
}

template<>
vector <int> Sorts::adapter (int *(Sorts::*sortFunc) (int *, int, bool), vector <int> mass, int size, bool render){
	int *array = new int[mass.size()];
	std::copy(mass.begin(), mass.end(), array);
	array = startSort(sortFunc, array, size, render);
	vector <int> dest(array, array + sizeof(array) / sizeof(array[0]));
	return dest;
}

template<>
list <int> Sorts::adapter (int *(Sorts::*sortFunc) (int *, int, bool), list <int> mass, int size, bool render){
	int *array = new int[mass.size()];
	//std::copy(mass.begin(), mass.end(), array);
	int k = 0;
	for (int const &i: mass) {
		array[k++] = i;
	}
	array = startSort(sortFunc, array, size, render);
	std::list <int> ints;
	for (int i = 0; i < size; i++) {
		ints.push_back(array[i]);
	}
	return ints;
}
