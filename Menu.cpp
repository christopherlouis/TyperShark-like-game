#include "Menu.h"

main_menu::main_menu(float width, float height) {
	text[0].setSize(sf::Vector2f(width, height));

	text[0].setTexture(&background_menu[0]);

	text[1].setSize(sf::Vector2f(100, 50));
	text[1].setPosition(352.0f, 180.0f);

	text[1].setTexture(&background_menu[1]);

	texturesize[0] = background_menu[1].getSize();
	texturesize[0].x /= 3;
	texturesize[0].y /= 4;
	text[1].setTextureRect(sf::IntRect(texturesize[0].x * 0, texturesize[0].y * 0, texturesize[0].x, texturesize[0].y));

	text[2].setSize(sf::Vector2f(100, 50));
	text[2].setPosition(352.0f, 250.0f);

	text[2].setTexture(&background_menu[2]);

	texturesize[1] = background_menu[2].getSize();
	texturesize[1].x /= 3;
	texturesize[1].y /= 4;
	text[2].setTextureRect(sf::IntRect(texturesize[1].x * 1, texturesize[1].y * 2, texturesize[1].x, texturesize[1].y));

	text[3].setSize(sf::Vector2f(100, 50));
	text[3].setPosition(352.0f, 320.0f);

	text[3].setTexture(&background_menu[3]);

	texturesize[2] = background_menu[3].getSize();
	texturesize[2].x /= 3;
	texturesize[2].y /= 4;
	text[3].setTextureRect(sf::IntRect(texturesize[2].x * 1, texturesize[2].y * 3, texturesize[2].x, texturesize[2].y));
}

void main_menu::draw(sf::RenderWindow& renderw) {
	for (int i = 0; i < max_number_of_item_menu; i++) {
		renderw.draw(text[i]);
	}
	for (int i = 0; i < 7; i++)
	{
		renderw.draw(skor[i]);
	}
}

void main_menu::mouse_klik(sf::RenderWindow& renderw) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (sf::Mouse::getPosition(renderw).x >= text[1].getPosition().x && sf::Mouse::getPosition(renderw).x <= text[1].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= text[1].getPosition().y && sf::Mouse::getPosition(renderw).y <= text[1].getPosition().y + 50) {
			//std::cout << "klik play \n";
			mode = 2;
		}
		else if (sf::Mouse::getPosition(renderw).x >= text[2].getPosition().x && sf::Mouse::getPosition(renderw).x <= text[2].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= text[2].getPosition().y && sf::Mouse::getPosition(renderw).y <= text[2].getPosition().y + 50) {
			//std::cout << "klik seting \n";
			mode = 1;
		}
		else if (sf::Mouse::getPosition(renderw).x >= text[3].getPosition().x && sf::Mouse::getPosition(renderw).x <= text[3].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= text[3].getPosition().y && sf::Mouse::getPosition(renderw).y <= text[3].getPosition().y + 50) {
			//std::cout << "klik exit \n";
			mode = 4;
		}
	}

	auto mouse_pos = sf::Mouse::getPosition(renderw);
	auto translated_pos = renderw.mapPixelToCoords(mouse_pos);
	if (text[1].getGlobalBounds().contains(translated_pos)) {
		text[1].setFillColor(sf::Color::Cyan);
	}

	else if (text[2].getGlobalBounds().contains(translated_pos)) {
		text[2].setFillColor(sf::Color::Cyan);
	}

	else if (text[3].getGlobalBounds().contains(translated_pos)) {
		text[3].setFillColor(sf::Color::Cyan);
	}
	else {
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::White);
	}
}

int main_menu::get_mode() {
	return mode;
}

void main_menu::set_mode() {
	mode = 0;
}

void main_menu::loadscore()
{
	int co = 0;
	std::fstream myfile("score.txt", std::ios::in);
	while (getline(myfile, kal[co]))
	{
		co++;
	}
}

void main_menu::tampil()
{

	skor[0].setFont(font_menu);
	skor[0].setFillColor(sf::Color::Black);
	skor[0].setString(kal[0]);
	skor[0].setPosition(10, 180);
	skor[0].setCharacterSize(13);

	skor[1].setFont(font_menu);
	skor[1].setFillColor(sf::Color::Black);
	skor[1].setString(kal[1]);
	skor[1].setPosition(10, 200);
	skor[1].setCharacterSize(13);

	skor[2].setFont(font_menu);
	skor[2].setFillColor(sf::Color::Black);
	skor[2].setString(kal[2]);
	skor[2].setPosition(10, 220);
	skor[2].setCharacterSize(13);

	skor[3].setFont(font_menu);
	skor[3].setFillColor(sf::Color::Black);
	skor[3].setString(kal[3]);
	skor[3].setPosition(10, 240);
	skor[3].setCharacterSize(13);

	skor[4].setFont(font_menu);
	skor[4].setFillColor(sf::Color::Black);
	skor[4].setString(kal[4]);
	skor[4].setPosition(10, 260);
	skor[4].setCharacterSize(13);

	skor[5].setFont(font_menu);
	skor[5].setFillColor(sf::Color::Black);
	skor[5].setString(kal[5]);
	skor[5].setPosition(10, 280);
	skor[5].setCharacterSize(13);

	skor[6].setFont(font_menu);
	skor[6].setFillColor(sf::Color::Black);
	skor[6].setString(kal[6]);
	skor[6].setPosition(10, 300);
	skor[6].setCharacterSize(13);
}