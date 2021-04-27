#ifndef SORTS_LAB_18_03_21_RENDER_H
#define SORTS_LAB_18_03_21_RENDER_H

#include <string>
#include <SFML/Graphics.hpp>

using std::string;
using namespace sf;

class Render {
	RenderWindow* window = nullptr;
	void visualize(int mass[], int size);
	string info = "test";
	int infoSize = 50;
	Font font;
public:
	~Render();
	void draw(int mass[], int size, int sleepTime, string info = "");
	Clock clock;
	Render(RenderWindow* _window = nullptr);
};


#endif //SORTS_LAB_18_03_21_RENDER_H
