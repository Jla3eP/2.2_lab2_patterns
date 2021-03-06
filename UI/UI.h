#ifndef SORTS_LAB_18_03_21_UI_H
#define SORTS_LAB_18_03_21_UI_H
#include "../sorts/Strategy.h"
#include <string>
#include "SFML/Graphics.hpp"

using namespace sf;
using std::string;

class UI {
	enum{
		DEFAULT = 720//розмір масиву за замовчуванням
	};
	enum{
		DEMO_MODE = 0,
		BUBBLE_SORT,
		SHAKER_SORT,
		INSERTION_SORT,
		SIMPLE_QUICK_SORT,
		MEDIAN_QUICK_SORT
	};
	
	int mode = DEMO_MODE;//режим роботи за замовчуванням
	
	Clock clock;
	RenderWindow* window = nullptr;
	int* array;
	size_t arraySize = 720;
	
	Font font1;
	Font font2;
	
	int textSize = 110;
	int voidSize = 35;//відстань між строками в пікселях
	
	void createArray();
	void start();
	void settings();
	void exit();
public:
	UI();
};


#endif //SORTS_LAB_18_03_21_UI_H
