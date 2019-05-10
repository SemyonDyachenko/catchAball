#include "../Includes.h"
#include <iostream>


class SfmlObject : public sf::Drawable
{
private:
	sf::Rect<float> Rect;
	sf::Sprite sprite;
	bool m_Alive;
	std::string name;
public:
	SfmlObject(sf::Rect<float> rect,sf::Texture& texture);
	bool isAlive();
	sf::Rect<float> const getRect() { return Rect; }
	void setPosition(float x, float y) { Rect.left = x; Rect.top = y; }
	void setTexture(sf::Texture & Ttexture) { sprite.setTexture(Ttexture); }
	bool setAlive(bool alive) { m_Alive = alive; return m_Alive; }
	virtual void draw(sf::RenderTarget& taget,sf::RenderStates state) const override;
	~SfmlObject();
};

