#include "Entity.h"

void Entity::initDefaultVariables()
{
	if (!this->img.loadFromFile("../res/images/hero.png")) {
		for (size_t i = 0; i < 25; i++)
		{
			std::cout << "ERROR LOAD IMAGE\n";
		}
	}
	this->img.createMaskFromColor(sf::Color(255, 255, 255));
	this->texture.loadFromImage(img);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(96, 98, 96, 98));
	this->currentFrame = 0;
	moveDir = STAY;
	this->dx = 0; this->dy = 0;
	this->speed = 0.f;
	//time
	this->animationTime = sf::milliseconds(80);
}

Entity::Entity(float x,float y)
{
	this->positionX = x;
	this->positionY = y;
	sprite.setPosition(this->positionX,this->positionY);
	this->initDefaultVariables();
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

 void Entity::movement(const float & dt)
 {
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		 this->moveDir = LEFT;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 96, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.1f;
	 } else 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		 this->moveDir = RIGHT;
		 this->currentFrame += 0.005f * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 192, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.1f;
	 } else 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		 this->moveDir = UP;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 288, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.1f;
	 } else
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		 this->moveDir = DOWN;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 0, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.1f;
	 }
 }


 void Entity::update(const float & dt)
{
	
	 movement(dt);
	switch (this->moveDir)
	{
	case Entity::STAY:
		break;
	case Entity::LEFT: this->dx = -speed; this->dy = 0;
		break;
	case Entity::RIGHT: this->dx = speed; this->dy = 0;
		break;
	case Entity::UP: this->dx = 0; this->dy = -speed;
		break;
	case Entity::DOWN: this->dx = 0; this->dy = speed;
		break;
	default:
		break;
	}

	this->positionX += this->dx * dt;
	this->positionY += this->dy * dt; 
	this->sprite.setPosition(this->positionX, this->positionY);
	this->speed = 0.f;
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}


