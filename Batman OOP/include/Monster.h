//Monster Class 
//***************
//***************

#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(sf::RectangleShape& shape, UploadImages& loader);
	~Monster();
	virtual void move(sf::Vector2f windowsize, sf::Vector2f digger_pos, sf::Clock clock) = 0;
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Digger& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Monster& gameObject) override;
	virtual void handleCollision(Stone& gameObject) override;
	virtual void handleCollision(Diamond& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	virtual const int get_index() = 0;
	void check_collision(std::vector< std::unique_ptr <StaticObject>>& static_vec, std::unique_ptr <Digger>& digger);	
};