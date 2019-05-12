#ifndef GAME_H
#define GAME_H

#include "States/GameState.h"


class Game
{
private:
	sf::RenderWindow * window;
	sf::Event event;
	sf::Clock clock;
	float time;

	std::stack<State*> states;

	
	std::map<std::string, int> supportedKeys;
		
	
	// window params ..
	unsigned winSizeX; // width window
	unsigned winSizeY; // height window
	bool vertical_sync_enable; //vsync
	std::string winTitle; // window title
	unsigned FrameRateLimit; // fps limi


	//init
	void initWindow();
	void initStates();
public:
	// constructor , destructor
	Game();
		
	~Game();

	//Regular
	void endApplication();

	//funcs
	void updateDeltaTime();
	void updateEvents();
	void update();

	//Render
	void render();

	//Run
	void run();
};

#endif`

