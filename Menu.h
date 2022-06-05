#pragma once
#include "Main.h"

class main_menu {
protected:

	int index;
	sf::Vector2u texturesize[3];
	sf::RectangleShape text[max_number_of_item_menu];
	int mode = 0;
	std::string kal[8];
	sf::Text skor[8];
public:

	main_menu(float width, float height);
	void draw(sf::RenderWindow& renderw);
	void mouse_klik(sf::RenderWindow& renderw);
	int get_mode();
	void set_mode();
	void loadscore();
	void tampil();
};