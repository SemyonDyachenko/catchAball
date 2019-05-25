#include "GameState.h"





GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states) : State(window, states)
{
	this->player = new Entity(400,200);
}


GameState::~GameState()
{
	delete this->player;
}

void GameState::endState()
{
	std::cout << " end game state" << std::endl;
}

void GameState::updateInput(const float & dt)
{
	this->checkForQuit();

}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget *target)
{
	if (!target)
		target = this->window;

	this->player->render(target);
}


