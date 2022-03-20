#include "Diamond.h"
#include "Digger.h"

//===================constructor==================
Diamond::Diamond(sf::RectangleShape& shape, UploadImages& loader)
	:StaticObject(shape, loader)
{
	getShape()->setTexture(&loader.get_img(DIAMOND));
}
//===============

//==================
Diamond::~Diamond()
{
}
//===================

//===================
//for double dispatch
void Diamond::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Diamond::handleCollision(Digger& digger)
{
	set_delete_me();
	digger.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void Diamond::handleCollision(Monster&)
{
}
//==================

//===================
//for double dispatch
void Diamond::handleCollision(Diamond&)
{
}
//==================

//===================
//for double dispatch
void Diamond::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void Diamond::handleCollision(Stone&)
{
}
//==================
void Diamond::handleCollision(Present& gameObject)
{

}