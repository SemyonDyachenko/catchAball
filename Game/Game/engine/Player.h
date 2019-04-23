#pragma once
#include "Includes.h"
#include "Level.h"
#include "../LifeBar.h"

using namespace sf;


class Player {
private:
	float x = 0, y = 0;
public:
	std::vector<Object> obj;
	float  w, h, dx, dy, speed = 0;
	int dir = 0;
	enum StateObject {STAND,LEFT,RIGHT,JUMP};
	StateObject state;
	bool onGround;
	String file;
	Image img;
	Texture t;
	Sprite sprite;
	int hp;
	int damage;
	Player(String file, float x, float y, Level &lvl, float w, float h,LifeBar bar,int hp,int damage)
	{
		this->hp = hp; this->damage = damage;
		dx = 0; dy = 0; speed = 0; state = STAND;  obj = lvl.GetAllObjects();
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
		if (hp > 100 || hp < 0) {
			std::cout << "error of initialization healt point" << std::endl;
		} 
	}



	void update(float time)
	{
		switch (state)
		{
		case RIGHT: dx = speed; break;
		case LEFT: dx = -speed;break;
		case JUMP: break; // чтобы можно было во время прыжка идти вперед то нужно здесь убрать dx = 0;  но при этом почему то будет возращать в начало координат.
		case STAND: break;
		}
		
		x += dx * time;
		checkCollisionWithMap(0,dx);
		y += dy * time;
		checkCollisionWithMap(dy,0);
		speed = 0;
		sprite.setPosition(x, y);
		dy = dy + 0.0015*time; checkCollisionWithMap(dy, dx);


		if (y > 320) { hp = 0; }
		if (hp == 0) {
			std::cout << "Player is dead"<<std::endl;
		}
		
		
		
	}


	FloatRect getRect() {
	return FloatRect(x, y, w, h);
	}



	void checkCollisionWithMap(float Dy,float Dx) {
		for (int i = 0; i < obj.size(); i++)//проходимся по объектам
			if (getRect().intersects(obj[i].rect))//проверяем пересечение игрока с объектом
			{
				if (obj[i].name == "colis")//если встретили препятствие
				{
					if (Dy > 0) { y = obj[i].rect.top - h; onGround = true; dy = 0; }
					if (Dy < 0) { y = obj[i].rect.top + obj[i].rect.height; dy = 0; }
					if (Dx > 0) { x = obj[i].rect.left - w; dx = 0; }
					if (Dx < 0) { x = obj[i].rect.left + obj[i].rect.width; dx = 0;}
					
				}
				else {
					onGround = false;
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

