#include "Render.h"


void Render::visualize (int mass[], int size){
	if(window == nullptr){
		window = new RenderWindow(VideoMode(1080, 720), "");
	}
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	int xSize = window->getSize().x / size;
	double ySize = (1.0 * window->getSize().y) / (1.0 * max);
	window->clear(Color(0, 0, 0, 0));
	for (int i = 0; i < size; i++) {
		RectangleShape element(Vector2f(xSize, mass[i] * ySize));
		element.setPosition(i * xSize, window->getSize().y - mass[i] * ySize);
		element.setFillColor(Color(255, 255, 255, 255));
		window->draw(element);
	}
	window->display();
	clock.restart();
	
	
}

Render::Render (){
	//this->window->setFramerateLimit(60);
}

void Render::draw (int *mass, int size, int sleepTime){
	if (clock.getElapsedTime().asMicroseconds() >= sleepTime) {
		visualize(mass, size);
	}
}

