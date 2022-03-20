//Stone Class 
//***************
//player can go through it
//***************


#pragma once
#include "StaticObject.h"
#include "UploadImages.h"

class Stone : public StaticObject
{
public:
	Stone(sf::RectangleShape& shape, UploadImages& loader);
	~Stone();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	const int STONE = 5;
};

