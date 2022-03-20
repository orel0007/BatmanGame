#pragma once
#include "SmartMonster.h"

SmartMonster::SmartMonster(sf::RectangleShape& shape, UploadImages& loader)
	:Monster(shape, loader)  //m_timeNum(time)
{
	set_sprite(SMART_MONSTER);
}

void SmartMonster::move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock)
{
	set_last_place(getPos());
	float dX = 0,
		dY = 0,
		speed = float(0.5 * (*getClock()).getElapsedTime().asSeconds());
	if ((*getClock()).getElapsedTime().asSeconds() > 2)
		(*getClock()).restart();
	if (std::abs(digger_pos.x - getPos().x) > std::abs(digger_pos.y - getPos().y))
	{
		if (digger_pos.x > getPos().x) {
			dX = speed;
		}
		else {
			dX = -speed;
		}
	}
	else
	{
		if (digger_pos.y > getPos().y)
		{
			dY = speed;
			//setAnimation(UP, get_sprite());
		}
		else
		{
			dY = -speed;
			//setAnimation(DOWN, get_sprite());
		}
	}

	set_direction(sf::Vector2f(dX, dY));

	can_move(windowsize);
}

const int SmartMonster::get_index()
{
	return SMART_MONSTER;
}

SmartMonster::~SmartMonster()
{}