#ifndef ENTITY_H
#define ENTITY_H


#include "Ball.h"


class Entity 
{
private:
	
protected:
	sf::Sprite sprite;
	float speed;
	sf::Texture texture;
	float dx, dy;
	enum EntityMovement { STAY, LEFT, RIGHT, UP, DOWN };
	EntityMovement moveDir;
	bool onGround;
	sf::Image img;
	float positionX;
	float positionY;
	//init
	void initDefaultVariables();
public:
	Entity(float x,float y);
	virtual ~Entity();


	//virtual void movement(const float& dt);

	// позиции
	float getPositionX();
	float getPositionY();
	sf::View view;
	//levels

	//camera
	

	//movement functions
	

	sf::FloatRect getRect();
	void movement(const float& dt);
	void loseHp();
	void getHp();
	void setPosition(float x, float y);


	//level


	// update , render
	void checkCollisionWithBall(float Dx, float Dy);
	virtual void update(const float& time);
	virtual void render(sf::RenderWindow * window);

};

#endif

