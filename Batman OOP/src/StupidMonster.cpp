#pragma once
#include "StupidMonster.h"

StupidMonster::StupidMonster(sf::RectangleShape& shape, UploadImages& loader)
	:Monster(shape, loader)  
{
	set_sprite(get_index());
	m_randomClock.restart();
	m_side = rand() % 4;
}

void StupidMonster::move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock)
{
	set_last_place(getPos());
	float dX = 0,
		dY = 0,
		speed = float(0.5 * (*getClock()).getElapsedTime().asSeconds());
	if ((*getClock()).getElapsedTime().asSeconds() > 1)
		(*getClock()).restart();

	if (m_randomClock.getElapsedTime().asSeconds() > 2) {
		m_side = rand() % 4;
		m_randomClock.restart();
	}
	if (m_side == 0)
	{
		dX = speed;
	}
	else if (m_side == 1)
	{
		dY = -speed;
	}
	else if (m_side == 2)
	{
		dX = -speed;
	}
	else if (m_side == 3)
	{
		dY = speed;
	}
	set_direction(sf::Vector2f(dX, dY));
	can_move(windowsize);
}

const int StupidMonster::get_index()
{
	return STUPID_MONSTER;
}

StupidMonster::~StupidMonster()
{}