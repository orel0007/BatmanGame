#include "UploadImages.h"

UploadImages::UploadImages()
{//load textures
	update_images_arr_texture();
}

void UploadImages::update_images_arr_texture()
{
	auto tex = sf::Texture();
	tex.loadFromFile("empty_box.png");
	m_images.push_back(tex);
	tex.loadFromFile("BatmanSet.png");//change to digger
	m_images.push_back(tex);
	tex.loadFromFile("monsterset.png");//change to monster
	m_images.push_back(tex);
	tex.loadFromFile("monster2set.png");//change to monster
	m_images.push_back(tex);
	tex.loadFromFile("batman-diamond.png");//change to diamond
	m_images.push_back(tex);
	tex.loadFromFile("stone.png");
	m_images.push_back(tex);
	tex.loadFromFile("wall.jpg");
	m_images.push_back(tex);
	tex.loadFromFile("Present.png");//change to present
	m_images.push_back(tex);
	tex.loadFromFile("play_again.png");
	m_images.push_back(tex);
	tex.loadFromFile("exit.png");
	m_images.push_back(tex);
	tex.loadFromFile("batman-wallpaper.png");
	m_images.push_back(tex);
	tex.loadFromFile("menu_backgroung_batman.jpg");
	m_images.push_back(tex);
	tex.loadFromFile("Game-over-2.png");
	m_images.push_back(tex);
	tex.loadFromFile("money.png");
	m_images.push_back(tex);
	tex.loadFromFile("time.png");
	m_images.push_back(tex);
	tex.loadFromFile("dig_stone.png");
	m_images.push_back(tex);
	
	//m_sound.openFromFile("batmanmusic.ogg");

	m_font.loadFromFile("BATMAN.ttf");

}

const sf::Texture& UploadImages::get_img(int index)
{//get the right texture
	return m_images[index];
}

sf::Font* UploadImages::getFont() {
	return &m_font;
}
//sf::Music* UploadImages::get_audio()
//{
//	return &m_sound;
//}


UploadImages::~UploadImages()
{

}