//Button Class 
//***************
//***************
#pragma once
#include "GraphicObject.h"

class Button : public GraphicObject
{
public:
	Button(sf::RectangleShape& shape, UploadImages& loader);
	~Button() = default;
	bool is_on(sf::Vector2f loaction);

private:
};