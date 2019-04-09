#include "Includes.h"

using namespace sf;



void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
	menuTexture1.loadFromFile("..//res/images/111.png");
	menuTexture2.loadFromFile("..//res/images/222.png");
	menuTexture3.loadFromFile("..//res/images/333.png");
	menuBackground.loadFromFile("..//res/images/bg.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(300, 180);
	menu2.setPosition(300, 240);
	menu3.setPosition(300, 300);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
		}

				menuNum = 0;

			if (IntRect(300, 180, 300, 50).contains(Mouse::getPosition(window))) { menuNum = 1; }
			if (IntRect(300, 240, 300, 50).contains(Mouse::getPosition(window))) { menuNum = 2; }
			if (IntRect(300, 300, 300, 50).contains(Mouse::getPosition(window))) { menuNum = 3; }

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { Sleep(300); isMenu = false; }//если нажали первую кнопку, то выходим из меню 
				if (menuNum == 2) { continue; }
				if (menuNum == 3) { window.close(); exit(-1); isMenu = false; }

			}



			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.draw(menu3);

			window.display();
		}
	}
	////////////////////////////////////////////////////
}