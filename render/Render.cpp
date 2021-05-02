#include "Render.h"

bool Render::doesItExist = 0;
Render* Render::renderPtr = nullptr;

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
	infoText.setPosition(/*double(this->window->getSize().x / 2 - 250)*/5, double(this->window->getSize().y) - infoSize - 5);
	infoText.setFillColor(Color(255,0,0,255));
	
	window->draw(infoText);
	window->display();
	clock.restart();
}

Render::Render (RenderWindow* _window){

	renderPtr = this;
	doesItExist = 1;
	this->window = _window;
	font.loadFromFile("../20647.ttf");
	//this->window->setFramerateLimit(60);
}

void Render::draw (int *mass, int size, int sleepTime, int redElemIndex, string _info){
	int trueSleepTime = (double (size * size) / (1080 * 1080)) * sleepTime;
	if (clock.getElapsedTime().asMicroseconds() >= trueSleepTime) {
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
	doesItExist = 0;
	renderPtr = nullptr;
}

void Render::finalDraw (int *mass, int size){
	float sleepTime = float(500) / size;
	int currentLastGreenIndex = 1;
	do{
		if(clock.getElapsedTime().asMilliseconds() >= sleepTime){
			currentLastGreenIndex += 2;
			visualize(mass, size, currentLastGreenIndex, 1);
		}
	}while(currentLastGreenIndex <= size);
	
	
}

Render *Render::createRender (){
	if(doesItExist){
		return renderPtr;
	}
	else{
		return new Render;
	}
}

void Render::deleteRender (){
	delete Render::renderPtr;
	Render::doesItExist = 0;
}
