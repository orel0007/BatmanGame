#include "StonePresent.h"
#include "Digger.h"


StonePresent::StonePresent(sf::RectangleShape& shape, UploadImages& loader)
	:Present(shape, loader)
{
	getShape()->setTexture(&loader.get_img(get_index()));
}

//===================
//for double dispatch
void StonePresent::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void StonePresent::handleCollision(Digger& digger)
{
	set_delete_me();
	digger.add_stone();
}
//==================

//===================
//for double dispatch
void StonePresent::handleCollision(Monster&)
{
}
//==================

//===================
//for double dispatch
void StonePresent::handleCollision(Diamond&)
{
}
//==================

//===================
//for double dispatch
void StonePresent::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void StonePresent::handleCollision(Stone&)
{
}
//==================
void StonePresent::handleCollision(Present&)
{
}

const int StonePresent::get_index()
{
	return STONE_PRESENT;
}

StonePresent::~StonePresent()
{
}