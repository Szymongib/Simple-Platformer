#pragma once
#include "Projectile.h"
#include "Constants.h"
#include <iostream>



Projectile::Projectile(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, float power, int facingDirection) :
	MovableRectangle(size, position, texture, switchTime)
{
	this->power = power;
	this->facingDirection = facingDirection;
}

Projectile::~Projectile()
{
}


bool Projectile::collisionWithStaticObject(StaticRectangle & obs)
{
	float xMax = this->getXMax() + this->getDirection().x;
	float xMin = this->getXMin() + this->getDirection().x;
	float yMax = this->getYMax() + this->getDirection().y;
	float yMin = this->getYMin() + this->getDirection().y;

	if ((xMin >= obs.getXMax() || xMax <= obs.getXMin()) || (yMin >= obs.getYMax() || yMax <= obs.getYMin())) {
		return false;
	}
	else {
		return true;
	}
}

bool Projectile::checkCollisionEnemy(Enemy & enemy)
{
	float xMax = this->getXMax() + this->direction.x;
	float xMin = this->getXMin() + this->direction.x;
	float yMax = this->getYMax() + this->direction.y;
	float yMin = this->getYMin() + this->direction.y;

	if ((xMin >= enemy.getXMax() || xMax <= enemy.getXMin()) || (yMin >= enemy.getYMax() || yMax <= enemy.getYMin())) {
		return false;
	}
	else {
		enemy.takeDamage(this->power);
		return true;
	}
}

Explosion* Projectile::explode()
{
	return nullptr;
}
