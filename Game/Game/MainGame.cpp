﻿#include "Includes.h"
#include "engine/Camera.h"
#include "menu.h"
#include "engine/Player.h"
#include "LifeBar.h"
#include "engine/Level.h"
#include "engine/TextureLoader.h"
#include "engine/MusicLoader.h"
#include "engine/SoundLoader.h"
#include "engine/Entity.h"
#include "../packages/Box2D.2.3.0/src/native/Box2D/Box2D.h"


using namespace sf;

//constans




int main() {
	//window width
	Vector2u winsize;
	winsize.x = 1920;
	winsize.y = 1080;

	RenderWindow window(VideoMode(winsize.x,winsize.y), "Enchanted world");
	menu(window);
	window.setFramerateLimit(60);
	view.reset(FloatRect(0, 0, winsize.x / 1.2, winsize.y / 1.2));

	//map
	Level level;
	level.LoadFromFile("../res/map.tmx");

	

	//lifebar
	LifeBar lifeBarForPlayer;

	//background
	TextureLoader background("gamebg.png");

	
	//sound
	MusicLoader music("music",15);
	//music.StartPlay();

	//sound
	SoundLoader goin("go", 20);
	goin.SetLoop(true);
	bool f = false;

	//cursor visible
	window.setMouseCursorVisible(false);

	//objects
	Player p("hero.png", 140,312, level, 96.0, 84.0);
	
	//

	//time
	Clock clock;
	float CurrentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}


			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::A || event.key.code == Keyboard::D || event.key.code == Keyboard::W || event.key.code == Keyboard::S) {
					if (!f) {
						f = true;
						goin.sound.play();
					}
				}
			}else
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::A || event.key.code == Keyboard::D || event.key.code == Keyboard::W || event.key.code == Keyboard::S) {
					if (f) {
						f = false;
						goin.sound.stop();
					}
				}
			}

		}

	
		//keyboard
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.state = p.LEFT; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(94 * int(CurrentFrame), 94, 72.0, 76.0));
				getPlayerCoord(p.getPositionX(), p.getPositionY());

		} else 
		if (Keyboard::isKeyPressed(Keyboard::D)) {
				p.state =p.RIGHT; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(94 * int(CurrentFrame), 192, 72.0, 76.0));
				getPlayerCoord(p.getPositionX(), p.getPositionY());

		} 
		if (Keyboard::isKeyPressed(Keyboard::Space) && (p.onGround)) {
			p.state = p.JUMP; p.dy = -0.4;  p.onGround = false; 
		 }

	//	getPlayerCoord(p.getPositionX(), p.getPositionY());
		


		//update
		p.update(time);


		//clear
		window.clear();

		//camera
		window.setView(view);

		//draw
		background.Draw(window);
		level.Draw(window);
		lifeBarForPlayer.draw(window);
		window.draw(p.sprite);
		//enemy.Draw(window);
		window.display();

	}

	system("pause");
	return 0;
}
