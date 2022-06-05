#include "Entity.h"

std::string getRandomText(int size) {//get random string with string length param
	std::string temp = "NOT VALID"; //temp string var
	if ((size >= 3 && size <= 7) || size == 10) {//when the request is 3-7
		do {
			temp = words[rand() % words.size()];//random string until true
		} while (temp.size() != size || words_used.find(temp) != std::string::npos);//while size not match or word is already used
		words_used += temp + " ";//add new word into used word list
	}
	return temp;//return string
}

TextEnemy::TextEnemy(sf::Vector2f pos, int stringlength, double timelength, sf::Clock& clock, std::vector<TextEnemy> enemies) {
	bool dup = true;
	while (dup) {//make sure theres no double first char
		text = getRandomText(stringlength);
		dup = false;
		for (TextEnemy each : enemies) {
			if (text[0] == each.getText()[0]) {
				dup = true;
				break;
			}
		}
	}
	starttime = clock.getElapsedTime().asSeconds();
	this->timelength = timelength;
	this->pos = pos;
}
std::string& TextEnemy::getText() {
	return text;
}
double TextEnemy::getTimeLeft(sf::Clock& clock) {
	return timelength - (clock.getElapsedTime().asSeconds() - starttime);
}
double TextEnemy::getTimeLength() {
	return timelength;
}
sf::Vector2f& TextEnemy::getPos() {
	return pos;
}
bool TextEnemy::Update(sf::Clock& clock) {
	if (getTimeLeft(clock) <= 0)
		return false;
	pos = sf::Vector2f(windowwidth * (getTimeLeft(clock) * 1.0f / timelength * 1.0f), pos.y);
	return true;
}



Animation::Animation(sf::Texture* texture, sf::Vector2u imgcount, float switchtime) {
	this->img_count = imgcount;
	this->switch_time = switchtime;
	totaltime = 0.0f;

	current_img.x = 0;

	uvrect.width = texture->getSize().x / float(img_count.x);
	uvrect.height = texture->getSize().y / float(img_count.y);

}

void Animation::updateAnimation(int row, float deltatime, bool face_right) {
	current_img.y = row;
	totaltime += deltatime;

	if (totaltime >= switch_time) {
		totaltime -= switch_time;
		current_img.x++;

		if (current_img.x >= img_count.x) {
			current_img.x = 0;
		}
	}

	uvrect.left = current_img.x * uvrect.width;
	uvrect.top = current_img.y * uvrect.height;
}



Entity::Entity(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgcount, float switchtime) : Animation(texture, imgcount, switchtime) {
	entity_type = "NOTYPE";
	player.setSize(size);
	player.setTexture(texture);
}

sf::RectangleShape& Entity::getRectangleShape() {
	return player;
}

void Entity::setPos(sf::Vector2f pos) {
	player.setPosition(pos);
}

void Entity::Update(float deltaTime) {

	Animation::updateAnimation(0, deltaTime, true);
	player.setTextureRect(uvrect);
}



Penguin::Penguin() : Entity(sf::Vector2f(75.0f, 100.0f), &penguin_texture, sf::Vector2u(4, 1), 0.04f) {
	entity_type = "PENGUIN";
}



Tiger::Tiger() : Entity(sf::Vector2f(100.0f, 75.0f), &tiger_texture, sf::Vector2u(6, 1), 0.05f) {
	entity_type = "TIGER";
}



Horse::Horse() : Entity(sf::Vector2f(100.0f, 100.0f), &horse_texture, sf::Vector2u(3, 4), 0.05f) {
	entity_type = "HORSE";
}

void Horse::Update(float deltaTime) {

	Animation::updateAnimation(1, deltaTime, true);
	player.setTextureRect(uvrect);
}


Spider::Spider() : Entity(sf::Vector2f(150.0f, 150.0f), &spider_texture, sf::Vector2u(3, 4), 0.04f) {
	entity_type = "SPIDER";
}

void Spider::Update(float deltaTime) {

	Animation::updateAnimation(1, deltaTime, true);
	player.setTextureRect(uvrect);
}

