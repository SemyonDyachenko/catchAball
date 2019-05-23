#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <glut.h>
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include  <map>

class Entity 
{
private:

protected:
	sf::Sprite sprite;
	float speed;
	float currentFrame;
	sf::Texture texture;
	float dx, dy;
	enum EntityMovement { STAY, LEFT, RIGHT, UP, DOWN };
	EntityMovement moveDir;
	sf::Image img;
	float positionX;
	float positionY;
	sf::Time animationTime;
	sf::Clock animationClock;
	int hp;


	//init
	void initDefaultVariables();
public:
	Entity(float x,float y);
	virtual ~Entity();


	//virtual void movement(const float& dt);

	// позиции
	float getPositionX();
	float getPositionY();


	//movement functions
	void movement();
	void loseHp();
	void getHp();



	// update , render
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget * target = nullptr);

};

#endif

