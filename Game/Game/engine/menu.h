
#include "Includes.h"

using namespace sf;



void menu(RenderWindow & window) {
	Image imgT1, imgT2, imgT3;
	imgT1.loadFromFile("..//res/images/play.png");
	//imgT2.loadFromFile("..//res/images/222.png");
	imgT3.loadFromFile("..//res/images/exit.png");
	imgT1.createMaskFromColor(Color(255, 255, 255));
	imgT3.createMaskFromColor(Color(255, 255, 255));
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
	menuTexture1.loadFromImage(imgT1);
	//menuTexture2.loadFromImage(imgT2);
	menuTexture3.loadFromImage(imgT3);
	menuBackground.loadFromFile("..//res/images/bg.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = true;
	int menuNum = 0;
	menu1.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	menu1.setOrigin(menuTexture1.getSize().x / 2, menuTexture1.getSize().y / 2);
	//menu2.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);
	//menu2.setOrigin(menuTexture2.getSize().x / 2, menuTexture2.getSize().y / 2);
	menu3.setPosition(window.getSize().x / 2, window.getSize().y/2 + 150);
	menu3.setOrigin(menuTexture3.getSize().x / 2, menuTexture3.getSize().y / 2);

	//sf::Text text;
	//sf::Font font;
	//sf::String string;
	//string = "hello";
	//text.setString(string);
	//window.draw(text);

	window.setMouseCursorVisible(false);
	Texture cur;
	cur.loadFromFile("../res/images/cursor.png");
	Sprite cursor(cur);

	//////////////////////////////menu///////////////////
	while (isMenu) {
		Event event;

		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
		}

			menuNum = 0;
			

			if (IntRect(menu1.getPosition().x-60, menu1.getPosition().y, menuTexture1.getSize().x, menuTexture1.getSize().y).contains(Mouse::getPosition(window))) { menuNum = 1;}
			//if (IntRect(menu2.getPosition().x-60, menu2.getPosition().y, menuTexture2.getSize().x, menuTexture2.getSize().y).contains(Mouse::getPosition(window))) { menuNum = 2; }
			if (IntRect(menu3.getPosition().x-60, menu3.getPosition().y, menuTexture3.getSize().x, menuTexture3.getSize().y).contains(Mouse::getPosition(window))) { menuNum = 3; }

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { isMenu = false; }//если нажали первую кнопку, то выходим из меню 
				//if (menuNum == 2) { continue; }
				if (menuNum == 3) { window.close(); exit(-1); isMenu = false; }

			}
			


			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.draw(menu3);
			cursor.setPosition(pos.x, pos.y);
			window.draw(cursor);
			window.display();
		}
	}
	////////////////////////////////////////////////////
}