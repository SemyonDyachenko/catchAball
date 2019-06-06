#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"


class GameState :public State
{
private:
	Entity  player;
	sf::RenderWindow * window;
	//funcs
	void initTextures();
public:
	GameState(sf::RenderWindow * window, std::stack<State*>*states);
	virtual ~GameState();


	//funcs
	void endState();
	void updateInput(const float& dt);
	void update(const float & dt);
	void render(sf::RenderWindow *window = nullptr);
};

#endif