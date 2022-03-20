#include "Wall.h"
#include "Digger.h"
#include "Monster.h"

//===================constructor==================
Wall::Wall(sf::RectangleShape& shape, UploadImages& loader)
	:StaticObject(shape, loader)
{
	getShape()->setTexture(&loader.get_img(WALL));
}
//===============

//===================
//for double dispatch
void Wall::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================
void Wall::handleCollision(Present& gameObject)
{
}
//===================
//for double dispatch
void Wall::handleCollision(Digger& digger)
{
	digger.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Wall::handleCollision(Monster& monster)
{
	monster.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Wall::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void Wall::handleCollision(Stone&)
{
}
//==================

//===================
//for double dispatch
void Wall::handleCollision(Diamond&)
{
}
//==================

//==================
Wall::~Wall()
{
}
//===================