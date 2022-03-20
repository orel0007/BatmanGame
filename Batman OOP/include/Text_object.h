#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicObject.h"

class Text_object 
{
public:
	Text_object(UploadImages& loader);
	void draw(sf::RenderWindow& window);
	~Text_object();
	void changeTextColor(sf::Color color);
	sf::Text& getText();
	void setText(std::string);
	void setText_int(std::string str, int num);
private:
	sf::Text m_text;
};

