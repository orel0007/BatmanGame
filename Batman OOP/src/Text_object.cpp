#include "Text_object.h"

Text_object::Text_object(UploadImages& loader)
{
	m_text.setFont(*loader.getFont());
}

void Text_object::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void Text_object::changeTextColor(sf::Color color)
{
	m_text.setFillColor(color);
}

sf::Text& Text_object::getText()
{
	return m_text;
}

void Text_object::setText(std::string str)
{
	m_text.setString(str);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(3.0f);
}

void Text_object::setText_int(std::string str, int num)
{
	std::string new_str = str;
	new_str.append(std::to_string(num));
	setText(new_str);
}

Text_object::~Text_object()
{
}