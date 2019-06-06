#include "GameState.h"



GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states) : State(window, states)
{

	this->player.view.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	this->window = window;
}


GameState::~GameState()
{
	
	//delete this->player;
	this->window->setView(window->getDefaultView());
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
	this->player.update(dt);
	this->window->setView(this->player.view);
}

void GameState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

	this->player.render(window);
	
}


