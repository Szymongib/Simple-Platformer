#pragma once
#include "Constants.h"
#include "StaticRectangle.h"
#include "MovableRectangle.h"

class Entity : public MovableRectangle
{
public:
	Entity();
	Entity(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth);
	~Entity();

	bool collisionWithStaticObject(StaticRectangle & obstacle);

	virtual void updateAnimation(float deltaTime);

	int getHealth();
	void setHealth(int health);

	int getMana();
	void setMana(int mana);
	
	void takeDamage(int dmg);
	void heal(int hp);

	bool checkDeath();

	virtual void onCollisionWithStatic(StaticRectangle object);

protected:
	bool canSecJump;
	bool isShooting;

	int maxHealth;
	int health;
	int maxMana;
	int mana;
};

