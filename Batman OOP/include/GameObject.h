//Objects Class 
//***************
//this a father for all game objects in the game
//***************
#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "UploadImages.h"
#include "GraphicObject.h"

class Digger;
class Wall;
class Diamond;
class Monster;
class Stone;
class Present;

class GameObject : public GraphicObject
{
public:
	GameObject(sf::RectangleShape &shape, UploadImages& loader);
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Digger& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Monster& gameObject) = 0;
	virtual void handleCollision(Stone& gameObject) = 0;
	virtual void handleCollision(Diamond& gameObject) = 0;
	virtual void handleCollision(Present& gameObject) = 0;
	~GameObject();
};

