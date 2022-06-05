#include "Setting.h"

std::string difficulty;

setting::setting(float width, float height) {
	logo[0].setSize(sf::Vector2f(width, height));

	logo[0].setTexture(&background_setting[0]);


	//home
	menu[0].setFont(font_setting);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("BACK");
	menu[0].setPosition(10, 170);

	logo[1].setSize(sf::Vector2f(50, 50));
	logo[1].setPosition(10.0f, 210.0f);

	logo[1].setTexture(&background_setting[1]);

	texturesize[0] = background_setting[1].getSize();
	logo[1].setTextureRect(sf::IntRect(texturesize[0].x * 0, texturesize[0].y * 0, texturesize[0].x, texturesize[0].y));

	//sound
	menu[1].setFont(font_setting);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("SOUND");
	menu[1].setPosition(10, 270);

	logo[2].setSize(sf::Vector2f(50, 50));
	logo[2].setPosition(10.0f, 310.0f);

	logo[2].setTexture(&background_setting[2]);

	texturesize[1] = background_setting[2].getSize();
	logo[2].setTextureRect(sf::IntRect(texturesize[1].x * 0, texturesize[1].y * 0, texturesize[1].x, texturesize[1].y));

	//!
	menu[2].setFont(font_setting);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("REPORT");
	menu[2].setPosition(380, 170);

	logo[3].setSize(sf::Vector2f(50, 50));
	logo[3].setPosition(442.0f, 210.0f);

	logo[3].setTexture(&background_setting[3]);

	texturesize[2] = background_setting[3].getSize();
	logo[3].setTextureRect(sf::IntRect(texturesize[2].x * 0, texturesize[2].y * 0, texturesize[2].x, texturesize[2].y));

	//?
	menu[3].setFont(font_setting);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("QUESTION");
	menu[3].setPosition(340, 270);

	logo[4].setSize(sf::Vector2f(50, 50));
	logo[4].setPosition(442.0f, 310.0f);

	logo[4].setTexture(&background_setting[4]);

	texturesize[3] = background_setting[4].getSize();
	logo[4].setTextureRect(sf::IntRect(texturesize[3].x * 0, texturesize[3].y * 0, texturesize[3].x, texturesize[3].y));
}

void setting::draw(sf::RenderWindow& renderw) {
	int a = 0;
	for (int i = 0; i < 5; i++) {
		renderw.draw(logo[i]);
	}
	for (int a = 0; a < 4; a++) {
		renderw.draw(menu[a]);
	}
}

void setting::mouse_klik(sf::RenderWindow& renderw) {
	int audio = 1;
	//int modee = 1;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (sf::Mouse::getPosition(renderw).x >= logo[1].getPosition().x && sf::Mouse::getPosition(renderw).x <= logo[1].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= logo[1].getPosition().y && sf::Mouse::getPosition(renderw).y <= logo[1].getPosition().y + 50) {
			//Home
			mode2 = mode;
		}
		else if (sf::Mouse::getPosition(renderw).x >= logo[2].getPosition().x && sf::Mouse::getPosition(renderw).x <= logo[2].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= logo[2].getPosition().y && sf::Mouse::getPosition(renderw).y <= logo[2].getPosition().y + 50) {
			//Audio Control
			if (audio % 2 != 0) {
			}
			else {

			}
		}
		else if (sf::Mouse::getPosition(renderw).x >= logo[3].getPosition().x && sf::Mouse::getPosition(renderw).x <= logo[3].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= logo[3].getPosition().y && sf::Mouse::getPosition(renderw).y <= logo[3].getPosition().y + 50) {
			//Report
		}
		else if (sf::Mouse::getPosition(renderw).x >= logo[4].getPosition().x && sf::Mouse::getPosition(renderw).x <= logo[4].getPosition().x + 100 && sf::Mouse::getPosition(renderw).y >= logo[4].getPosition().y && sf::Mouse::getPosition(renderw).y <= logo[4].getPosition().y + 50) {
			/*if (modee == 1) {
			difficulty = "EASY";

			}
			else if (modee == 2) {
			difficulty = "NORMAL";
			}
			else if (modee == 3) {
			difficulty = "HARD";
			}
			else{
			modee == 1;
			difficulty = "EASY";
			}*/

		}
	}

	auto mouse_pos = sf::Mouse::getPosition(renderw);
	auto translated_pos = renderw.mapPixelToCoords(mouse_pos);
	if (logo[1].getGlobalBounds().contains(translated_pos)) {
		logo[1].setFillColor(sf::Color::Cyan);
	}

	else if (logo[2].getGlobalBounds().contains(translated_pos)) {
		logo[2].setFillColor(sf::Color::Cyan);
	}

	else if (logo[3].getGlobalBounds().contains(translated_pos)) {
		logo[3].setFillColor(sf::Color::Cyan);
	}
	else if (logo[4].getGlobalBounds().contains(translated_pos)) {
		logo[4].setFillColor(sf::Color::Cyan);
	}
	else {
		logo[1].setFillColor(sf::Color::White);
		logo[2].setFillColor(sf::Color::White);
		logo[3].setFillColor(sf::Color::White);
		logo[4].setFillColor(sf::Color::White);
	}
}

int setting::get_mode2() {
	return mode2;
}

void setting::set_mode() {
	mode2 = 1;
}