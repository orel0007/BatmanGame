#include"MovingObject.h"
//=====================constructor===============
MovingObject::MovingObject(sf::RectangleShape &shape, UploadImages &loader)
	:GameObject(shape, loader), m_loader(loader)
{
	m_last_place = getPos();
	m_start_location = getPos();
}
//===============
//===============
bool MovingObject::can_move(sf::Vector2f windowsize)
{
	if (getPos().x + get_direction().x + getSize().x > windowsize.x) {
		return false;
	}
	if (getPos().x + get_direction().x < 0) {
		return false;
	}
	if (getPos().y + get_direction().y + getSize().y > windowsize.y) {
		return false;
	}
	if (getPos().y + get_direction().y < 50) {
		return false;
	}
	sf::Vector2f pos(getPos().x + m_direction.x, getPos().y + m_direction.y);
	setPos(pos);
	return true;
}
//===============

sf::Vector2f MovingObject::get_direction()
{
	return m_direction;
}

void MovingObject::set_direction(sf::Vector2f direction)
{
	m_direction = direction;
}

bool MovingObject::get_is_reset()
{
	return Reset_place;
}

void MovingObject::set_is_reset(bool boliani)
{
	Reset_place = boliani;
}

void MovingObject::reset_location()
{
	setPos(m_start_location);
}

sf::Vector2f MovingObject::get_last_place()
{
	return m_last_place;
}

void MovingObject::set_last_place(sf::Vector2f location)
{
	m_last_place = location;
}

//=====================
void MovingObject::restartClock()
{
	m_clock.restart();
}
//=====================

//=====================
sf::Clock* MovingObject::getClock()
{
	return &m_clock;
}

void MovingObject::set_old_place()
{
	setPos(get_last_place());
}

//=====================
sf::Sprite& MovingObject::get_sprite()
{
	return m_sprite;
}

void MovingObject::set_sprite(int image)
{
	m_sprite.setTexture(m_loader.get_img(image));
	m_sprite.setTextureRect(sf::IntRect(1* 48, 0 * 48, 48, 48));
	m_sprite.scale((float)getSize().x / m_sprite.getGlobalBounds().width, (float)getSize().y / m_sprite.getGlobalBounds().height);
}

void MovingObject::setAnimation(enum Direction way, sf::Sprite& m_image)
{
	source.y = way;
	animationCounter += m_clock.restart().asMicroseconds();
	if (animationCounter >= animationFrameDuration)
	{
		animationCounter -= animationFrameDuration;
		source.x++;
	}
	if (source.x * 48 >= 48 * 3)
		source.x = 0; 
	m_image.setTextureRect(sf::IntRect(source.x * 48, source.y * 48, 48, 48));
}

void MovingObject::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(getShape()->getPosition());
	window.draw(m_sprite);
}


//===============
MovingObject::~MovingObject()
{
}
