#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"


class GameState :public State
{
private:
	Entity * player;

	//funcs
	void initTextures();
public:
	GameState(sf::RenderWindow * window, std::stack<State*>*states);
	virtual ~GameState();


	//funcs
	void endState();

	void updateInput(const float& dt);
	void update(const float & dt);
	void render(sf::RenderTarget *target = nullptr);
};

#endif