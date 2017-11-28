#pragma once
#include "Entity.h"


class Enemy: 
	public Entity
{
public:
	Enemy(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth, int touchDamage);
	~Enemy();

	void handleMovement(float deltaTime);
	virtual void aiAlghoritm();

	int dealDamageOnTouch();

private:
	int touchDamage;
};

