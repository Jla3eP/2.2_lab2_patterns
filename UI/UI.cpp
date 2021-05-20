#include "UI.h"


UI::UI (){
	font1.loadFromFile("../discoduckchromeital.ttf");
	font2.loadFromFile("../discoduckcond.ttf");
	
	const int size = 4;
	Text *text[size];
	typedef void (UI::*method) ();
	method actions[size];
	
	window = new RenderWindow(VideoMode(1080, 720), "");
	voidSize = (window->getSize().y - textSize*size) / (size - 1);
	
	text[0] = new Text("Create array", font1, textSize);
	text[0]->setPosition(0, 0);
	actions[0] = &UI::createArray;
	
	text[1] = new Text("Start", font1, textSize);
	text[1]->setPosition(0, text[0]->getPosition().y + textSize + voidSize);
	actions[1] = &UI::start;
	
	text[2] = new Text("Settings", font1, textSize);
	text[2]->setPosition(0, text[1]->getPosition().y + textSize + voidSize);
	actions[2] = &UI::settings;
	
	text[3] = new Text("Exit", font1, textSize);
	text[3]->setPosition(0, text[2]->getPosition().y + textSize + voidSize);
	actions[3] = &UI::exit;
	
	
	while ( window->isOpen()) {
		if (clock.getElapsedTime().asMilliseconds() < 1000 / 60) {
			continue;
		}
		else {
			clock.restart();
		}
		Event event;
		while ( window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
		}
		window->clear(Color(0, 0, 0, 0));
		
		for (int i = 0; i < size; i++) {
			text[i]->setFont(font1);
		}
		
		Vector2i pixelPos = Mouse::getPosition(*window);
		Vector2f pos = window->mapPixelToCoords(pixelPos);
		
		for (int i = 0; i < size; i++) {
			if (pos.y >= text[i]->getPosition().y && pos.y <= text[i]->getPosition().y + textSize) {
				text[i]->setFont(font2);
				if (Mouse::isButtonPressed(sf::Mouse::Left)) {
					Clock pleaseWait;
					while ( pleaseWait.getElapsedTime().asMilliseconds() < 150 ) {}
					(this->*actions[i])();
				}
			}
			window->draw(*text[i]);
		}
		window->display();
		
	}
}

void UI::createArray (){
	string str;
	
	Text numText("", font2, textSize);
	Text exitText("Exit", font2, textSize);
	Text menuText("Enter array size\nAnd press enter", font2, textSize);
	
	menuText.setPosition(0, window->getPosition().y / 4);
	numText.setPosition(0, menuText.getPosition().y + textSize * 2);
	exitText.setPosition(0, numText.getPosition().y + textSize);
	
	Clock enterTimer;
	
	while ( window->isOpen()) {
		if (clock.getElapsedTime().asMilliseconds() < 1000 / 60) {
			continue;
		}
		else {
			clock.restart();
		}
		Event event;
		while ( window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
		}
		Vector2i pixelPos = Mouse::getPosition(*window);
		Vector2f pos = window->mapPixelToCoords(pixelPos);
		
		if (pos.y >= exitText.getPosition().y && pos.y <= exitText.getPosition().y + textSize) {
			exitText.setFont(font1);
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				break;
			}
		}
		else {
			exitText.setFont(font2);
		}
		
		window->clear(Color(0, 0, 0, 0));
		window->draw(menuText);
		window->draw(exitText);
		
		if (event.type == Event::TextEntered) {
			if (enterTimer.getElapsedTime().asMilliseconds() > 120) {
				if (isdigit(static_cast<char>(event.text.unicode)) && str.size() <= 2) {
					str += static_cast<char>(event.text.unicode);
					numText.setString(str);
					enterTimer.restart();
				}
				else if (Keyboard::isKeyPressed(Keyboard::BackSpace) && str.size() > 0 && enterTimer.getElapsedTime().asMilliseconds() > 200) {
					str = str.erase(str.size() - 1, 1);
					numText.setString(str);
					enterTimer.restart();
				}
				else if (Keyboard::isKeyPressed(Keyboard::BackSpace) && str.size() > 0) {
					this->arraySize = stoi(str);
					break;
				}
			}
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!str.empty()) {
				arraySize = stoi(str);
			}
			else {
				arraySize = DEFAULT;
			}
			array = new int[arraySize];
			for (int i = 0; i < arraySize; i++) {
				array[i] = i + 1;
			}
			for (int j = 0; j < arraySize * 5; j++) {
				std::swap(array[rand() % arraySize], array[rand() % arraySize]);
			}
			break;
		}
		window->draw(numText);
		window->display();
	}
}

