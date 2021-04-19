#include <iostream>
#include "UI/UI.h"

int main (){
	
	
	srand(time(NULL));
	Sorts sorts;
	
	for (int i = 19; i < 40; i++) {
		int size = 720;
		int mass[size];
		
		for (int i = 0; i < size; i++) {
			mass[i] = i;
		}
		
		for (int i = 0; i < size * 5; i++) {
			std::swap(mass[rand() % size], mass[rand() % size]);
		}
		
		sorts.startSort(&Sorts::medianQuickSort, mass, size, 1);
		
		//sorts._mass = mass;
		//std::cout<<sorts.findMedian(0, size-1)<<std::endl;
		
		//sorts.adapter(&Sorts::shakerSort, mass, size, 1);
	}
	//UI ui;
	
	
	//sorts.checkFuncs();
	//Sorts sorts;
	//std::cout << sorts.findO(&Sorts::stupidQuickSort);
	
}
