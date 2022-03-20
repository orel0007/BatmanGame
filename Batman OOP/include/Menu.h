//Menu Class Header
//***************
//Menu holds buttons and background
//***************
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */
#include "UploadImages.h"
#include <stdio.h>
#include <cstdio>
#include "Button.h"
#include "Text_object.h"


class Menu
{
public:
	Menu(sf::Vector2f windowSize, UploadImages& UploadImages);
	void draw(sf::RenderWindow& window);
	void run(sf::RenderWindow& window);
	void Menu_mouse(sf::Vector2f loaction, sf::RenderWindow& window);
	void set_game_over_background();
	~Menu();

private:
	void add_game_over_background(sf::RenderWindow& window);
	void reset_color();
	sf::RectangleShape m_rec;
	std::unique_ptr <Button>  m_play_again;
	std::unique_ptr <Button>  m_exit;
	sf::RectangleShape m_background_rec;
	sf::RectangleShape m_game_over_rec;
	const int PLAY_AGAIN = 8;
	const int EXIT = 9;
	const int MENU_IMAGE = 11;
	const int GAME_OVER = 12;
	Text_object m_game_Status;
	bool m_game_over = false;
};