void UI::exit (){
	if (window->isOpen()) {
		window->close();
	}
}

void UI::start (){
	switch (mode) {
		case DEMO_MODE: {
			Strategy::sort(Strategy::BubbleSort, array, arraySize, 1);
			for (int j = 0; j < arraySize * 5; j++) {
				std::swap(array[rand() % arraySize], array[rand() % arraySize]);
			}
			Strategy::sort(Strategy::ShakerSort, array, arraySize, 1);
			for (int j = 0; j < arraySize * 5; j++) {
				std::swap(array[rand() % arraySize], array[rand() % arraySize]);
			}
			Strategy::sort(Strategy::InsertionSort, array, arraySize, 1);
			for (int j = 0; j < arraySize * 5; j++) {
				std::swap(array[rand() % arraySize], array[rand() % arraySize]);
			}
			Strategy::sort(Strategy::StupidQuickSort, array, arraySize, 1);
			for (int j = 0; j < arraySize * 5; j++) {
				std::swap(array[rand() % arraySize], array[rand() % arraySize]);
			}
			Strategy::sort(Strategy::MedianQuickSort, array, arraySize, 1);
			break;
		}
		case BUBBLE_SORT: {
			Strategy::sort(Strategy::BubbleSort, array, arraySize, 1);
			break;
		}
		case SHAKER_SORT: {
			Strategy::sort(Strategy::ShakerSort, array, arraySize, 1);
			break;
		}
		case INSERTION_SORT: {
			Strategy::sort(Strategy::InsertionSort, array, arraySize, 1);
			break;
		}
		case SIMPLE_QUICK_SORT: {
			Strategy::sort(Strategy::StupidQuickSort, array, arraySize, 1);
			break;
		}
		case MEDIAN_QUICK_SORT: {
			Strategy::sort(Strategy::MedianQuickSort, array, arraySize, 1);
			break;
		}
	}
	Render::deleteRender();
}

void UI::settings (){
	int listSize = 6;
	window->create(VideoMode(window->getSize().x, textSize * (listSize + 1)), "");
	voidSize = (window->getSize().y - textSize * listSize) / (listSize - 1);
	Text *menuList = new Text[listSize];
	menuList[DEMO_MODE] = Text("Demo Mode", font2, textSize);
	menuList[BUBBLE_SORT] = Text("Bubble Sort", font2, textSize);
	menuList[SHAKER_SORT] = Text("Shaker Sort", font2, textSize);
	menuList[INSERTION_SORT] = Text("Insertion Sort", font2, textSize);
	menuList[SIMPLE_QUICK_SORT] = Text("Simple Quick Sort", font2, textSize);
	menuList[MEDIAN_QUICK_SORT] = Text("Median Quick Sort", font2, textSize);
	menuList[0].setPosition(0, 0);
	for (int i = 1; i < listSize; i++) {
		menuList[i].setPosition(0,  menuList[i-1].getPosition().y + textSize + voidSize);
	}
	

	while ( window->isOpen()) {
		window->clear();
		Event event;
		while ( window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
		}
		Vector2i pixelPos = Mouse::getPosition(*window);
		Vector2f pos = window->mapPixelToCoords(pixelPos);
		for (int i = 0; i < listSize; i++) {
			menuList[i].setCharacterSize(textSize);
			if (pos.y >= menuList[i].getPosition().y && pos.y <= menuList[i].getPosition().y + textSize) {
				menuList[i].setCharacterSize(textSize * 1.2);
				if (Mouse::isButtonPressed(sf::Mouse::Left)) {
					mode = i;
					clock.restart();
					while (clock.getElapsedTime().asMilliseconds() < 300 ){}
					return;
				}
			}
			window->draw(menuList[i]);
		}
		window->display();
	}
}
