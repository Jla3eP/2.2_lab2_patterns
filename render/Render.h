#ifndef SORTS_LAB_18_03_21_RENDER_H
#define SORTS_LAB_18_03_21_RENDER_H

#include <string>
#include <SFML/Graphics.hpp>

using std::string;
using namespace sf;

class Render {
	RenderWindow* window = nullptr;
	void visualize(int mass[], int size, int redElemIndex, bool greenField = 0);
	string info = "";//інформація, яка буде виведена внизу вікна
	int infoSize = 50;//розімр тексту
	Font font;
	Render(RenderWindow* _window = nullptr);//приватний так як сінглтон
	static Render* renderPtr;//частина реалізації singleton
public:
	static void deleteRender();
	static Render* getRender();//singleton
	~Render();
	void finalDraw(int mass[], int size);
	void draw(int mass[], int size, int sleepTime, int redElemIndex, string info = "");
	Clock clock;
};



#endif //SORTS_LAB_18_03_21_RENDER_H
