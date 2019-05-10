#include "../Includes.h"

class CoinObject {
private:
	sf::Rect<float> rect;
	sf::Sprite sprite;
	sf::Texture texture;
	bool Alive;
	std::string name;
public:

	CoinObject(sf::Rect<float> rect, sf::Texture & texture);
	sf::Rect<float>  getRect() { return rect; }
	bool isAlive();
	bool setAlive(bool alive) { Alive = alive; };
	void draw(sf::RenderWindow & window);

};