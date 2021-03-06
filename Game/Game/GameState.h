#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"


class GameState :public State
{
private:
    Entity *  player;
    sf::RenderWindow * window;
    sf::RectangleShape backgroundShape;
    sf::Texture backgroundTexture;

    //mouse
    sf::Vector2i pixelPos;
    sf::Vector2f pos;
    //funcs
    void initTextures();
public:
    GameState(sf::RenderWindow * window, std::stack<State*>*states);
    virtual ~GameState();


    //funcs
    void endState();
    void updateInput(const float& time);
    void update(const float & time);
    void render(sf::RenderWindow *window);
};

#endif