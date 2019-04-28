#include "Includes.h"

using namespace sf;
using std::cout;
using std::endl;

class TextureLoader {
private:
	std::string file;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	TextureLoader(std::string file) {
		this->file = file;
		if (image.loadFromFile("../res/images/" + file)) {
			texture.loadFromImage(image);
			sprite.setTexture(texture);
		}
		else {
			cout << "Error load image" << endl;
		}

	}

	void SetOrigin(float x, float y)
	{
		sprite.setOrigin(x, y);
			
	}

	void SetPosition(int x,int y)
	{
		sprite.setPosition(x, y);
	}

	float GetPositionX()
	{
		return sprite.getPosition().x;
	}
	float GetPositionY()
	{
		return sprite.getPosition().y;
	}

	void Draw(RenderWindow &window)
	{
		window.draw(sprite);
	}
};