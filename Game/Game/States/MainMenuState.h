#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"

class MainMenuState :
	public State
{
private:

public:
	MainMenuState(sf::RenderWindow * window);
	virtual ~MainMenuState();


	void endState();

	//funcs
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget * target = nullptr);
};


#endif