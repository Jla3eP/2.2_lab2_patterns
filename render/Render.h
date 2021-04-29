#ifndef SORTS_LAB_18_03_21_RENDER_H
#define SORTS_LAB_18_03_21_RENDER_H

#include <string>
#include <SFML/Graphics.hpp>

using std::string;
using namespace sf;

class Render {
	RenderWindow* window = nullptr;
	void visualize(int mass[], int size, int redElemIndex, bool greenField = 0);
	string info = "test";
	int infoSize = 50;
	Font font;
public:
	~Render();
	void finalDraw(int mass[], int size);
	void draw(int mass[], int size, int sleepTime, int redElemIndex, string info = "");
	Clock clock;
	Render(RenderWindow* _window = nullptr);
};


#endif //SORTS_LAB_18_03_21_RENDER_H
