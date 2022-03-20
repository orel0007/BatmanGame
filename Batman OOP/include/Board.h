#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <vector>
#include <stdarg.h>  
#include <cmath>
#include <memory>
#include <fstream>
#include "UploadImages.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Monster.h"
#include "StupidMonster.h"
#include "SmartMonster.h"
#include "Stone.h"
#include "Diamond.h"
#include "Wall.h"
#include "Digger.h"
#include "Present.h"
#include "Text_object.h"


class Board
{
public:
	Board(sf::Vector2f windowSize, UploadImages& UploadImages);
	~Board();
	void read(sf::Vector2f windowSize);
	void draw_board_objects(sf::RenderWindow& window);
	void delete_objects();
	void reset_movingobject_place(sf::RenderWindow& window);
	void clean_objects();
	int get_diamond() const;
	void reset_diamond();
	void check_time();
	void add_monster_kind(sf::RectangleShape& shape, UploadImages& loader);
	void update_digger_life();
	void restart_file_level();
	std::unique_ptr <Digger>& get_digger();
	std::vector< std::unique_ptr <StaticObject>>& get_static_vec();
	std::vector< std::unique_ptr <Monster>>& get_monster_vec();
	void  clear_file();
	bool is_file_end();

private:
	//private functions
	void  add_present_kind(sf::RectangleShape& shape, UploadImages& loader);
	void openFile(std::string fileName);
	//Members
	std::fstream m_file;
	UploadImages& m_UploadImages;
	sf::Vector2f m_windowSize;
	sf::Clock m_clock_time;
	sf::RectangleShape background_rec;
	std::vector< std::unique_ptr <StaticObject>> m_static_vec;
	std::vector<std::unique_ptr <Monster>> m_monster_vec;
	std::unique_ptr <Digger> m_digger;
	int m_row, m_col;
	const float WIN_MIN_COL = 50;
	int m_diamond = 0;
	int m_pose_file;
	int m_score = 0;
	int m_digger_life = 3;	
	
};
