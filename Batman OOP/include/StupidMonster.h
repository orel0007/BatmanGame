//StupidMonster Class 
//***************
//move by random.
//***************

#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"

class StupidMonster : public Monster
{
public:
	StupidMonster(sf::RectangleShape& shape, UploadImages& loader);
	~StupidMonster();
	void move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock) override;
	virtual const int get_index() override;
private:
	const int STUPID_MONSTER = 2;
	sf::Clock m_randomClock;
	int m_side;
};