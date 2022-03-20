#include "Board.h"
#include "MoneyPresent.h"
#include "ClockPresent.h"
#include "StonePresent.h"

Board::Board(sf::Vector2f windowSize, UploadImages& UploadImages) :m_UploadImages(UploadImages)
, m_windowSize(windowSize)
{//Board constructor
	openFile("Board.txt");
	read(windowSize);
	m_score = 0;
	background_rec.setSize(windowSize);
	background_rec.setTexture(&m_UploadImages.get_img(10));

	
}
//==============
void Board::openFile(std::string fileName)
{//open file for read
	m_file.open(fileName);

	if (!m_file.is_open())
	{
		std::cout << "file error \n";
	}
}
//================

//================
void Board::read(sf::Vector2f windowSize)
{//read the level from the file and initalize objects
	m_pose_file = int(m_file.tellg());
	reset_diamond();
	sf::Clock clock;
	sf::RectangleShape rec;
	sf::RectangleShape moving_rec;
	int stones, time;
	m_file >> m_col >> m_row >> stones >> time;//update the board data
	char c;
	//update size of each elemnt on the window
	float col_size = windowSize.x / m_col;
	float row_size = (windowSize.y - WIN_MIN_COL) / m_row;
	rec.setSize(sf::Vector2f(col_size-10, row_size-10));
	moving_rec.setSize(sf::Vector2f(col_size-10, row_size-10));
	m_file.get(c);//skip '\n
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			rec.setPosition(sf::Vector2f(col_size * j, WIN_MIN_COL + i * row_size));
			moving_rec.setPosition(sf::Vector2f(col_size * j, WIN_MIN_COL + i * row_size));
			m_file.get(c);
			if (c == '/') {
				m_digger = std::make_unique<Digger>(moving_rec, m_UploadImages);
				m_digger->set_life(m_digger_life);
				m_digger->set_score(m_score);
			}
			rec.setPosition(sf::Vector2f(col_size * j, WIN_MIN_COL + i * row_size));
			rec.setSize(sf::Vector2f(col_size, row_size));
			if (c == 'D') {
				m_static_vec.push_back(std::make_unique<Diamond>(rec, m_UploadImages));
				m_diamond++;
			}
			if (c == '#') {
				m_static_vec.push_back(std::make_unique<Wall>(rec, m_UploadImages));
			}
			if (c == '@') {
				m_static_vec.push_back(std::make_unique<Stone>(rec, m_UploadImages));
			}
			if (c == '!') {
				add_monster_kind(moving_rec, m_UploadImages);
			}
			if (c == '+') {
				add_present_kind(moving_rec, m_UploadImages);
			}
		}
		m_file.get(c);
	}
	m_digger->set_stone(stones);
	m_digger->set_time(time);
	m_digger->set_diamond(m_diamond);
}

std::unique_ptr <Digger>& Board::get_digger()
{
	return m_digger;
}

void  Board::add_monster_kind(sf::RectangleShape& shape, UploadImages& loader)
{// choose the kind of monster by random :1)SmartMonster 2)StupidMonster
	int monster_kind = rand() % 3;//change
	if (monster_kind == 0)
		m_monster_vec.push_back(std::make_unique<SmartMonster>(shape, loader));
	else
		m_monster_vec.push_back(std::make_unique<StupidMonster>(shape, m_UploadImages));
}

void  Board::add_present_kind(sf::RectangleShape& shape, UploadImages& loader)
{// choose the kind of present by random :1)MoneyPresent 2)ClockPresent 3)StonePresent
	int present_kind = rand() % 3;//change
	if (present_kind == 0)
		m_static_vec.push_back(std::make_unique<MoneyPresent>(shape, loader));
	else if(present_kind == 1)
		m_static_vec.push_back(std::make_unique<ClockPresent>(shape, loader));
	else
		m_static_vec.push_back(std::make_unique<StonePresent>(shape, m_UploadImages));
}

std::vector< std::unique_ptr <StaticObject>>& Board::get_static_vec()
{
	return m_static_vec;
}

std::vector< std::unique_ptr <Monster>>& Board::get_monster_vec()
{
	return m_monster_vec;
}

bool Board::is_file_end()
{
	return m_file.eof();
}

void Board::check_time()
{//check if past more than a secends
	if (m_clock_time.getElapsedTime().asSeconds() > 1) {
		m_digger->decrease_time();
		m_clock_time.restart();
	}
}

void Board::draw_board_objects(sf::RenderWindow& window)
{//draw all objects to the screen
	window.draw(background_rec);
	for (int i = 0; i < m_static_vec.size(); i++)
	{
		m_static_vec[i]->draw(window);
	}

	for (int i = 0; i < m_monster_vec.size(); i++)
	{
		m_monster_vec[i]->draw(window);
	}
	m_digger->draw(window);
}

void Board::delete_objects()
{//delete objects
	for (size_t i = 0; i < m_static_vec.size(); i++) {
		if (m_static_vec[i]->get_deleteMe()) {
			*m_static_vec.erase((m_static_vec.begin() + i));
		}
	}
}

int Board::get_diamond() const
{
	return m_diamond;
}

void Board::reset_diamond()
{
	m_diamond = 0;
}

void Board::update_digger_life() {
	//update digger life and score
	if (m_digger->get_life() == 0) {
		m_digger_life = 3;
		m_score = 0;
	}
	else {
		m_digger_life = m_digger->get_life();
		m_score = m_digger->get_score();
	}
}

void Board::clean_objects()
{//restart the vector of the board
	m_static_vec.clear();
	m_monster_vec.clear();
	reset_diamond();
}

void Board::reset_movingobject_place(sf::RenderWindow& window)
{//reset monnsters and digger place
	for (size_t i = 0; i < m_monster_vec.size(); i++) {
		(*m_monster_vec[i]).reset_location();
	}
	(*m_digger).reset_location();
	m_digger->set_is_reset(false);
	draw_board_objects(window);
}

void Board::clear_file()
{//reset the read file place
	m_file.clear();//restart the file to the start
	m_pose_file = 0;//no need
}

void Board::restart_file_level()
{
	m_file.clear();
	m_file.seekg(m_pose_file);
}

Board::~Board()
{
}


