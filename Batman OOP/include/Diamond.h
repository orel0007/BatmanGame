//Diamond Class 
//***************
//***************


#pragma once
#include "StaticObject.h"
#include "UploadImages.h"
class Diamond : public StaticObject
{
public:
	Diamond(sf::RectangleShape& shape, UploadImages& loader);
	~Diamond();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	const int EAT_DIAMOND = 15;
	const int DIAMOND = 4;
};