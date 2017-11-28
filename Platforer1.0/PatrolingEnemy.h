#pragma once
#include "Enemy.h"

class PatrolingEnemy: public Enemy
{
public:
	PatrolingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth, int touchDamage, float speed, float minPatrolRange, float maxPatrolRange);
	~PatrolingEnemy();

	void aiAlghoritm();

private:
	float speed;
	float minPatrolRangeX;
	float maxPatrolRangeX;

};

