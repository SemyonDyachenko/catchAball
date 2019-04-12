#include "Includes.h"
#include "Camera.h"
#include "menu.h"
#include "engine/Player.h"
#include "LifeBar.h"
#include "engine/Level.h"
#include "engine/TextureLoader.h"
#include "engine/MusicLoader.h"
#include "engine/SoundLoader.h"

using namespace sf;

//constans
const int window_width = 800;
const int window_height = 600;


int main() {
	
	RenderWindow window(VideoMode(window_width, window_height), "Enchanted world");
	menu(window);
	window.setFramerateLimit(60);
	view.reset(FloatRect(0, 0, window_width / 1.2, window_height / 1.2));
	
	//map
	Level level;
	level.LoadFromFile("images/test.tmx");

	//lifebar
	LifeBar lifeBarForPlayer;


	//background 
	TextureLoader background("gamebg.png");

	//sound
	MusicLoader music("music1",15);
	//music.StartPlay();

	//sound
	SoundLoader goin("go", 20);
	goin.SetLoop(true);
	bool f = false;


	//cursor visible
	window.setMouseCursorVisible(false); 

	//created player
	Player p("hero.png", 10,400, level, 96.0, 98.0);
	
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
			}
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
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(94 * int(CurrentFrame), 96, 72.0, 76.0));
			getPlayerCoord(p.getPositionX(), p.getPositionY());

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			p.dir = 0; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(94 * int(CurrentFrame), 192, 72.0, 76.0));
			getPlayerCoord(p.getPositionX(), p.getPositionY());

		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			p.sprite.move(-0.5, 0);
		}


		//update
		p.update(time);
		lifeBarForPlayer.update(100);

		//clear
		window.clear();

		//camera
		window.setView(view);
		//changeview();

		//draw
		background.Draw(window);
		level.Draw(window);
		lifeBarForPlayer.draw(window);
		window.draw(p.sprite);
		window.display();
	}

	system("pause");
	return 0;
}