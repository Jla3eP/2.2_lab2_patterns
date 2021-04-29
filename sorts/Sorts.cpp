#include "Sorts.h"

Render* Sorts::render = new Render();

int *Sorts::startSort (int *mass, int size, bool _render){
	this->_mass = mass;
	this->_size = size;
	this->brender = _render;
	
	sort();
	if(_render){
		Clock plsWait;
		while ( plsWait.getElapsedTime().asMilliseconds() < 750 ) {}
	}
	return _mass;
}

void Sorts::findBigO (){
	int size = 200;
	int mass[size];
	operations = 0;
	int operations1 = 0;
	for(int i=0; i < 10 ;i++) {
		for (int i = 0; i < size; i++) {
			mass[i] = i;
		}
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		this->_mass = mass;
		this->_size = size;
		this->brender = 0;
		this->sort();
		operations1 += operations;
		operations = 0;
	}
	size *= 0.5;
	int mass2[size];
	int operations2 = 0;
	for(int i=0; i < 10;i++) {
		for (int i = 0; i < size; i++) {
			mass2[i] = i;
		}
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass2[rand() % size], mass2[rand() % size]);
		}
		
		this->_mass = mass2;
		this->_size = size;
		sort();
		operations2 += operations;
		operations = 0;
	}
	if (double(operations1) / operations2 < 2.2 * log2(2.4)) {
		this->info = "n*log(n)";
	}
	else if (double(operations1) / operations2 < 4.2) {
		this->info = "n^2";
	}
	else {
		this->info = ">n^2";
	}
	infoFlag = 0;
	operations = 0;
}

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
	return 1;
}

Sorts::Sorts (){

}

void bubbleSort::sort (){
	if(!infoFlag) {
		info += " bubble sort";
		infoFlag = 1;
	}
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size - 1; j++) {
			if (_mass[j] > _mass[j + 1]) {
				std::swap(_mass[j], _mass[j + 1]);
				if (brender) {
					render->draw(_mass, _size, 50, j, info);
				}
			}
			operations++;
		}
		if (checkSort (_mass, _size)) {
			if (brender && checkSort(_mass, _size)) {
				render->finalDraw(_mass, _size);
			}
			this->time = clock.getElapsedTime().asMilliseconds();
			return;
		}
	}
	
}

void shakerSort::sort (){
	if(!infoFlag) {
		info += " shaker sort";
		infoFlag = 1;
	}
	int begin = 0;
	int end = _size;
	for (int i = 0; i < _size; i++) {
		for (int j = begin; j < end; j++) {
			if (_mass[j] > _mass[j + 1]) {
				std::swap(_mass[j], _mass[j + 1]);
				if (brender) {
					this->render->draw(_mass, _size, 50, j + 1, info);
				}
				operations++;
			}
			if (_mass[_size - j] < _mass[_size - (j + 1)]) {
				std::swap(_mass[_size - j], _mass[_size - (j + 1)]);
				if (brender) {
					this->render->draw(_mass, _size, 50, _size - j - 1, info);
				}
				operations++;
			}
		}
		begin++;
		end--;
		if (checkSort(_mass, _size) || begin == end) {
			if (brender && checkSort(_mass, _size)) {
				render->finalDraw(_mass, _size);
			}
			time = clock.getElapsedTime().asMilliseconds();
			return;
		}
	}
}

void insertionSort::insert (int startPos, int endPos){
	if(startPos > endPos){
		int sp_elem = _mass[startPos];
		for (int i = startPos; i >= endPos; i--) {
			operations++;
			_mass[i] = _mass[i - 1];
			if (brender) {
				this->render->draw(_mass, _size, 60, endPos, info);
			}
		}
		_mass[endPos] = sp_elem;
	}
}

void insertionSort::sort (){
	if(!infoFlag) {
		info += " Insertion Sort";
		infoFlag = 1;
	}
	for (int k = 1; k < _size; k++) {
		if (_mass[k] < _mass[0]) {
			insert(k, 0);
		}
		for (int i = 1; i < k; i++) {
			if (_mass[i - 1] < _mass[k] && _mass[i] > _mass[k]) {
				insert(k, i);
				
				if (brender) {
					this->render->draw(_mass, _size, 50, k, info);
				}
				operations++;
				break;
			}
		}
	}
	if (brender && checkSort(_mass, _size)) {
		render->finalDraw(_mass, _size);
		return;
	}
}



int simpleQuickSort::quickSortMainLogic (int begin, int end, int opNumIter){
	if(begin == end){
		return opNumIter;
	}
	for (int i = 0; i <= _size * _size; i++) {
		if (begin < opNumIter && _mass[begin] > _mass[opNumIter]) {
			std::swap(_mass[begin], _mass[opNumIter]);
			opNumIter = begin;
			if (this->brender) {
				this->render->draw(_mass, _size, 2, opNumIter, info);
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
				if (this->brender) {
					this->render->draw(_mass, _size, 2, opNumIter);
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

void simpleQuickSort::sort (){
	if(!infoFlag) {
		info += " Simple Quick Sort";
		infoFlag = 1;
	}
	int opNumIter = _size - 1;
	int begin = 0;
	int end = _size - 1;
	
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	
	while (!checkSort(_mass, _size)) {
		quickSort(opNumIter - 1, 0, opNumIter);
		quickSort(_size - 1, opNumIter + 1, _size - 1);
	}
	
	if (brender && checkSort(_mass, _size)) {
		render->finalDraw(_mass, _size);
		return;
	}
}

void simpleQuickSort::quickSort (int opNumIter, int begin, int end){
	quickSortMainLogic(begin, end, opNumIter);
	while (!checkSort(_mass, end - begin, begin, end)) {
		quickSort(opNumIter - 1, begin, opNumIter);
		quickSort(_size - 1, opNumIter, end);
	}
}


int medianQuickSort::findMedian (int begin, int end){
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

void medianQuickSort::sort (){
	if (!infoFlag) {
		info += " Median Quick Sort";
		infoFlag = 1;
	}
	int opNumIter = findMedian(0, _size - 1);
	int begin = 0;
	int end = _size - 1;
	
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	
	//while (!checkSort(_mass, _size)) {
	
	while (!checkSort(_mass, opNumIter + 1, 0, opNumIter)) {
		quickSort(0, 0, opNumIter);
	}
	while (!checkSort(_mass, (_size - 1) - (opNumIter + 1) + 1)) {
		quickSort(0, opNumIter + 1, _size);
	}
	
	if (brender && checkSort(_mass, _size)) {
		render->finalDraw(_mass, _size);
		return;
	}
}

void medianQuickSort::quickSort (int _opNumIter, int begin, int end){//функція приймає опорний елемент, але не використовує тому-що наслідування
	int opNumIter = findMedian(begin, end);
	quickSortMainLogic(begin, end, opNumIter);
	while (!checkSort(_mass, end - begin, begin, end)) {
		//if(!checkSort(_mass, opNumIter - begin + 1, begin, opNumIter))
		quickSort(0, begin, opNumIter);
		
		//if(!checkSort(_mass, end - opNumIter, opNumIter, end))
		quickSort(0, opNumIter + 1, end);
	}
}
