#include "Monster.h"
#include "Controller.h"
#include <string>
#include <stdio.h>
#include <stdlib.h> 

//=====================constructor======================
Monster::Monster(sf::RectangleShape& shape, UploadImages& loader)
	:MovingObject(shape, loader)
{
	set_last_place(getPos());
}

void Monster::check_collision(std::vector< std::unique_ptr <StaticObject>>& static_vec, std::unique_ptr <Digger>& digger)
{
	for (int j = 0; j < static_vec.size(); j++) {
		if (getShape()->getGlobalBounds().intersects(static_vec[j]->getShape()->getGlobalBounds())) {
			(*this).handleCollision(*static_vec[j]);
		}
	}
	if (getShape()->getGlobalBounds().intersects(digger->getShape()->getGlobalBounds())) {
		(*this).handleCollision(*digger);
	}
}

//===============
void Monster::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}
//===============

//===============
//for double dispatch
void Monster::handleCollision(Digger& digger)
{
	digger.handleCollision(*this);
}
//===============

//===============
//for double dispatch
void Monster::handleCollision(Monster& gameObject)
{
	//m_controller.getBoard()->restartLevel();
}
//===============

//===============
//for double dispatch
void Monster::handleCollision(Stone& gameObject)
{
	set_old_place();
}
//===============

//===============
//for double dispatch
void Monster::handleCollision(Wall& gameObject)
{
	set_old_place();
}
//===============

//===============
//for double dispatch
void Monster::handleCollision(Diamond& gameObject)
{
	//m_controller.getBoard()->restartLevel();
}
//===============
void Monster::handleCollision(Present& gameObject)
{
}

Monster::~Monster()
{}