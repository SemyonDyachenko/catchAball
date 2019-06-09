#include "Entity.h"


void Entity::initDefaultVariables()
{
	if (!this->img.loadFromFile("../res/images/hero.png")) {
		for (size_t i = 0; i < 25; i++)
		{
			std::cout << "ERROR LOAD IMAGE\n";
		}
	}
	this->img.createMaskFromColor(sf::Color::White);
	this->texture.loadFromImage(img);
	this->sprite.setTexture(texture);
	moveDir = STAY;
	this->dx = 0; this->dy = 0;
	this->speed = 0.f;
}

Entity::Entity(float x,float y)
{
	this->positionX = x;
	this->positionY = y;
	this->initDefaultVariables();
	sprite.setPosition(this->positionX, this->positionY);
}

Entity::~Entity()
{

}


float Entity::getPositionX() 
{
	return this->positionX;
}

float Entity::getPositionY() 
{
	return this->positionY;
}



sf::FloatRect Entity::getRect()
{
	return sf::FloatRect(this->positionX,this->positionY,1,2);
}

void Entity::movement(const float & dt)
 {
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		 this->moveDir = LEFT;
		 this->speed = 0.35f;
		
	 } else 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		 this->moveDir = RIGHT;
		 this->speed = 0.35f;
		
	 }
 }

void Entity::setPosition(float x, float y)
{
	this->positionX = x;
	this->positionY = y;
	this->sprite.setPosition(positionX, positionY);
}




void Entity::checkCollisionWithBall(float Dx, float Dy)
{
	
}


void Entity::update(const float & time)
{
	movement(time);
	switch (this->moveDir)
	{
	case Entity::STAY:
		break;
	case Entity::LEFT: this->dx = -speed;
		break;
	case Entity::RIGHT: this->dx = speed; 
		break;
	case Entity::UP: 
		break;
	case Entity::DOWN: 
		break;
	default:
		break;
	}

	this->positionX += this->dx * time;
	this->positionY += this->dy * time;
	this->speed = 0.f;
	this->sprite.setPosition(this->positionX, this->positionY);

}

void Entity::render(sf::RenderWindow * window)
{
	window->draw(this->sprite);
}


