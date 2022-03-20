//MovingObject Class 
//***************
//pure class that is the father of all active objects in the board
//***************
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "StaticObject.h"
class Controller;
enum Direction { DOWN, LEFT, RIGHT, UP };

class MovingObject : public GameObject
{
public:
	MovingObject(sf::RectangleShape &shape,UploadImages &loader);
	~MovingObject();
	void restartClock();
	sf::Clock* getClock();
	bool can_move(sf::Vector2f windowsize);
	sf::Vector2f get_direction();
	void set_direction(sf::Vector2f direction);
	virtual void move(sf::Vector2f windowsize, sf::Vector2f digger_pos,sf::Clock clock) = 0;
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Digger& gameObject) = 0;
	void handleCollision(Wall& gameObject) = 0;
	void handleCollision(Stone& gameObject) = 0;
	void handleCollision(Diamond& gameObject) = 0;
	bool get_is_reset();
	void reset_location();
	void set_is_reset(bool boliani);
	sf::Vector2f get_last_place();
	void set_old_place();
	void set_last_place(sf::Vector2f location);
	void setAnimation(enum Direction way, sf::Sprite& m_image);
	void set_sprite(int image);
	sf::Sprite& get_sprite();
	void draw(sf::RenderWindow& window);

private:
	UploadImages& m_loader;
	sf::Vector2i source;
	int animationCounter = 0,
		animationFrameDuration = 200;	
	sf::Vector2f m_last_place;
	sf::Vector2f m_direction;
	bool Reset_place = false;
	sf::Vector2f m_start_location;
	sf::Clock m_clock;
	sf::Sprite m_sprite;
};

