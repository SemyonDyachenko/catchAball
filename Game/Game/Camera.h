#ifndef CAMERA_H
#define CAMERA_H

#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Level.h"


class Camera
{
private:
	sf::View view;
public:
	Camera();

	
	virtual ~Camera();
};

#endif