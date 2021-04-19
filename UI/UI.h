#ifndef SORTS_LAB_18_03_21_UI_H
#define SORTS_LAB_18_03_21_UI_H
#include "../sorts/Sorts.h"

class UI {
	Clock clock;
	RenderWindow* window = nullptr;
	Sorts sorts;
	//int* array = nullptr;
	int arraySize = 720;
	
	Font font1;
	Font font2;
	
	const int textSize = 135;
	const int voidSize = 35;
	
	void createArray();
	void start();
	void settings();
	void exit();
public:
	UI();
};


#endif //SORTS_LAB_18_03_21_UI_H
