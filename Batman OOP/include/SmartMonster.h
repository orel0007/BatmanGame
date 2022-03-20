//SmartMonster Class 
//***************
//the object that is try to catch the player.
//***************

#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"

class SmartMonster : public Monster
{
public:
	SmartMonster(sf::RectangleShape& shape, UploadImages& loader);
	~SmartMonster();
	void move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock) override;
	virtual const int get_index() override;
private:
	const int SMART_MONSTER = 3;
};