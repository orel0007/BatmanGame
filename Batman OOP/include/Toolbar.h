#pragma once
#include "GraphicObject.h"
#include "Text_object.h"

class Toolbar
{
public:
	Toolbar(sf::RectangleShape& shape, UploadImages& loader);
	void draw_toolbar(sf::RenderWindow& window, int level, int life, int stones, int score, int time);
	~Toolbar();
private:
	void LoadToolbar();
	//Members
	Text_object m_level;
	Text_object m_life;
	Text_object m_stones;
	Text_object m_score;
	Text_object m_time;
};