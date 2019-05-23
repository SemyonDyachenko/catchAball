#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"


class MainMenuState : public State
{
private:
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;

	//funcs
	void initVariables();
	void initBackground();
	void initFonts();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow * window, std::stack<State*>* states);
	virtual ~MainMenuState();


	void endState();

	//funcs
	void updateInput(const float& dt);
	void updateButtons();
	void renderButtons(sf::RenderTarget * target = nullptr);
	void update(const float& dt);
	void render(sf::RenderTarget * target = nullptr);
};


#endif