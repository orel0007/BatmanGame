//MoneyPresent Class 
//***************
//***************

#pragma once
#include "Present.h"

class MoneyPresent : public Present
{
public:
	MoneyPresent(sf::RectangleShape& shape, UploadImages& loader);
	~MoneyPresent();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& digger) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	virtual const int get_index() override;
	const int MONEY_SCORE = 30;
	const int MONEY_PRESENT = 13;
};