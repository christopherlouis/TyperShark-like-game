#pragma once
#include "Main.h"

class setting
{
protected:

	int index;
	sf::Vector2u texturesize[4];
	sf::RectangleShape logo[max_number_of_item_setting];

	sf::Text menu[4];
	int mode2 = 1;
	int mode = 0;

public:
	setting(float width, float height);
	void draw(sf::RenderWindow& renderw);
	void mouse_klik(sf::RenderWindow& renderw);
	int get_mode2();
	void set_mode();

};

