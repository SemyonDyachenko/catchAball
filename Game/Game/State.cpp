#include "State.h"




State::State(sf::RenderWindow * window,std::stack<State*>* states)
{
    this->window = window;
    this->quit = false; // ïî óìîë÷àíèþ çíà÷åíèå âûõîäà èç ñîñòîÿíèÿ ðàâíî = false
    this->states = states;
    //this->supportedKeys = supportedKeys;
}

State::~State()
{
}

const bool & State::getQuit() const
{
    return this->quit; // âîçðàùàåì òîêóùåå ñîñòîÿíèå ïåðåìåííîé
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) /* åñëè íàæàòà êëàâèøà escape òî ñîñòîÿíèå ïåðåìåííîé âûõîäà  = true òî åñòü ìû âûøëè èç ñîñòîÿíèÿ (state) */
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
