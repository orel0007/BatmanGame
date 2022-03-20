#include "Controller.h"


Controller::Controller()//constructor
	:m_window(sf::VideoMode(1200, 750), "DIGGER_GAME", sf::Style::Titlebar | sf::Style::Close),
	m_board(sf::Vector2f(m_window.getSize()), m_UploadImages)
{
	sf::RectangleShape rec_toolbar;
	//Toolbar initalize
	m_toolbar = std::make_unique<Toolbar>(rec_toolbar, m_UploadImages);
	//menu initalize
	m_menu = std::make_unique<Menu>(sf::Vector2f(m_window.getSize()), m_UploadImages);
	//gift graphic object
}

void Controller::run_game()
{
	sf::Clock clock;
	sf::Clock clock_gifts;

	m_menu->run(m_window);

	m_menu->set_game_over_background();

	m_sound.openFromFile("batmanmusic.ogg");

	m_sound.play();

	m_sound.setLoop(true);

	while (m_window.isOpen())
	{
		m_window.clear();

		check_game_status();

		check_end_game();

		m_board.delete_objects();
	
		m_toolbar->draw_toolbar(m_window, m_level,
			m_board.get_digger()->get_life(), m_board.get_digger()->get_stone(), m_board.get_digger()->get_score()
			, m_board.get_digger()->get_time());

		m_window.display();

		clock.restart();

		move_monsters(clock);

		move_digger(clock);

		check_game_status();

		sf::Event event;

		while (m_window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				cout << "END_GAME";	
				m_window.close();
				break;
			case sf::Event::KeyPressed: {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					cout << "EXIT GAME" << endl;
					m_window.close();
				}
			}
			}
		}
	}
}

void Controller::check_end_game()
{
	if (m_end_level) {
		m_menu->run(m_window);
		start_new_game();
		restart_level();
	}
}

void Controller::move_digger(sf::Clock clock)
{//MOVE DIGGER
	m_board.get_digger()->move(sf::Vector2f(m_window.getSize()), m_board.get_digger()->getPos(), clock);
	m_board.get_digger()->check_collision(m_board.get_static_vec(), m_board.get_monster_vec());
	m_board.get_digger()->draw(m_window);
	check_game_status();
}

void Controller::move_monsters(sf::Clock clock)
{//MOVE MONSTERS
	for (int i = 0; i < m_board.get_monster_vec().size(); i++)
	{
		m_board.get_monster_vec()[i]->move(sf::Vector2f(m_window.getSize()), m_board.get_digger()->getPos(), clock);//move monster
		m_board.get_monster_vec()[i]->check_collision(m_board.get_static_vec(), m_board.get_digger());
	}
	check_game_status();
	m_board.draw_board_objects(m_window);
}

void Controller::check_game_status()
{//check game status
	//if need to restart monster and digger location
	if (m_board.get_digger()->get_is_reset())
		m_board.reset_movingobject_place(m_window);
	//if digger gie
	if (m_board.get_digger()->is_die()) {
		m_end_level = true;
	}
	// if time over or stones
	if (m_board.get_digger()->get_stone() == 0 || m_board.get_digger()->get_time() == 0) {//if digger died by monster
		m_board.get_digger()->decrease_life();
		if (!m_board.get_digger()->is_die())
			restart_level();
		else
			m_end_level = true;
	}
	//if finish level
	else if (m_board.get_digger()->is_finish_level())
		new_level();
	m_board.check_time();
	m_board.draw_board_objects(m_window);
}

void Controller::start_new_game()
{
	reset_levels();
	m_board.clean_objects();
	m_end_level = false;
	m_board.clear_file();
	m_board.get_digger()->set_life(3);
}

void Controller::new_level()
{//initalize new game
	if (m_board.is_file_end())
		end_levels();
	else
		upload_new_level();
}

void Controller::end_levels()
{//mard and game
		reset_levels();
		m_end_level = true;
}

void Controller::upload_new_level()
{////initalize new level
	m_board.update_digger_life();
	add_level();
	m_board.clean_objects();
	m_board.read(sf::Vector2f(m_window.getSize()));
	m_board.draw_board_objects(m_window);
	m_board.get_digger()->add_score(END_LEVEL);
}

void Controller::add_level()
{
	m_level++;
}

void Controller::reset_levels()
{
	m_level = 1;
}


void Controller::restart_level()
{//initalize restart level
	m_board.update_digger_life();
	m_board.restart_file_level();
	m_board.clean_objects();
	m_board.read(sf::Vector2f(m_window.getSize()));
	m_board.draw_board_objects(m_window);
}

Controller::~Controller()
{
}