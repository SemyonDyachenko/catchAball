#include "../Includes.h"

using namespace sf;
using std::cout;
using std::endl;

class Entity {
private:
	std::string name;
	std::string file;
	int hp;
	int damage;
	float x, y, w, h; // position x, position y, width, height
	int speed;
	bool isLife;
	bool enemy;
	Image image;
	Texture texture;
	Sprite sprite;
	int dir;
public:
	Entity(std::string name, std::string file, int hp, int damage, float x, float y,float w,float h, bool isLife, bool enemy,float red,float green,float blue)
	{
		this->name = name;
		this->file = file;
		this->hp = hp;
		this->damage = damage;
		this->x = x; this->y = y;
		this->w = w; this->h = h;
		this->isLife = isLife;
		this->enemy = enemy;
		if (!image.loadFromFile("../res/images/" + file + ".png")) {
			cout << "Error load image!" << endl;
		}
		image.createMaskFromColor(Color(red, green, blue));
		texture.loadFromImage(image);
		sprite.setTextureRect(IntRect(w,h,w,h));
		dir = 0;
		speed = 1.0;
	}


	void Draw(RenderWindow &window)
	{
		window.draw(sprite);
	}

	
};

