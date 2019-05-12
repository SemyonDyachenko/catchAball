#include "MainMenuState.h"




MainMenuState::MainMenuState(sf::RenderWindow * window) : State(window)
{

}

MainMenuState::~MainMenuState()	
{

}

void MainMenuState::endState()
{
	std::cout << " end MainMenu state" << std::endl;
}

void MainMenuState::updateInput(const float & dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float & dt)
{

}

void MainMenuState::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;
}
