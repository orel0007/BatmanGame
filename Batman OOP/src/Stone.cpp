#include "Stone.h"
#include "Monster.h"
#include "Digger.h"

//===================constructor==================
Stone::Stone(sf::RectangleShape& shape, UploadImages& loader)
	:StaticObject(shape, loader)
{
	getShape()->setTexture(&loader.get_img(STONE));
}
//===============

//===================
//for double dispatch
void Stone::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Stone::handleCollision(Digger& digger)
{
	set_delete_me();
	digger.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Stone::handleCollision(Monster& monster)
{
	monster.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Stone::handleCollision(Stone&)
{
}
//==================

//===================
//for double dispatch
void Stone::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void Stone::handleCollision(Diamond&)
{
}
//==================
void Stone::handleCollision(Present& gameObject) 
{
}

//==================
Stone::~Stone()
{
}
//===================