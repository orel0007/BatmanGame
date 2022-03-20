//GraphicObject Class 
//***************
//this a father for all grapghical objects in the game
//***************
#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "UploadImages.h"

class GraphicObject
{
public:
	GraphicObject(sf::RectangleShape& shape, UploadImages& loader);
	virtual ~GraphicObject();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f pos);
	sf::Vector2f getSize();
	void  setSize(sf::Vector2f pos);
	sf::RectangleShape* getShape();
	virtual void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_shape;
	UploadImages& m_loader;
};

