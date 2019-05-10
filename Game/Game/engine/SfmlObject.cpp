#include "SfmlObject.h"



SfmlObject::SfmlObject(sf::Rect<float> rect, sf::Texture& texture) :
	Rect(rect),
	sprite(texture),
	m_Alive(true)
{
	sprite.setPosition(Rect.left, Rect.top);

}

bool SfmlObject::isAlive()
{
	return m_Alive;
}




void SfmlObject::draw(sf::RenderTarget & taget, sf::RenderStates state) const
{
	taget.draw(sprite);
}

SfmlObject::~SfmlObject()
{

}
