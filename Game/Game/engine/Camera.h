#include <SFML/Graphics.hpp>

using namespace sf;


View view;

View getPlayerCoord(float x, float y) {
	float tempX = x;
	if (x < 300) tempX = 300;
	view.setCenter(tempX, y);
	return view;
}


