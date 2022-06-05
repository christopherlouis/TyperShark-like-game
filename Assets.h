#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <thread>

#define max_number_of_item_menu 4
#define max_number_of_item1_menu 4
#define max_number_of_item_setting 5
#define max_number_of_item1_setting 5

extern sf::Texture penguin_texture,
bird_texture,
tiger_texture,
cat_texture,
seal_texture,
sheep_texture,
horse_texture,
deer_texture,
spider_texture,
background_menu[max_number_of_item1_menu],
background_setting[max_number_of_item1_setting],
background_texture;

extern sf::Font font_all;

extern sf::Font font_menu;

extern sf::Font font_setting;

extern sf::Sprite background_sprite;

extern sf::Music music;
extern sf::Music death;
extern sf::Music bg;
extern sf::Music dmg;
extern sf::Music music_town;

extern const int windowwidth, windowheight;
extern sf::View view1;

extern std::vector<std::string>words;
extern std::string words_used;
extern sf::Clock cycle, runtime;
extern double deltaTime;
extern char inputkeylog;
extern int pointer;
extern std::string tempinput, tempcheck;

extern sf::Text target, lives, scores, wavetext, wavecount, wavetrans;
extern bool firstletter;
extern std::vector<sf::Text> slots;

extern sf::RectangleShape bossHpBar;
extern sf::RectangleShape bossHpBarBack;

//scores
extern int letters, misses, wordsolved, score, waveC;

//realtime 
extern double enemytimelength; //speed
extern int sizereq, health, maxenemy; //change maxenemy after round end
extern bool spawnenemies; //spawner
extern int fontsize; //fontsize
extern int roundcooldown;
extern double stagecooldown, tempmovecount;
extern int bosshp, bosshpMax;
extern float hpPercent;

void ReinitMovingText();
bool loadDefaultAssets();

