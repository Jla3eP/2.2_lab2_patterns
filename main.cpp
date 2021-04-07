#include <iostream>
#include "sorts/Sorts.h"

int main (){
	
	
	srand(time(NULL));
	Sorts sorts;
	
	for (int i = 0; i < 40; i++) {
		int size = 1080;
		int mass[size];
		for (int i = 0; i < size; i++) {
			mass[i] = i;
		}
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		sorts.quickSort(mass, size, 1);
	}
	sorts.checkFuncs();
	
	std::cout << sorts.findO(&Sorts::shakerSort);
	
}
