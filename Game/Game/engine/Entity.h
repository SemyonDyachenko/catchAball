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
	float x, y;
	int speed;
	bool isLife;
	bool enemy;
	Image image;
	Texture texture;
	Sprite sprite;
	int dir;
public:
	Entity(std::string name,std::string file,int hp,int damage,float x,float y,bool isLife,bool enemy)
	{
		this->name = name;
		this->file = file;
		this->hp = hp;
		this->damage = damage;
		this->x = x; this->y = y;
		this->isLife = isLife;
		this->enemy = enemy;
		if (!image.loadFromFile("../res/images/" + file + ".png")) {
			cout << "Error load image!" << endl;
		}
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		dir = 0;
		speed = 1.0;
	}
};

