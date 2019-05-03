#include "Includes.h"
#include "engine/Camera.h"
#include "menu.h"
#include "engine/Player.h"
#include "LifeBar.h"
#include "engine/Level.h"
#include "engine/TextureLoader.h"
#include "engine/MusicLoader.h"
#include "engine/SoundLoader.h"
#include "../packages/Box2D.2.3.0/src/native/Box2D/Box2D.h"



using namespace sf;

//constans




int main() {
	//window width
	Vector2u winsize;
	winsize.x = 1920;
	winsize.y = 1080;
	const float CameraSizeX = winsize.x / 1.5;
	const float CameraSizeY = winsize.y / 1.5;
	//render//**************************
	RenderWindow window(VideoMode(winsize.x, winsize.y), "Game by Semyon", Style::Fullscreen);
	menu(window);
	window.setFramerateLimit(120);
	view.reset(FloatRect(0, 0, CameraSizeX, CameraSizeY));

	//map
	Level level;
	level.LoadFromFile("../Debug/map.tmx");	

	//lifebars
	LifeBar lifeBarForPlayer;


	//objects
	Object player = level.GetObjectA("player");
	Player p("hero.png", player.rect.left, player.rect.top, level, 96.0, 84.0, lifeBarForPlayer);
	//background
	TextureLoader background("background.png");

	

	//objects
	TextureLoader box("elements/box.png");

	//sound
	MusicLoader music("music",15);
	music.StartPlay();

	//sound
	SoundLoader goin("go", 20);
	goin.SetLoop(true);
	bool f = false;

	//cursor visible
	window.setMouseCursorVisible(false);

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
		if(p.life) {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.state = p.LEFT;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(91 * int(CurrentFrame), 90, 70.0, 76.0));
			getPlayerCoord(p.getPositionX(), p.getPositionY(),winsize.x,winsize.y);
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
				getPlayerCoord(p.getPositionX(), p.getPositionY(),winsize.x,winsize.y);
				if (!(Keyboard::isKeyPressed(Keyboard::LShift)))
				{
					p.speed = 0.1;
				}
				else {
					p.speed = 0.15;
				}

		} 
		if (Keyboard::isKeyPressed(Keyboard::Space) && (p.onGround)) {
			p.state = p.JUMP; p.dy = -0.5;  p.onGround = false; 
			getPlayerCoord(p.getPositionX(), p.getPositionY(), winsize.x, winsize.y);
		 }
		}

		getPlayerCoord(p.getPositionX(), p.getPositionY(), winsize.x, winsize.y);
		//

	
	
		
		//update
		p.update(time);
		lifeBarForPlayer.update(p.hp);
		
		//clear
		window.clear(Color(113, 229, 242));

		//camera
		window.setView(view);

		//draw
		background.Draw(window);
		level.Draw(window);
		lifeBarForPlayer.draw(window);
		window.draw(p.sprite);
		box.Draw(window);
		window.display();

	}

	system("pause");
	return 0;
}
