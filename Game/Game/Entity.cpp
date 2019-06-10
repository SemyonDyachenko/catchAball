#include "Entity.h"



void Entity::initScoreDefaultVariables()
{
this->scoreStr = "Collected ball " + std::to_string(this->score);
this->scoreFont.loadFromFile("fonts/Dosis-Light.ttf");
this->scoreText.setFont(this->scoreFont);
this->scoreText.setCharacterSize(27);
this->scoreText.setString(this->scoreStr);
this->scoreText.setPosition(10,10);
this->scoreText.setFillColor(sf::Color::Black);

}


void Entity::initGameOverDefaultVariables()
{
    this->gameOverShape.setSize(sf::Vector2f(this->window->getSize().x,this->window->getSize().y));
    this->gameOverShape.setPosition(0,0);
    this->pathToGameOverTexture = "../res/images/gameover.png";
    if(!this->gameOverTexture.loadFromFile(this->pathToGameOverTexture)) std::cout << "error load image for gameover"<<std::endl;
    this->gameOverShape.setTexture(&this->gameOverTexture);

}



void Entity::initBallDefaultVariables()
{
    this->BallPath = "../res/images/ball.png";
    if(!this->ballImage.loadFromFile(this->BallPath)) std::cout << "Error load ball image" << std::endl;
    this->ballTexture.loadFromImage(this->ballImage);
    this->ballSprite.setTexture(this->ballTexture);
    this->BallSpeed = 0.1f;
    this->BallPositionY = -100;
    this->BallPositionX = 200;
    this->ballSprite.setPosition(BallPositionX,BallPositionY);
}



void Entity::initDefaultVariables()
{
    if (!this->img.loadFromFile("../res/images/hero.png")) {
        for (size_t i = 0; i < 25; i++)
        {
            std::cout << "ERROR LOAD IMAGE\n";
        }
    }
    this->img.createMaskFromColor(sf::Color::White);
    this->texture.loadFromImage(img);
    this->sprite.setTexture(texture);
    this->width = 73;
    this->height = 66;
    moveDir = STAY;
    this->dx = 0; this->dy = 0;
    this->speed = 0.f;
    this->isCatch = false;
    this->score = 0;
}

Entity::Entity(sf::RenderWindow * window,float x,float y)
{
    this->window = window;
    this->positionX = x;
    this->positionY = y;
    this->initDefaultVariables();
    this->initBallDefaultVariables();
    sprite.setPosition(this->positionX, this->positionY);
    this->initGameOverDefaultVariables();
    this->initScoreDefaultVariables();
    this->GameOver = false;

}

Entity::~Entity()
{
    GameOver = true;
}


float Entity::getPositionX()
{
    return this->positionX;
}

float Entity::getPositionY()
{
    return this->positionY;
}



sf::FloatRect Entity::getRect()
{
    return sf::FloatRect(positionX,positionY,width,height);
}


void Entity::setPosition(float x, float y)
{
    this->positionX = x;
    this->positionY = y;
    this->sprite.setPosition(positionX, positionY);
}

void Entity::checkIsGame()
{
    if(this->GameOver == true) {

    }
}



void Entity::checkCollisionWithBall()
{
    if(this->getRect().intersects(sf::FloatRect(BallPositionX,BallPositionY,53,53))) {

        this->isCatch = true;
        if(this->isCatch == true)
        {
            this->BallPositionY = -100;
            this->BallPositionX = rand()%(this->window->getSize().x-1)+1;
            this->BallSpeed += 0.030f;
            this->score += 1;
            this->scoreStr = "Collected ball " + std::to_string(this->score);
            this->scoreText.setString(this->scoreStr);
        }

    }

    if(!this->getRect().intersects(sf::FloatRect(BallPositionX,BallPositionY,53,53))) {
        if((sf::FloatRect(BallPositionX,BallPositionY,53,53).top-53) > (this->getRect().top))
        {
            this->GameOver = true;
        }
    }

}


void Entity::update(const float & time)
{
    switch (this->moveDir)
    {
        case Entity::STAY:
            break;
        case Entity::LEFT: this->dx = -speed;
            break;
        case Entity::RIGHT: this->dx = speed;
            break;
        case Entity::UP:
            break;
        case Entity::DOWN:
            break;
        default:
            break;
    }

    checkCollisionWithBall();
    this->speed = 0.f;
    checkCollisionWithBall();
    this->BallPositionY += this->BallSpeed * time;
    this->ballSprite.setPosition(this->BallPositionX,this->BallPositionY);
    checkCollisionWithBall();
}

void Entity::render(sf::RenderWindow * window)
{
    window->draw(this->sprite);
    window->draw(this->ballSprite);
    if(this->GameOver == true) {
        window->draw(this->gameOverShape);
    }


        window->draw(this->scoreText);

}