Deer::Deer() : Entity(sf::Vector2f(100.0f, 100.0f), &deer_texture, sf::Vector2u(4, 4), 0.06f) {
	entity_type = "DEER";
}

void Deer::Update(float deltaTime) {

	Animation::updateAnimation(1, deltaTime, true);
	player.setTextureRect(uvrect);
}

Cat::Cat() : Entity(sf::Vector2f(100.0f, 75.0f), &cat_texture, sf::Vector2u(6, 1), 0.06f) {
	entity_type = "CAT";
}

Seal::Seal() : Entity(sf::Vector2f(100.0f, 75.0f), &seal_texture, sf::Vector2u(3, 1), 0.07f) {
	entity_type = "SEAL";
}


Sheep::Sheep() : Entity(sf::Vector2f(100.0f, 75.0f), &sheep_texture, sf::Vector2u(6, 1), 0.04f) {
	entity_type = "SHEEP";
}

Bird::Bird() : Entity(sf::Vector2f(100.0f, 75.0f), &bird_texture, sf::Vector2u(3, 1), 0.04f) {
	entity_type = "BIRD";
}

std::vector<TextEnemy> enemytext;
std::vector<Entity*> entitytext;

void loadDefaultGameArg()
{
	words_used = " ";
	cycle.restart();
	runtime.restart();
	deltaTime = 0;
	inputkeylog = '\0';
	pointer = 0;
	tempinput = "";
	tempcheck = "";
	firstletter = false;
	letters = 0;
	misses = 0;
	wordsolved = 0;
	score = 0;
	waveC = 0;
	enemytimelength = 17.0f; //speed
	sizereq = 3;
	health = 3;
	maxenemy = 3;
	bosshpMax = 10;
	bosshp = 10;
	spawnenemies = true;
	fontsize = 20;
	roundcooldown = 5.0f;
	stagecooldown = 0;
	tempmovecount = 0;
	slots.clear();
	enemytext.clear();
	entitytext.clear();


	dmg.setVolume(20);
	bg.setVolume(20);
	bg.play();
	death.setVolume(30);
	srand(time(0));//randoming seed

	ReinitMovingText();//initialize moving texts
	target.setFont(font_all);
	target.setCharacterSize(fontsize);
	target.setString("");
	target.setOrigin(target.getOrigin().x, target.getLocalBounds().height / 2.0f);
	target.setPosition(windowwidth / 2.0f, windowheight / 2.0f);
	target.setFillColor(sf::Color(255, 0, 0, 255));
	//lives
	lives.setFont(font_all);
	lives.setCharacterSize(30);
	lives.setString(std::to_string(health));
	lives.setPosition(windowwidth - 105, windowheight - 35);
	lives.setFillColor(sf::Color::Blue);
	//livescores
	scores.setFont(font_all);
	scores.setCharacterSize(30);
	scores.setString(std::to_string(score));
	scores.setPosition(0, windowheight - 35);
	scores.setFillColor(sf::Color::Blue);
	//waveround
	wavecount.setFont(font_all);
	wavecount.setCharacterSize(30);
	wavecount.setString(std::to_string(waveC));
	wavecount.setPosition(windowwidth / 2.0f - 40, windowheight - 35);
	wavecount.setFillColor(sf::Color::Blue);
	//background
	background_sprite.setTexture(background_texture);
	background_sprite.setScale(sf::Vector2f(1.0f, 1.0f));
	background_sprite.setPosition(sf::Vector2f(0.1f, 0.1f));

	wavetrans.setFont(font_all);
	wavetrans.setCharacterSize(100);
	wavetrans.setString("Wave X");
	wavetrans.setOrigin(wavetrans.getLocalBounds().width / 2.0f, wavetrans.getLocalBounds().height / 2.0f);
	wavetrans.setPosition(windowwidth / 2.0f, (windowheight / 2.0f) - 20);
	wavetrans.setFillColor(sf::Color(0, 0, 255, 0));

	//boss hp bar
	bossHpBar.setSize(sf::Vector2f(300.f, 25.f));
	bossHpBar.setFillColor(sf::Color::Red);
	bossHpBar.setPosition(windowwidth / 2.0f - 130, 40);

	bossHpBarBack = bossHpBar;
	bossHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}