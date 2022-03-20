#include "MoneyPresent.h"
#include "Digger.h"


MoneyPresent::MoneyPresent(sf::RectangleShape& shape, UploadImages& loader)
	:Present(shape, loader)
{
	getShape()->setTexture(&loader.get_img(get_index()));
}

//===================
//for double dispatch
void MoneyPresent::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//==================

//===================
//for double dispatch
void MoneyPresent::handleCollision(Digger& digger)
{
	set_delete_me();
	digger.add_score(MONEY_SCORE);
}
//==================

//===================
//for double dispatch
void MoneyPresent::handleCollision(Monster&)
{
}
//==================

//===================
//for double dispatch
void MoneyPresent::handleCollision(Diamond&)
{
}
//==================

//===================
//for double dispatch
void MoneyPresent::handleCollision(Wall&)
{
}
//==================

//===================
//for double dispatch
void MoneyPresent::handleCollision(Stone&)
{
}
//==================
void MoneyPresent::handleCollision(Present&)
{
}

const int MoneyPresent::get_index()
{
	return MONEY_PRESENT;
}

MoneyPresent::~MoneyPresent()
{
}