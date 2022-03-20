#include "StaticObject.h"

StaticObject::StaticObject(sf::RectangleShape &shape, UploadImages  &loader)
	:GameObject(shape, loader)
{
}

bool StaticObject::get_deleteMe()
{
	return deleteMe;
}

void StaticObject::set_delete_me() {
	deleteMe = true;
}

//==================
StaticObject::~StaticObject()
{
}
//==================
