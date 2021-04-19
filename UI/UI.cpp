#include "UI.h"


UI::UI (){
	
	font1.loadFromFile("../discoduckchromeital.ttf");
	font2.loadFromFile("../discoduckcond.ttf");
	
	const int size = 4;
	Text *text[size];
	typedef void (UI::*method) ();
	method actions[size];
	
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
	
	window = new RenderWindow(VideoMode(1080, 720), "");
	while ( window->isOpen()) {
		if (clock.getElapsedTime().asMilliseconds() < 1000 / 60) {
			continue;
		}
		else{
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
	Text text("", font2, textSize);
	Text exitText("Exit", font2, textSize);
	
	
	//const int size = 4;
	Text menuText("Enter array size\nAnd press enter", font2, textSize);
	menuText.setPosition(0, window->getPosition().y / 4);
	text.setPosition(0, menuText.getPosition().y + textSize * 2);
	exitText.setPosition(0, text.getPosition().y + textSize);
	
	Clock enterTimer;
	
	while ( window->isOpen()) {
		if (clock.getElapsedTime().asMilliseconds() < 1000 / 60) {
			continue;
		}
		else{
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
		else{
			exitText.setFont(font2);
		}
		
		window->clear(Color(0, 0, 0, 0));
		window->draw(menuText);
		window->draw(exitText);
		
		if (event.type == Event::TextEntered)
		{
			if (enterTimer.getElapsedTime().asMilliseconds() > 120 )
			{
				if(isdigit(static_cast<char>(event.text.unicode)) && str.size() <= 2) {
					str += static_cast<char>(event.text.unicode);
					text.setString(str);
					enterTimer.restart();
				}
				else if(Keyboard::isKeyPressed(Keyboard::BackSpace) && str.size() > 0 && enterTimer.getElapsedTime().asMilliseconds() > 200){
					str = str.erase(str.size() - 1, 1);
					text.setString(str);
					enterTimer.restart();
				}
				else if(Keyboard::isKeyPressed(Keyboard::BackSpace) && str.size() > 0){
					this->arraySize = stoi(str);
					break;
				}
			}
		}
		window->draw(text);
		window->display();
	}
	/*if (event.Type == sf::Event::TextEntered && isPassEnter)// ввод текста, нужно оставить только цифры (if с юникодом)
	{
		if (event.Text.Unicode < 128)
		{
			str += static_cast<char>(event.Text.Unicode);
			text.SetText(str);
		}
	}
	
	
	window.Draw(text);*/
}

void UI::exit (){
	if (window->isOpen()) {
		window->close();
	}
}

void UI::start (){

}

void UI::settings (){

}
