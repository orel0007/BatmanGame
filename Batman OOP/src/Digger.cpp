#include "Digger.h"
#include "Controller.h"
#include "GameObject.h"
#include <iostream>
#include <string>

//=====================constructor======================
Digger::Digger(sf::RectangleShape& shape, UploadImages& loader)
	:MovingObject(shape, loader)
{
	reset_score();
	set_sprite(DIGGER);
	set_last_place(getPos());
}

void Digger::move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock)
{
	set_last_place(getPos());
	float dX = 0,
		dY = 0,
		speed = 600 * clock.getElapsedTime().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setAnimation(LEFT, get_sprite());
		dX = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setAnimation(UP, get_sprite());
		dY = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setAnimation(RIGHT, get_sprite());
		dX = speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setAnimation(DOWN, get_sprite());
		dY = speed;
	}
	set_direction(sf::Vector2f(dX, dY));
	can_move(windowsize);
}

void Digger::check_collision(std::vector< std::unique_ptr <StaticObject>>& static_vec, std::vector<std::unique_ptr <Monster>>& monster_vec)
{
	for (size_t i = 0; i < static_vec.size(); i++) {
		if (getShape()->getGlobalBounds().intersects(static_vec[i]->getShape()->getGlobalBounds())) {
			(*this).handleCollision(*static_vec[i]);
		}
	}
	for (size_t i = 0; i < monster_vec.size(); i++) {
		if (getShape()->getGlobalBounds().intersects(monster_vec[i]->getShape()->getGlobalBounds())) {
			(*this).handleCollision(*monster_vec[i]);
		}
	}
}

//===============
void Digger::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);	
}
//===============

//===============
//for double dispatch
void Digger::handleCollision(Digger&)
{
}
//===============

//===============
//for double dispatch
void Digger::handleCollision(Monster& gameObject)
{
	decrease_life();
	set_is_reset(true);
}
//===============

//===============
//for double dispatch
void Digger::handleCollision(Stone& gameObject)
{
	decrease_stone();
}
//===============

//===============
//for double dispatch
void Digger::handleCollision(Wall& gameObject)
{
	set_old_place();
}
//===============

//===============
//for double dispatch
void Digger::handleCollision(Diamond& gameObject)
{
	decrease_diamond();
	add_score(EAT_DIAMOND);
}
//===============
void Digger::handleCollision(Present& gameObject)
{
}

void Digger::decrease_life()
{
	m_life--;
}

void Digger::add_life()
{
	m_life++;
}
int Digger::get_life() const
{
	return m_life;
}

void Digger::set_life(int life)
{
	m_life = life;
}

bool Digger::is_die()
{
	if (get_life() == 0)
		return true;
	return false;
}

bool Digger::is_finish_level()
{
	if (m_diamond == 0)
		return true;
	return false;
}

int Digger::get_score() const
{
	return m_score;
}

void Digger::set_score(int score)
{
	m_score = score;
}

void Digger::add_score(int score)
{
	m_score += score;
}

void Digger::reset_score()
{
	m_score = 0;
}

int Digger::get_stone() const
{
	return m_stone;
}

void Digger::set_stone(int stone)
{
	m_stone = stone;
}

void Digger::add_stone()
{
	m_stone += 2;
}

void Digger::decrease_stone()
{
	m_stone--;
}

int Digger::get_diamond() const
{
	return m_diamond;
}

void Digger::decrease_diamond()
{
	--m_diamond;
}

void Digger::set_diamond(int diamonds)
{
	m_diamond = diamonds;
}

int Digger::get_time() const
{
	return m_time;
}

void Digger::set_time(int time) 
{
	m_time = time;
}

void Digger::decrease_time()
{
	m_time--;
}

void Digger::add_time()
{
	m_time += ADD_TIME;
}

Digger::~Digger()
{}