#ifndef ENTITY_H
#define ENTITY_H


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


class Entity
{
private:

protected:
    sf::RenderWindow * window;
    sf::Sprite sprite;
    float speed;
    float width, height;
    sf::Texture texture;
    float dx, dy;
    enum EntityMovement { STAY, LEFT, RIGHT, UP, DOWN };
    EntityMovement moveDir;
    bool onGround;
    sf::Image img;
    float positionX;
    float positionY;

    //score
    int score;
    sf::Text  scoreText;
    sf::Font scoreFont;
    std::string scoreStr;

    //ball
    sf::Sprite ballSprite;
    sf::Image ballImage;
    sf::Texture ballTexture;
    bool isCatch;
    float BallPositionX,BallPositionY;
    float BallSpeed;
    std::string BallPath;

    sf::Vector2i pixelPoss;
    sf::Vector2f poss;


    //game over state
    sf::RectangleShape gameOverShape;
    sf::Texture gameOverTexture;
    std::string pathToGameOverTexture;


    //init
    void initScoreDefaultVariables();
    void initGameOverDefaultVariables();
    void initBallDefaultVariables();
    void initDefaultVariables();
public:
    Entity(sf::RenderWindow * window,float x,float y);
    virtual ~Entity();


    //virtual void movement(const float& dt);

    // ïîçèöèè
    float getPositionX();
    float getPositionY();
    sf::View view;
    //levels

    bool GameOver;


    //movement functions


    sf::FloatRect getRect();
    void movement(const float& dt);
    void loseHp();
    void getHp();
    void setPosition(float x, float y);
    void checkIsGame();

    //level


    // update , render
    void checkCollisionWithBall();
    virtual void update(const float& time);
    virtual void render(sf::RenderWindow * window);

};

#endif

