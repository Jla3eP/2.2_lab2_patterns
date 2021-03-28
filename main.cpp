#include <iostream>
#include "Sorts.h"

int main (){
	srand(time(NULL));
	int size = 1080;
	int mass[size];
	for (int i = 0; i < size; i++) {
		mass[i] = i;
	}
	for (int i = 0; i < size * 5; i++) {
		std::swap(mass[rand() % size], mass[rand() % size]);
	}
	Sorts sorts;
	sorts.bubbleSort(mass, size, 1);
	
	std::cout<<sorts.findO(&Sorts::bubbleSort);
}
