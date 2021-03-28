#ifndef SORTS_LAB_18_03_21_RENDER_H
#define SORTS_LAB_18_03_21_RENDER_H

#include <SFML/graphics.hpp>

using namespace sf;

class Render {
public:
	RenderWindow* window = new RenderWindow(VideoMode(1080, 720), "");
	void visualize(int mass[], int size);
	void draw(int mass[], int size, int sleepTime);
	Clock clock;
	Render();
};


#endif //SORTS_LAB_18_03_21_RENDER_H
