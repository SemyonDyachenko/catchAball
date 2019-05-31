#include "State.h"




State::State(sf::RenderWindow * window,std::stack<State*>* states)
{
	this->window = window;
	this->quit = false; // по умолчанию значение выхода из состояния равно = false
	this->states = states;
	//this->supportedKeys = supportedKeys;
}

State::~State()
{
}

const bool & State::getQuit() const
{
	return this->quit; // возращаем токущее состояние переменной
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) /* если нажата клавиша escape то состояние переменной выхода  = true то есть мы вышли из состояния (state) */
	{
		this->quit = true;
	}
}


void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}


