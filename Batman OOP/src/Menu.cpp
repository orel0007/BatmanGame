#include "Menu.h"


Menu::Menu(sf::Vector2f windowSize, UploadImages& UploadImages) : m_game_Status(UploadImages)
{//constructor toolbar
	m_background_rec.setSize(windowSize);
	m_background_rec.setTexture(&UploadImages.get_img(MENU_IMAGE));
	
	sf::RectangleShape rec_button;
	float size_col =200, size_row = 150,
		pos_col = windowSize.x / 2 - (size_col /2), pos_row = windowSize.y / 2;

	
	sf::Vector2f pos(pos_col, pos_row);
	sf::Vector2f size(size_col, size_row);
	
	rec_button.setSize(size);
	rec_button.setSize(size);

	rec_button.setPosition(pos);
	m_play_again = std::make_unique<Button>(rec_button, UploadImages);
	m_play_again->getShape()->setTexture(&UploadImages.get_img(PLAY_AGAIN));

	pos.y += size_row + 50;
	rec_button.setPosition(pos);
	m_exit = std::make_unique<Button>(rec_button, UploadImages);
	m_exit->getShape()->setTexture(&UploadImages.get_img(EXIT));
	
	m_game_Status.getText().setPosition(sf::Vector2f(450,0));
	m_game_Status.getText().setCharacterSize(50);
	m_game_Status.getText().setFillColor(sf::Color::Red);
}


void Menu::run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		window.clear();
		
		draw(window);
		
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (sf::Event::MouseMoved)
			{
				auto location = 
					window.mapPixelToCoords(
					{ event.mouseMove.x, event.mouseMove.y });
					Menu_mouse(location, window);
			}
			if (sf::Event::MouseButtonReleased) {
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (m_play_again->is_on(location)) {
					window.clear();
					return;
				}
				if (m_exit->is_on(location)){
					window.close();
					return;
				}
			}
		}
	}
}

void Menu::Menu_mouse(sf::Vector2f loaction, sf::RenderWindow& window)
{// if the mouse is on cell, change it red if not empty and yellow if empty 	
	if (m_play_again->is_on(loaction)) {
		m_play_again->getShape()->setFillColor(sf::Color::Yellow);
	}
	else 
		m_play_again->getShape()->setFillColor(sf::Color::White);
	if (m_exit->is_on(loaction)) {
		m_exit->getShape()->setFillColor(sf::Color::Yellow);
	}
	else
		m_exit->getShape()->setFillColor(sf::Color::White);
	m_play_again->draw(window);
	m_play_again->draw(window);
}

void Menu::reset_color()
{
	m_play_again->getShape()->setFillColor(sf::Color::White);
	m_exit->getShape()->setFillColor(sf::Color::White);
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_background_rec);
	m_play_again->draw(window);
	m_exit->draw(window);
	add_game_over_background(window);
	m_game_Status.draw(window);
}

void Menu::add_game_over_background(sf::RenderWindow& window)
{
	std::string str;
	if (m_game_over == true) {

		str = "GAME OVER";
		m_game_Status.setText(str);
	}
	else {
		str = "START_GAME";
		m_game_Status.setText(str);
	}
}

void Menu::set_game_over_background()
{
	m_game_over = true;
}

Menu::~Menu()
{
}