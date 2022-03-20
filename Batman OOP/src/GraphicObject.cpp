#include "GraphicObject.h"

//====================constructor================
GraphicObject::GraphicObject(sf::RectangleShape& shape, UploadImages& loader)
	:m_shape(shape), m_loader(loader)
{
}
//==============

//=============
sf::Vector2f GraphicObject::getPos()
{
	return m_shape.getPosition();
}
//=============

void  GraphicObject::setPos(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}
//==============

//=============
sf::Vector2f GraphicObject::getSize()
{
	return m_shape.getSize();
}
//==============

void  GraphicObject::setSize(sf::Vector2f pos)
{
	m_shape.setSize(pos);
}
//==============

//==============
sf::RectangleShape* GraphicObject::getShape()
{
	return &m_shape;
}
//===============

//===============
void GraphicObject::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}
//===============

//==============
GraphicObject::~GraphicObject()
{
}
//=============