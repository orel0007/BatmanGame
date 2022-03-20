//ClockPresent Class 
//***************
//can't walk through it
//***************
#pragma once
#include "Present.h"

class ClockPresent : public Present
{
public:
	ClockPresent(sf::RectangleShape& shape, UploadImages& loader);
	~ClockPresent();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& digger) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	virtual const int get_index() override;
	const int CLOCK_PRESENT = 14;
};