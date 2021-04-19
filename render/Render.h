#ifndef SORTS_LAB_18_03_21_RENDER_H
#define SORTS_LAB_18_03_21_RENDER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Render {
public:
	~Render();
	RenderWindow* window = nullptr;
	void visualize(int mass[], int size);
	void draw(int mass[], int size, int sleepTime);
	Clock clock;
	Render(RenderWindow* _window = nullptr);
};


#endif //SORTS_LAB_18_03_21_RENDER_H
