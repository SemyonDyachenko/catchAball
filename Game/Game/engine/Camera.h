#include <SFML/Graphics.hpp>

using namespace sf;


View view;

View getPlayerCoord(float x, float y,float WinX,float WinY) {
	float tempX = x;
	float mediumX;
	if (WinX <= 800) {
		mediumX = WinX / 2.6;
	}
	else {
		mediumX = WinX / 2.833333;
	}
	if (x < mediumX) { tempX = mediumX; }
	view.setCenter(tempX, y);
	return view;
}


