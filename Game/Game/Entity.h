#ifndef ENTITY_H
#define ENTITY_H




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


class Entity 
{
private:
	
protected:
	sf::Sprite sprite;
	float speed;
	double currentFrame;
	sf::Texture texture;
	float dx, dy, weight, height;
	enum EntityMovement { STAY, LEFT, RIGHT, UP, DOWN };
	EntityMovement moveDir;
	sf::Image img;
	float positionX;
	float positionY;
	sf::Time animationTime;
	sf::Clock animationClock;
	//init
	void initDefaultVariables();
public:
	Entity(float x, float y);
	virtual ~Entity();


	//virtual void movement(const float& dt);

	// позиции
	float getPositionX();
	float getPositionY();
	sf::View view;
	//levels

	//camera
	sf::View playerCoordsForView(float x, float y);

	//movement functions
	

	sf::FloatRect getRect();
	void movement(const float& dt);
	void loseHp();
	void getHp();


	//level
	Level level;
	std::vector<Object> collision;
	Level getLevel();


	// update , render
	void checkCollisionWithMap(float Dx, float Dy);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget * target = nullptr);

};

#endif

