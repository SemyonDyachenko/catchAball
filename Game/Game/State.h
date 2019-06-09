#ifndef STATE_H
#define STATE_H


#include "Entity.h"


class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow * window; // окно
	//std::map<std::string, int>* supportedKeys;
	//std::map<std::string, int> keybinds;
	bool quit; // переменая отвечающая за нахождении в текущем стостоянии (state)
	
	//res
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



	std::vector<sf::Texture> textures;

	//funcs
	//virtual void keybinds() = 0;

public:
	State(sf::RenderWindow * window,std::stack<State*>* states); // конструктор принимает на вход sfml окно
	virtual ~State();// виртуальный диструктор

	const bool& getQuit() const; // получить значение quit выхода из состояния

	virtual void checkForQuit(); // функция проверки на конец состояния

	//функции которые обязательно должны быть переопределены
	virtual void endState() = 0; //завершение текущего состояния
	virtual void updateMousePosition();
	virtual void updateInput(const float& time) = 0; // функция которая отвечает за обновление входящей информации 
	virtual void update(const float& time) = 0; // апдейт принимает время delta time (Dt)
	virtual void render(sf::RenderWindow * window) = 0; // функция рендера
};

#endif

