#include "ClockPresent.h"
#include "Digger.h"

ClockPresent::ClockPresent(sf::RectangleShape& shape, UploadImages& loader)
	:Present(shape, loader)
{
	getShape()->setTexture(&loader.get_img(get_index()));
}

//===================
//for double dispatch
void ClockPresent::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void ClockPresent::handleCollision(Digger& digger)
{
	set_delete_me();
	digger.add_time();
}
//==================

//===================
//for double dispatch
void ClockPresent::handleCollision(Monster&)
{
}
//==================

//===================
//for double dispatch
void ClockPresent::handleCollision(Diamond&)
{
}
//==================

//===================
//for double dispatch
void ClockPresent::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void ClockPresent::handleCollision(Stone&)
{
}
//==================
void ClockPresent::handleCollision(Present&)
{
}

const int ClockPresent::get_index()
{
	return CLOCK_PRESENT;
}

ClockPresent::~ClockPresent()
{
}