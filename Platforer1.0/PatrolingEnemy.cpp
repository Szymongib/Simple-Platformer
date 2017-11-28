#pragma once
#include "PatrolingEnemy.h"
#include "Constants.h"
#include <iostream>

PatrolingEnemy::PatrolingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth, int touchDamage, float speed, float minPatrolRangeX, float maxPatrolRangeX) :
	Enemy(size, position, texture, switchTime, maxHealth, touchDamage)
{
	this->speed = speed;
	this->minPatrolRangeX = minPatrolRangeX;
	this->maxPatrolRangeX = maxPatrolRangeX;
	facingDirection = 1;
}

PatrolingEnemy::~PatrolingEnemy()
{
}

void PatrolingEnemy::aiAlghoritm()
{
	if (facingDirection == 1) {
		if (getPositionBottomRight().x < maxPatrolRangeX) {
			velocity.x = PATROLING_ENEMY_BASE_SPEED * speed;
		}
		else {
			facingDirection = -1;
		}
	}
	else if (facingDirection == -1) {
		if (getPosition().x > minPatrolRangeX) {
			velocity.x = -PATROLING_ENEMY_BASE_SPEED * speed;
		}
		else {
			facingDirection = 1;
		}
	}


	
}
