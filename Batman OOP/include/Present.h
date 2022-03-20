//Present Class 
//*************** 
//***************
#pragma once
#include "StaticObject.h"
#include "UploadImages.h"
class Present : public StaticObject
{
public:
	Present(sf::RectangleShape& shape, UploadImages& loader);
	~Present();
	virtual const int get_index() = 0;
};