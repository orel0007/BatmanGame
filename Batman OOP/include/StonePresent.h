//StonePresent Class 
//***************
//give more stone to eat
//***************

#pragma once
#include "Present.h"

class StonePresent : public Present
{
public:
	StonePresent(sf::RectangleShape& shape, UploadImages& loader);
	~StonePresent();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	virtual const int get_index() override;
	const int STONE_PRESENT = 15;
};