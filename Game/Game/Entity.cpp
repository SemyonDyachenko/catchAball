#include "Entity.h"


void Entity::initDefaultVariables()
{
	this->weight = 96;
	this->height = 98;
	if (!this->img.loadFromFile("../res/images/hero.png")) {
		for (size_t i = 0; i < 25; i++)
		{
			std::cout << "ERROR LOAD IMAGE\n";
		}
	}
	this->img.createMaskFromColor(sf::Color(255, 255, 255));
	this->texture.loadFromImage(img);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(weight, height, weight, height));
	this->currentFrame = 0;
	moveDir = STAY;
	this->dx = 0; this->dy = 0;
	this->speed = 0.f;
	//time
	this->animationTime = sf::milliseconds(80);
	this->level.LoadFromFile("map.tmx");
	collision = this->level.GetObjects("collis");
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

sf::View Entity::playerCoordsForView(float x, float y)
{
	this->view.setCenter(x + 100, y);
	return view;
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
	return sf::FloatRect(this->positionX,this->positionY,this->weight,this->height);
}

void Entity::movement(const float & dt)
 {
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		 this->moveDir = LEFT;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 96, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.35f;
		 playerCoordsForView(this->sprite.getPosition().x, this->sprite.getPosition().y);
	 } else 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		 this->moveDir = RIGHT;
		 this->currentFrame += 0.005f * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 192, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.35f;
		 playerCoordsForView(this->sprite.getPosition().x, this->sprite.getPosition().y);
	 } else 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		 this->moveDir = UP;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 288, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.35f;
		 playerCoordsForView(this->sprite.getPosition().x, this->sprite.getPosition().y);
	 } else
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		 this->moveDir = DOWN;
		 this->currentFrame += 0.005 * dt;
		 if (this->currentFrame > 3) currentFrame -= 3;
		 this->sprite.setTextureRect(sf::IntRect(96 * int(this->currentFrame), 0, 96, 96)); //проходимс€ по координатам ’. получаетс€ 0, 96,96*2 и оп€ть 0
		 this->speed = 0.35f;
		 playerCoordsForView(this->sprite.getPosition().x, this->sprite.getPosition().y);
	 }
 }

Level Entity::getLevel()
{
	return this->level;
}


void Entity::checkCollisionWithMap(float Dx, float Dy)
{
	for (size_t i = 0; i < collision.size(); i++) {
		if (this->getRect().intersects(collision[i].rect)) {
			if (Dy > 0) { positionY = collision[i].rect.top - height;  dy = 0;}
			if (Dy < 0) { positionY = collision[i].rect.top + collision[i].rect.height;   dy = 0; }
			if (Dx > 0) { positionX = collision[i].rect.left - weight; }
			if (Dx < 0) { positionX = collision[i].rect.left + collision[i].rect.width; }
		}
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
	checkCollisionWithMap(this->dx, 0);
	this->positionY += this->dy * dt; 
	checkCollisionWithMap(0, this->dy);
	this->sprite.setPosition(this->positionX, this->positionY);
	this->speed = 0.f;
}

void Entity::render(sf::RenderTarget * target)
{
	level.Draw(target);
	target->draw(this->sprite);
}


