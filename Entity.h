#pragma once
#include "Assets.h"

std::string getRandomText(int size);

class TextEnemy {
private:
	std::string text;
	double starttime, timelength;
	sf::Vector2f pos;
public:
	TextEnemy(sf::Vector2f pos, int stringlength, double timelength, sf::Clock& clock, std::vector<TextEnemy> enemies);
	std::string& getText();
	double getTimeLeft(sf::Clock& clock);
	double getTimeLength();
	sf::Vector2f& getPos();
	bool Update(sf::Clock& clock);
};

class Animation {
protected:
	sf::Vector2u img_count;
	sf::Vector2u current_img;
	float totaltime;
	float switch_time;
	sf::IntRect uvrect;
public:
	Animation(sf::Texture* texture, sf::Vector2u imgcount, float switchtime);
	void updateAnimation(int row, float deltatime, bool face_right);
};

class Entity : public Animation
{
public:
	Entity(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgcount, float switchtime);
	sf::RectangleShape& getRectangleShape();
	void setPos(sf::Vector2f pos);
	virtual void Update(float deltaTime);
protected:
	sf::RectangleShape player;
	std::string entity_type;
};

class Penguin : public Entity
{
public:
	Penguin();
};

class Tiger : public Entity
{
public:
	Tiger();
};

class Horse : public Entity
{
public:
	Horse();
	void Update(float deltaTime);
};

class Spider : public Entity
{
public:
	Spider();
	void Update(float deltaTime);
};

class Deer : public Entity
{
public:
	Deer();
	void Update(float deltaTime);
};

class Cat : public Entity
{
public:
	Cat();
};

class Seal : public Entity
{
public:
	Seal();
};

class Sheep : public Entity
{
public:
	Sheep();
};

class Bird : public Entity
{
public:
	Bird();
};

extern std::vector<TextEnemy> enemytext;
extern std::vector<Entity*> entitytext;

void loadDefaultGameArg();