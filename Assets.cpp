#include "Assets.h"

sf::Texture penguin_texture,
bird_texture,
tiger_texture,
cat_texture,
seal_texture,
sheep_texture,
horse_texture,
deer_texture,
spider_texture;

sf::Font font_all;

sf::Texture background_menu[max_number_of_item1_menu];
sf::Font font_menu;

sf::Texture background_setting[max_number_of_item1_setting];
sf::Font font_setting;


sf::Sprite background_sprite;
sf::Texture background_texture;

sf::Music music;
sf::Music death;
sf::Music bg;
sf::Music dmg;
sf::Music music_town;

const int windowwidth = 800, windowheight = 600;
sf::View view1(sf::Vector2f(400, 300), sf::Vector2f(windowwidth, windowheight));

std::vector<std::string>words;
std::string words_used = " ";
sf::Clock cycle, runtime;
double deltaTime;
char inputkeylog = '\0';
int pointer = 0;
std::string tempinput = "", tempcheck = "";

sf::Text target, lives, scores, wavetext, wavecount, wavetrans;
bool firstletter = false;
std::vector<sf::Text> slots;

sf::RectangleShape bossHpBar;
sf::RectangleShape bossHpBarBack;

//scores
int letters = 0, misses = 0, wordsolved = 0, score = 0, waveC = 1;

//realtime 
double enemytimelength = 17.0f; //speed
int sizereq = 3, health = 3, maxenemy = 3; //change maxenemy after round end
bool spawnenemies = true; //spawner
int fontsize = 20; //fontsize
int roundcooldown = 5.0f;
double stagecooldown = 0, tempmovecount = 0;
int bosshpMax = 10;
int bosshp = bosshpMax;


void ReinitMovingText() {
	slots.clear();
	for (int i = 0; i < maxenemy; i++)
	{
		slots.push_back(sf::Text());
	}
	int div = 1;
	for (sf::Text& each : slots) {
		each.setFont(font_all);
		each.setCharacterSize(fontsize);
		each.setString("");
		each.setOrigin(each.getOrigin().x, each.getLocalBounds().height / 2.0f);
		each.setPosition(windowwidth / 2.0f, windowheight * (div++ * 1.0f / (maxenemy + 1) * 1.0f));
		each.setFillColor(sf::Color(255, 255, 255, 255));
	}
}
bool loadDefaultAssets()
{
	std::fstream source("dictionary.dict", std::ios::in);
	if (source.fail()) {
		std::cout << "\n\ndictionary.dict is not found!\n\n";
		return false;
	}
	std::string temp;
	while (source >> temp) {

		if (temp.find("#LENGTH-") == std::string::npos && temp.find("#END") == std::string::npos) {
			words.push_back(temp);
		}
		else if (temp == "#END") {
		}
	}

	penguin_texture.loadFromFile("Texture/penguin.png");
	tiger_texture.loadFromFile("Texture/macan.png");
	cat_texture.loadFromFile("Texture/kucing.png");
	seal_texture.loadFromFile("Texture/anjinglaut.png");
	sheep_texture.loadFromFile("Texture/dombaflip.png");
	bird_texture.loadFromFile("Texture/manuk.png");
	horse_texture.loadFromFile("Texture/horse.png");
	deer_texture.loadFromFile("Texture/deer.png");
	spider_texture.loadFromFile("Texture/spider.png");
	background_texture.loadFromFile("Texture/plantzombie.jpg");
	background_setting[0].loadFromFile("Texture/zoo.png");
	background_menu[0].loadFromFile("Texture/zoo.png");
	background_menu[1].loadFromFile("Texture/menubuttons.png");
	background_menu[2].loadFromFile("Texture/menubuttons.png");
	background_menu[3].loadFromFile("Texture/menubuttons.png");
	background_setting[1].loadFromFile("Texture/homebutton.png");
	background_setting[2].loadFromFile("Texture/audiobutton.png");
	background_setting[3].loadFromFile("Texture/infobutton.png");
	background_setting[4].loadFromFile("Texture/questionbutton.png");

	font_all.loadFromFile("Font/Product-Sans-Bold.ttf");
	font_setting.loadFromFile("Font/riffic.ttf");
	font_menu.loadFromFile("Font/riffic.ttf");

	music_town.openFromFile("Audio/01Town0.wav");
	dmg.openFromFile("Audio/damage.wav");
	bg.openFromFile("Audio/gameplay.wav");
	death.openFromFile("Audio/death1.wav");


}


