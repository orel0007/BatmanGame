#include "GameObject.h"

GameObject::GameObject(sf::RectangleShape& shape, UploadImages& loader) 
	: GraphicObject(shape, loader)
{

}

GameObject::~GameObject()
{}