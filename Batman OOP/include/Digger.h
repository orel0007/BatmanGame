//Digger Class 
//***************
//the object that is controlled by the player.
//***************

#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "StaticObject.h"

class Digger : public MovingObject
{
public:
	Digger(sf::RectangleShape& shape, UploadImages& loader);
	~Digger();
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	void check_collision(std::vector< std::unique_ptr <StaticObject>>& static_vec, std::vector<std::unique_ptr <Monster>>& monster_vec);
	void move(sf::Vector2f windowsize, sf::Vector2f digger_pos,sf::Clock clock) override;
	void decrease_life();
	int get_life() const;
	void add_life();
	void set_life(int life);
	bool is_die(); //add const
	bool is_finish_level();//add const
	int get_score() const;
	void set_score(int score);
	void add_score(int score);
	void reset_score();
	void set_stone(int stone);
	void decrease_stone();
	int get_stone() const;
	int get_diamond() const;
	void decrease_diamond();
	void set_diamond(int diamonds);
	int get_time() const;
	void set_time(int time);
	void decrease_time();
	void add_time();
	void add_stone();

private:
	const int EAT_DIAMOND = 15;
	const int ADD_TIME = 15;
	int m_life = 3;
	int m_score;
	int m_stone;
	int m_diamond;
	int m_time;
	const int DIGGER = 1;
	sf::Vector2f m_speed;
};

