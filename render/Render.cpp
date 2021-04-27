#include "Render.h"


void Render::visualize (int mass[], int size){
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
		window->draw(element);
	}
	Text infoText(info ,font, infoSize);
	infoText.setPosition(double(this->window->getSize().x / 2 - 150), double(this->window->getSize().y) - infoSize);
	window->draw(infoText);
	window->display();
	clock.restart();
}

Render::Render (RenderWindow* _window){
	this->window = _window;
	font.loadFromFile("../WIDEAWAKE.ttf");
	//this->window->setFramerateLimit(60);
}

void Render::draw (int *mass, int size, int sleepTime, string _info){
	int trueSleepTime = (double (size * size) / (1080 * 1080)) * sleepTime;
	if (clock.getElapsedTime().asMicroseconds() >= trueSleepTime) {
		if(!_info.empty()){
			this->info = _info;
		}
		visualize(mass, size);
	}
}

Render::~Render (){
	if (window != nullptr && window->isOpen()) {
		window->close();
		delete window;
	}
}