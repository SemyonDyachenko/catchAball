#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "MainMenuState.h"

class GameState  : public State
{
private:
	Entity player;


	//funcs
	//void initKeybinds();
public:
	GameState(sf::RenderWindow * window);
	virtual ~GameState();

	

	//funcs
	void endState();

	void updateInput(const float& dt);
	void update(const float & dt);
	void render(sf::RenderTarget *target = nullptr);
};

#endif

