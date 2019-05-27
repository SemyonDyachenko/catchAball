#ifndef ENTITY_H
#define ENTITY_H

#include "Camera.h"


class Entity 
{
private:

protected:
	sf::Sprite sprite;
	float speed;
	double currentFrame;
	sf::Texture texture;
	float dx, dy;
	enum EntityMovement { STAY, LEFT, RIGHT, UP, DOWN };
	EntityMovement moveDir;
	sf::Image img;
	Level level;
	float positionX;
	float positionY;
	sf::Time animationTime;
	sf::Clock animationClock;

	//init
	void initDefaultVariables();
public:
	Entity(float x,float y);
	virtual ~Entity();


	//virtual void movement(const float& dt);

	// позиции
	float getPositionX();
	float getPositionY();

	//levels

	//movement functions
	
	void movement(const float& dt);
	void loseHp();
	void getHp();



	// update , render
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget * target = nullptr);

};

#endif

