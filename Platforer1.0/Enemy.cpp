#pragma once
#include "Enemy.h"



Enemy::Enemy(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth, int touchDamage) :
	Entity(size, position, texture, switchTime, 100)
{
	this->touchDamage = touchDamage;
}

Enemy::~Enemy()
{
}

void Enemy::handleMovement(float deltaTime)
{
	aiAlghoritm();
}

void Enemy::aiAlghoritm()
{
}


int Enemy::dealDamageOnTouch()
{
	return touchDamage;
}

