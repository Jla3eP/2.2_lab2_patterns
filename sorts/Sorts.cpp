#include "Sorts.h"

Render* Sorts::render = Render::getRender();

int *Sorts::startSort (int *array, size_t size, bool _render){
	this->_array = array;
	this->_arraySize = size;
	this->needVisualise = _render;
	
	sort();
	if(_render){
		render->clock.restart();
		while ( render->clock.getElapsedTime().asMilliseconds() < 750 ) {}//після завершення сортування невелика пауза
	}
	return _array;
}

void Sorts::findBigO (){
	int size = 200;
	int mass[size];
	operations = 0;
	int operations1 = 0;
	for(int i = 0; i < 20 ;i++) {//20 разів сортуємо масив розміром 10
		for (int i = 0; i < size; i++) {
			mass[i] = i;
		}
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		this->_array = mass;
		this->_arraySize = size;
		this->needVisualise = 0;
		this->sort();
		operations1 += operations;
		operations = 0;
	}
	size *= 0.5;//зменшуємо розмір масива вдвічі
	int mass2[size];
	int operations2 = 0;
	for(int i = 0; i < 20;i++) {//повторюємо для масиву нового розміру
		for (int i = 0; i < size; i++) {
			mass2[i] = i;
		}
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass2[rand() % size], mass2[rand() % size]);
		}
		
		this->_array = mass2;
		this->_arraySize = size;
		sort();
		operations2 += operations;
		operations = 0;
	}
	if (double(operations1) / operations2 < 2.2 * log2(2.4)) {//ураховуючи співвідношення кількості операцій, повертаємо приблизне значення складності
		this->info = "N log(N) ";
	}
	else if (double(operations1) / operations2 < 2.2 * log2(3.3)) {
		this->info = "N log^2(N) ";
	}
	else if (double(operations1) / operations2 < 4.3) {
		this->info = "N^2 ";
	}
	else {
		this->info = ">N^2 ";
	}
	infoFlag = 0;
	operations = 0;
}

bool Sorts::doesArraySorted (int *array, size_t size, int a, int b){
	if (a == -1 && b == -1) {
		a = 0;
		b = size - 1;
	}
	if (size > 0) {
		for (int i = a; i < b; i++) {
			if (array[i + 1] < array[i]) {
				return 0;
			}
		}
	}
	return 1;
}

void Sorts::clearOperationsCounter (){
	this->operations = 0;
}

void Sorts::drawArray (int sleepTime, int redElemIndex, string _info){
	render = Render::getRender();
	if (needVisualise) {
		render->draw(_array, _arraySize, sleepTime, redElemIndex, _info);
	}
}

void bubbleSort::sort (){
	if(!infoFlag) {
		info += " Bubble Sort";
		infoFlag = 1;
	}
	for (int i = 0; i < _arraySize; i++) {
		for (int j = 0; j < _arraySize - 1; j++) {
			if (_array[j] > _array[j + 1]) {
				std::swap(_array[j], _array[j + 1]);
				drawArray(200, j, info + "   " + std::to_string(operations));
				operations++;
			}
		}
		if (doesArraySorted(_array, _arraySize)) {
			if (needVisualise && doesArraySorted(_array, _arraySize)) {
				render->finalDraw(_array, _arraySize);
			}
			this->time = clock.getElapsedTime().asMilliseconds();
			return;
		}
	}
	
}

void shakerSort::sort (){
	if(!infoFlag) {
		info += " Shaker Sort";
		infoFlag = 1;
	}
	int begin = 0;
	int end = _arraySize;
	for (int i = 0; i < _arraySize; i++) {
		for (int j = begin; j < end; j++) {
			if (_array[j] > _array[j + 1]) {
				std::swap(_array[j], _array[j + 1]);
				drawArray(140, j + 1, info + "   " + std::to_string(operations));
				operations++;
			}
			if (_array[_arraySize - j] < _array[_arraySize - (j + 1)]) {
				std::swap(_array[_arraySize - j], _array[_arraySize - (j + 1)]);
				drawArray(140, _arraySize - j - 1, info + "   " + std::to_string(operations));
				operations++;
			}
		}
		begin++;
		end--;
		if (doesArraySorted(_array, _arraySize) || begin == end) {
			if (needVisualise && doesArraySorted(_array, _arraySize)) {
				render->finalDraw(_array, _arraySize);
			}
			time = clock.getElapsedTime().asMilliseconds();
			return;
		}
	}
}

