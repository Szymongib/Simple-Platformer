#pragma once
#include "Bullet.h"
#include <iostream>


Bullet::Bullet(sf::Vector2f size, sf::Vector2f position, float power, int facingDirection) :
	Projectile(size, position, globalManager.getTexture(TextureName::bullet2), 0, power, facingDirection)
{
	affectedByGravity = false;
	this->power = power;
	distacePassed = 0;
	damageDecrease = 0;
	velocity = sf::Vector2f(BULLET_VELOCITY_X * facingDirection, 0);
}

Bullet::~Bullet()
{
}

bool Bullet::destroyBasedOnDistance()
{
	distacePassed += direction.x;

	if (distacePassed >= BULLET_MAX_RANGE) {
		return true;
	}

	if (distacePassed >= 300 && damageDecrease<1) {
		this->setSize(sf::Vector2f(10, 8));
		power -= BULLET_DAMGE_LOSS;
		damageDecrease++;
	}
	else if (distacePassed >= 600 && damageDecrease<2) {
		this->setSize(sf::Vector2f(8, 6));
		power -= BULLET_DAMGE_LOSS;
		damageDecrease++;
	}
	else if (distacePassed >= 900 && damageDecrease<3) {
		this->setSize(sf::Vector2f(6, 4));
		power -= BULLET_DAMGE_LOSS;
		damageDecrease++;
	}

	return false;
}

void Bullet::handleMovement(float deltaTime)
{ 
	destroy = destroyBasedOnDistance();
}


