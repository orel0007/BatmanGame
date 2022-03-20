//Wall Class 
//***************
//can't walk through it
//***************


#pragma once
#include "StaticObject.h"
#include "MovingObject.h"
#include "UploadImages.h"

class Wall : public StaticObject
{
public:
	Wall(sf::RectangleShape& shape, UploadImages& loader);
	~Wall();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	const int WALL = 6;
};

