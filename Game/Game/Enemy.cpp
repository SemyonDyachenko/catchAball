#include "Enemy.h"




void Enemy::init()
{
	this->onGround = false;
	this->dx = 0; this->dy = 0;
	this->posX = this->level.GetObject("enemy").rect.left;
	this->posY = this->level.GetObject("enemy").rect.top;
	this->speed = 0;
	this->path = "../res/images/enemy.png";
	if (!this->image.loadFromFile(this->path)) std::cout << "Error load image" << std::endl;
	this->texture.loadFromImage(this->image);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect());
	this->sprite.setPosition(this->posX, this->posY);
}

Enemy::Enemy(Level & level)
{
	this->level = level;
	this->init();
}

Enemy::~Enemy()
{
}

sf::FloatRect Enemy::rect()
{
	return sf::FloatRect(posX, posY, w, h);
}

void Enemy::collision(float Dy,float  Dx)
{
	this->map = this->level.GetObjects("collis");
	for (int i = 0; i < map.size(); ++i) {
 		if (this->rect.intersects(map[i].rect)) {

			if (Dy > 0) { posY = map[i].rect.top - h; dy = 0;  /*onGround = true;*/ }
			if (Dy < 0) { posY = map[i].rect.top + map[i].rect.height;  dy = 0; }
			if (Dx > 0) { posX = map[i].rect.left - w; dx = 0; }
			if (Dx < 0) { posX = map[i].rect.left + map[i].rect.width; dx = 0; }
		}
	}
}

void Enemy::activeMovement()
{

}


void Enemy::update(const float & dt)
{
}

void Enemy::render(sf::RenderWindow * window)
{
}
