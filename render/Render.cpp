#include "Render.h"

Render* Render::renderPtr = nullptr;

/**
 * малюємо масив
 * @param redElemIndex індекс елемента, який необхідно зробити червоним
 * @param greenField 1 - замалювати поле зеленим до redElemIndex
 */
void Render::visualize (int mass[], int size, int redElemIndex, bool greenField){
	if (window == nullptr) {
		window = new RenderWindow(VideoMode(1080, 720), "");
	}
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	double xSize = window->getSize().x / double(size);
	double ySize = double(window->getSize().y - infoSize) / double(max);
	window->clear(Color(0, 0, 0, 0));
	float xSum = 0;
	for (int i = 0; i < size; i++) {
		RectangleShape element(Vector2f(xSize, mass[i] * ySize));
		element.setPosition(xSize * double(i), double(window->getSize().y) - mass[i] * ySize - infoSize);
		xSum += xSize;
		element.setFillColor(Color(255, 255, 255, 255));
		if(i == redElemIndex){
			element.setFillColor(Color(255,0,0,255));
		}
		if(greenField && i < redElemIndex){
			element.setFillColor(Color(0, 255, 0, 255));
		}
		window->draw(element);
	}
	Text infoText(info ,font, infoSize);
	infoText.setPosition(5, double(this->window->getSize().y) - infoSize - 5);
	infoText.setFillColor(Color(255,0,0,255));
	
	window->draw(infoText);
	window->display();
	clock.restart();
}

Render::Render (RenderWindow* _window){
	this->window = _window;
	font.loadFromFile("../20647.ttf");
}

void Render::draw (int *mass, int size, int sleepTime, int redElemIndex, string _info){
	int trueSleepTime = (double (size * size) / (1080 * 1080)) * sleepTime;//адаптуємо sleepTime під розмір масива відносно розміру 1080
	if (clock.getElapsedTime().asMicroseconds() >= trueSleepTime) {//якщо з останньої візуалізації пройшло досить часу, запускаємо visualize
		if(!_info.empty()){
			this->info = _info;
		}
		visualize(mass, size, redElemIndex);
	}
}

Render::~Render (){
	if (window != nullptr && window->isOpen()) {
		window->close();
		delete window;
	}
	renderPtr = nullptr;
}

void Render::finalDraw (int *mass, int size){
	float sleepTime = float(500) / size;
	int currentLastGreenIndex = 1;
	do{//малюємо зелені лінії доти, доки всі лінії не стануть зеленими
		if(clock.getElapsedTime().asMilliseconds() >= sleepTime){
			currentLastGreenIndex += 2;
			visualize(mass, size, currentLastGreenIndex, 1);
		}
	}while(currentLastGreenIndex <= size);
}

Render *Render::getRender (){//частина реалізації singleton
	if(renderPtr != nullptr){
		return renderPtr;
	}
	else{
		Render* rnd = new Render;
		renderPtr = rnd;
		return rnd;
	}
}

void Render::deleteRender (){
	delete Render::renderPtr;
	renderPtr = nullptr;
}
