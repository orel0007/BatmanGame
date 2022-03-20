#include "Toolbar.h"

Toolbar::Toolbar(sf::RectangleShape& shape, UploadImages& loader)
	: m_level(loader) , m_life(loader), 
	m_stones(loader),m_score(loader) ,m_time(loader)
{
	LoadToolbar();
}

void Toolbar::LoadToolbar()
{
	sf::Vector2f pos(0, 0);

	m_level.getText().setPosition(pos);
	pos.x += 280;
	m_life.getText().setPosition(pos);
	pos.x += 250;
	m_score.getText().setPosition(pos);
	pos.x += 250;
	m_stones.getText().setPosition(pos);
	pos.x += 250;
	m_time.getText().setPosition(pos);
}

void Toolbar::draw_toolbar(sf::RenderWindow& window, int level, int life, int stones, int score, int time)
{
	m_level.setText_int("LEVEL: ", level);
	m_level.draw(window);

	m_life.setText_int("LIFE: ", life);
	m_life.draw(window);

	m_stones.setText_int("STONES: ", stones);
	m_stones.draw(window);

	m_score.setText_int("SCORE: ", score);
	m_score.draw(window);

	m_time.setText_int("TIME: ", time);
	m_time.draw(window);
}

Toolbar::~Toolbar()
{}

