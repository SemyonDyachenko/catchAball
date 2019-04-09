#include <SFML/Graphics.hpp>

using namespace sf;


View view;

View getPlayerCoord(float x, float y) {
	view.setCenter(x + 100, y);
	return view;
}

View changeview() {
	if (Keyboard::isKeyPressed(Keyboard::X)) {
		view.setSize(800, 600);
	}
	if (Keyboard::isKeyPressed(Keyboard::Y)) {
		view.setSize(540, 430);
	}
	return view;
}