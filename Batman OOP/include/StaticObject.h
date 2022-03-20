//BoardObject Class 
//***************
//a pure virtual father class for all boared objects, holds bool 
//if the object needs to be erased
//***

#pragma once
#include "GameObject.h"



class StaticObject : public  GameObject
{
public:
	StaticObject(sf::RectangleShape &shape, UploadImages &loader);
	~StaticObject();
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Digger& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Monster& gameObject) = 0;
	virtual void handleCollision(Stone& gameObject) = 0;
	virtual void handleCollision(Diamond& gameObject) = 0;
	bool get_deleteMe();
	void set_delete_me();
private:
	bool deleteMe = false;
};