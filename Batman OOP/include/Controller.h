//Controller Class 

#pragma once
//-------------- include section --------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <stdarg.h>
#include "UploadImages.h"
#include "Menu.h"
#include <stdio.h>
#include <cstdio>
#include"Board.h"
#include"Digger.h"
#include"Toolbar.h"

//-------------- using section -----------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Controller
{
public:
	Controller();
	~Controller();
	void run_game();
	
private:
	//praivate functions
	void check_end_game();
	void move_digger(sf::Clock clock);
	void move_monsters(sf::Clock clock);
	void start_new_game();
	void new_level();
	void check_game_status();
	void restart_level();
	void end_levels();
	void upload_new_level();
	void add_level();
	void reset_levels();
	//Members
	sf::RenderWindow m_window;
	std::unique_ptr <Toolbar> m_toolbar;
	std::unique_ptr <Menu> m_menu;
	UploadImages m_UploadImages;
	Board m_board;
	sf::Music m_sound;
	const int END_LEVEL = 20;
	int m_level = 1;
	bool m_end_level = false;
};
