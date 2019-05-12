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
protected:
	sf::RectangleShape shape;
	float Speed;
	float EntityPosX, EntityPosY;
	float dx, dy;

	//funcs 
	void initEntityPos();

public:
	Entity();
	virtual ~Entity();

	//funcs
	virtual void move(const float& dt, const float x,const float y);


	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget * target);
};

#endif

