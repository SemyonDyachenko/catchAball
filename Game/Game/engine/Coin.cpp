#include "Coin.h"

CoinObject::CoinObject(sf::Rect<float> rect, sf::Texture & texture)
{
	this->rect = rect;
	texture.loadFromFile("../res/images/coin.png");
	sprite.setTexture(texture);
}

bool CoinObject::isAlive()
{
	return Alive;
}

void CoinObject::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}
