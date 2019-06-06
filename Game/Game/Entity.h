#ifndef ENTITY_H
#define ENTITY_H




#include "Enemy.h"

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
	bool onGround;
	sf::Image img;
	float standAnimationFrame;
	float positionX;
	float positionY;
	sf::Time animationTime;
	Level  level;
	sf::Clock animationClock;
	//init
	void initDefaultVariables();
public:
	Entity();
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
	std::vector<Object> collision;
	Level getLevel();


	// update , render
	void checkCollisionWithMap(float Dx, float Dy);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget * target = nullptr);

};

#endif

