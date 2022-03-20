#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class UploadImages{
public:
	UploadImages();
	const sf::Texture& get_img(int index);
	sf::Font* getFont();
	//sf::Music* get_audio();
	~UploadImages();
	

private:
	void update_images_arr_texture();
	//Members
	std::vector <sf::Texture> m_images;
	sf::Font m_font;
	//sf::Music  m_sound;

};