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
	bool isMove, isSelect, onGround;
	String FILE;
	Image img;
	Texture t;
	Sprite sprite;
	Player(String F, float X, float Y, Level &lvl, float W, float H)
	{
		dx = 0; dy = 0; speed = 0; dir = 0;  obj = lvl.GetAllObjects();
		isMove = false; isSelect = false;
		w = W; h = H;
		FILE = F;
		img.loadFromFile("../res/images/" + F);
		img.createMaskFromColor(Color(255, 255, 255));
		t.loadFromImage(img);
		sprite.setTexture(t);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 134, w, h));
		sprite.setOrigin(w / 2, h / 2);

	}



	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: break;
		case 3: break;
		}
		//if(y == )
		x += dx * time;
		checkCollisionWithMap();
		y += dy * time;
		checkCollisionWithMap();
		speed = 0; 
		sprite.setPosition(x+w/2, y+h/2);

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
					if (dy > 0) { y = obj[i].rect.top - h; onGround = true; }
					if (dy < 0) { y = obj[i].rect.top + obj[i].rect.height;  }
					if (dx > 0) { x = obj[i].rect.left - w; }
					if (dx < 0) { x = obj[i].rect.left + obj[i].rect.width; }

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