void insertionSort::insert (int startPos, int endPos){
	if(startPos > endPos){
		int sp_elem = _array[startPos];
		for (int i = startPos; i >= endPos; i--) {
			operations++;
			_array[i] = _array[i - 1];
			drawArray(140, endPos, info + "   " + std::to_string(operations));
		}
		_array[endPos] = sp_elem;
	}
}

void insertionSort::sort (){
	if(!infoFlag) {
		info += " Insertion Sort";
		infoFlag = 1;
	}
	for (int k = 1; k < _arraySize; k++) {
		if (_array[k] < _array[0]) {
			insert(k, 0);
		}
		for (int i = 1; i < k; i++) {
			operations++;
			if (_array[i - 1] < _array[k] && _array[i] > _array[k]) {
				insert(k, i);
				drawArray(140, k, info + "   " + std::to_string(operations));
				break;
			}
		}
	}
	if (needVisualise && doesArraySorted(_array, _arraySize)) {
		render->finalDraw(_array, _arraySize);
		return;
	}
}



int simpleQuickSort::quickSortMainLogic (int begin, int end, int opNumIter){
	if(begin == end){
		return opNumIter;
	}
	for (int i = 0; i <= _arraySize * _arraySize; i++) {
		if (begin < opNumIter && _array[begin] > _array[opNumIter]) {
			std::swap(_array[begin], _array[opNumIter]);
			opNumIter = begin;
			drawArray(5, opNumIter, info + "   " + std::to_string(operations));
			
			operations++;
		}else {
			begin++;
		}
		if (end > opNumIter) {
			if (_array[end] <= _array[opNumIter]) {
				std::swap(_array[opNumIter + 1], _array[end]);
				std::swap(_array[opNumIter], _array[opNumIter + 1]);
				opNumIter++;
				end++;
				drawArray(5, opNumIter, info + "   " + std::to_string(operations));
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
	int opNumIter = _arraySize - 1;
	int begin = 0;
	int end = _arraySize - 1;
	
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	
	while (!doesArraySorted(_array, _arraySize)) {
		quickSort(opNumIter - 1, 0, opNumIter);
		quickSort(_arraySize - 1, opNumIter + 1, _arraySize - 1);
	}
	
	if (needVisualise && doesArraySorted(_array, _arraySize)) {
		render->finalDraw(_array, _arraySize);
		return;
	}
}

void simpleQuickSort::quickSort (int opNumIter, int begin, int end){
	quickSortMainLogic(begin, end, opNumIter);
	while (!doesArraySorted(_array, end - begin, begin, end)) {
		quickSort(opNumIter - 1, begin, opNumIter);
		quickSort(_arraySize - 1, opNumIter, end);
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
	int opNumIter = findMedian(0, _arraySize - 1);
	int begin = 0;
	int end = _arraySize - 1;
	
	opNumIter = quickSortMainLogic(begin, end, opNumIter);
	
	while (!doesArraySorted(_array, opNumIter + 1, 0, opNumIter)) {
		quickSort(0, 0, opNumIter);
	}
	while (!doesArraySorted(_array, (_arraySize - 1) - (opNumIter + 1) + 1)) {
		quickSort(0, opNumIter + 1, _arraySize);
	}
	
	if (needVisualise && doesArraySorted(_array, _arraySize)) {
		render->finalDraw(_array, _arraySize);
		return;
	}
}

void medianQuickSort::quickSort (int _opNumIter, int begin, int end){//функція приймає опорний елемент, але не використовує тому-що наслідування
	int opNumIter = findMedian(begin, end);
	quickSortMainLogic(begin, end, opNumIter);
	while (!doesArraySorted(_array, end - begin, begin, end)) {
		quickSort(0, begin, opNumIter);
		quickSort(0, opNumIter + 1, end);
	}
}
