#ifndef ENEMY
#define ENEMY

#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Level.h"



class Enemy
{
protected:
	float posX, posY, w, h, dx, dy;
	float speed;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image image;
	std::string path;
	Level level;
	bool onGround;
	std::vector<Object> map;
	void init();
public:
	Enemy(Level & level);
	virtual ~Enemy();


	sf::FloatRect rect();
	void collision(float Dy, float  Dx);
	void activeMovement();

	void update(const float & dt);
	void render(sf::RenderWindow * window = nullptr);
};

#endif