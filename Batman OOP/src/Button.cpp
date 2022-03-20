#include "Button.h"

Button::Button(sf::RectangleShape& shape, UploadImages& loader)
	: GraphicObject(shape, loader)
{

}

bool Button::is_on(sf::Vector2f loaction)
{//check if mouse is on board location, if if does update the board cell place
	if (getShape()->getGlobalBounds().contains(loaction)) {
		return true;
	}
	return false;
}