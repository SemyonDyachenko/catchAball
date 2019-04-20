#pragma once
#include "Includes.h"
#include "Level.h"

using namespace sf;


class Player {
private:
	float x = 0, y = 0;
public:
	std::vector<Object> obj;
	float  w, h, dx, dy, speed = 0;
	int dir = 0;
	bool onGround;
	String file;
	Image img;
	Texture t;
	Sprite sprite;
	Player(String file, float x, float y, Level &lvl, float w, float h)
	{
		dx = 0; dy = 0; speed = 0; dir = 0;  obj = lvl.GetAllObjects();
		onGround = false;
		this->w = w; 
		this->h = h;
		this->file = file;
		img.loadFromFile("../res/images/" + file);
		img.createMaskFromColor(Color(255, 255, 255));
		t.loadFromImage(img);
		sprite.setTexture(t);
		this->x = x; this->y = y;
		sprite.setTextureRect(IntRect(0,192, w, h));
		sprite.setOrigin(w / 2, h / 2);

	}



	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; break;
		case 1: dx = -speed;break;
		case 2: break; // чтобы можно было во время прыжка идти вперед то нужно здесь убрать dx = 0;  но при этом почему то будет возращать в начало координат.
		case 3: break;
		}
		
		x += dx * time;
		checkCollisionWithMap();
		y += dy * time;
		checkCollisionWithMap();
		speed = 0;
		sprite.setPosition(x+w/2, y+h/2);
		if (!onGround) { dy = dy + 0.0015*time; }
		
		
	}


	FloatRect getRect() {
	return FloatRect(x, y, w, h);
	}



	void checkCollisionWithMap() {
		for (int i = 0; i < obj.size(); i++)//проходимся по объектам
			if (getRect().intersects(obj[i].rect))//проверяем пересечение игрока с объектом
			{
				if (obj[i].name == "colis")//если встретили препятствие
				{
					if (dy > 0) { y = obj[i].rect.top - h; onGround = true; dy = 0; }
					if (dy < 0) { y = obj[i].rect.top + obj[i].rect.height; dy = 0; }
					if (dx > 0) { x = obj[i].rect.left - w; dx = 0; }
					if (dx < 0) { x = obj[i].rect.left + obj[i].rect.width; dx = 0;}

				}
			}
	}



	float getPositionX() {
		return x;
	}

	float getPositionY() {
		return y;
	}

};

