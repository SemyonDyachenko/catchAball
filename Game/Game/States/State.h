#ifndef STATE_H
#define STATE_H


#include "../entites/Entity.h"


class State
{
private:

protected:
	sf::RenderWindow * window;
	//std::map<std::string, int>* supportedKeys;
	//std::map<std::string, int> keybinds;
	bool quit;
	
	//res
	std::vector<sf::Texture> textures;

	//funcs
	//virtual void keybinds() = 0;

public:
	State(sf::RenderWindow * window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0; // const delta time
	virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif

