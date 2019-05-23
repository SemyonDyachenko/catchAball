#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"

enum buttonStates{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape button;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor; // холостой цвет 
	sf::Color hoverColor; // цвет зависания при наведении 
	sf::Color activeColor; // активный цвет

	

public:
	Button(float x, float y, float w, float h, sf::Font *font,
		std::string text,sf::Color idleColor,
		sf::Color hoverColor, sf::Color activeColor);
	~Button();


	const bool isPressed()  const;

	//funcs
	void update(const sf::Vector2f mousePos);
	void  render(sf::RenderTarget * target);
};

#endif
