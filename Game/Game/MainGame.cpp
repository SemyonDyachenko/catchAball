#include <vector>
#include <math.h>
#include <map>
#include <time.h>
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "engine/Camera.h"
#include "engine/menu.h"
#include "engine/Player.h"
#include "engine/LifeBar.h"
#include "engine/Level.h"
#include "engine/TextureLoader.h"
#include "engine/MusicLoader.h"
#include "engine/SoundLoader.h"
#include "Box2D/Box2D.h"
#include "engine/Coin.h"


using namespace sf;

//constans




int main() {
	//window width
	Vector2u winsize;
	winsize.x = 800;
	winsize.y = 600;
	const float CameraSizeX = winsize.x / 1.5;
	const float CameraSizeY = winsize.y / 1.5;
	//render//**************************
	RenderWindow window(VideoMode(winsize.x, winsize.y), "Game by Semyon");

	menu(window);
	view.reset(FloatRect(0, 0, CameraSizeX, CameraSizeY));

	//map
	Level level;
	level.LoadFromFile("../Debug/map.tmx");

	std::vector<CoinObject> coins;
	std::vector<Object> CoinObj = level.GetAllObjects();
	for (size_t i = 0; i < CoinObj.size(); i++) {
		if (CoinObj[i].name == "coin") {
			coins.emplace_back(CoinObj[i].rect);
		}
	}


	//lifebars
	LifeBar lifeBarForPlayer;

	//object
	//Object bg = level.GetObjectA("BG");
	Vector2i TileSize = level.GetTileSize();
	Object player = level.GetObjectA("player");
	Player p("hero.png", player.rect.left, player.rect.top, level, 96.0, 84.0, lifeBarForPlayer);

	//sound
	MusicLoader music("music",15);
	music.StartPlay();
	SoundLoader goin("go", 20);
	goin.SetLoop(true);
	bool f = false;

	

	//cursor visible
	window.setMouseCursorVisible(false);
	Clock clock;
	float CurrentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds()/800;
		clock.restart();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) 
				window.close();
			
		}	
		for (size_t i = 0; i < CoinObj.size(); i++) {
			if (p.getRect().intersects(CoinObj[i].rect)) {
				coins[i].setAlive(false);

			}
		}
		
	
		//keyboard
		if(p.life) {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.state = p.LEFT;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(91 * int(CurrentFrame), 90, 70.0, 76.0));
			getPlayerCoord(p.sprite.getPosition().x, p.sprite.getPosition().y,winsize.x,winsize.y);
			if (!(Keyboard::isKeyPressed(Keyboard::LShift))) {
				p.speed = 0.1;
			}
			else {
				p.speed = 0.15;
			}
		} else 
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				p.state = p.RIGHT;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(91 * int(CurrentFrame), 188, 70.0, 76.0));
				getPlayerCoord(p.sprite.getPosition().x, p.sprite.getPosition().y,winsize.x,winsize.y);
				if (!(Keyboard::isKeyPressed(Keyboard::LShift)))
				{
					p.speed = 0.1;
				}
				else {
					p.speed = 0.15;
				}

		} 
		if (Keyboard::isKeyPressed(Keyboard::Space) && (p.onGround)) {
			p.state = p.JUMP; p.dy = -0.6;  p.onGround = false; 
			getPlayerCoord(p.sprite.getPosition().x, p.sprite.getPosition().y, winsize.x, winsize.y);
		 }
		getPlayerCoord(p.sprite.getPosition().x, p.sprite.getPosition().y, winsize.x, winsize.y);
		}
		
		//update
		p.update(time);
		lifeBarForPlayer.update(p.hp);
		
		//clear
		window.clear(Color(113, 229, 242));

		//camera
		window.setView(view);

		//draw
		//background.Draw(window);
		level.Draw(window);
		lifeBarForPlayer.draw(window);
		for (size_t i = 0; i < coins.size(); i++) {
			if (coins[i].isAlive()) {
				coins[i].draw(window);
			}
		}
		window.draw(p.sprite);
		window.display();

	}
	
	return 0;
}
