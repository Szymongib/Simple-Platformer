#pragma once
#include "ExplosiveFireBall.h"
#include "Constants.h"
#include <iostream>



ExplosiveFireBall::ExplosiveFireBall(sf::Vector2f size, sf::Vector2f position, float power, float range, int facingDirection) :
	Projectile(size, position, globalManager.getTexture(TextureName::fireBall), 0, power, facingDirection)
{
	isExplosive = true;
	this->radius = radius;
	this->range = range;
	velocity.y = -sqrtf(2 * GRAVITY*EXPLOSIVE_FIRE_BALL_MAX_HEIGHT);
	velocity.x = EXPLOSIVE_FIRE_BALL_VELOCITY_X *range*facingDirection;
	affectedByGravity = true;
}


ExplosiveFireBall::~ExplosiveFireBall()
{
}

bool ExplosiveFireBall::collisionWithStaticObject(StaticRectangle & obs)
{
	if (Projectile::collisionWithStaticObject(obs)) {
		if (this->direction.x == 0) {
			//Przeszkoda z do³u
			if (this->direction.y >0) {
				float overlap = getPositionBottomRight().y - obs.getYMin();
				this->direction.y -= overlap;
				this->velocity.y = 0;
			}
			//przeszkoda z gory
			else {
				float overlap = getPosition().y - obs.getYMax();
				this->direction.y -= overlap;
				this->velocity.y = 0;
			}
		}
		//Porusza siê tylko left/right
		else if (this->direction.y == 0) {
			//Przeszkoda z prawej
			if (this->direction.x >0) {
				float overlap = getPositionBottomRight().x - obs.getXMin();
				this->direction.x -= overlap;
			}
			//przeszkoda z lewej
			else {
				float overlap = getPosition().x - obs.getXMax();
				this->direction.x -= overlap;
			}

		}
		//Porusza siê w dwóch kierunkach
		else {
			float overlapY;
			float overlapX;

			if (this->direction.y > 0) {
				overlapY = getPositionBottomRight().y - obs.getYMin();
			}
			else if (this->direction.y < 0) {
				overlapY = getPosition().y - obs.getYMax();
			}

			if (this->direction.x > 0) {
				overlapX = getPositionBottomRight().x - obs.getXMin();
			}
			else if (this->direction.x < 0) {
				overlapX = getPosition().x - obs.getXMax();
			}

			if (fabs(overlapY) <= fabs(overlapX)) {
				//dominuje przeszkoda z do³u
				this->direction.y -= overlapY;
				this->velocity.y = 0;
			}
			else {
				this->direction.x -= overlapX;
				this->velocity.x = 0;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool ExplosiveFireBall::checkCollisionEnemy(Enemy & enemy)
{
	if (Projectile::checkCollisionEnemy(enemy)) {
		if (this->direction.x == 0) {
			//Przeszkoda z do³u
			if (this->direction.y >0) {
				float overlap = getPositionBottomRight().y - enemy.getYMin();
				this->direction.y -= overlap;
				this->velocity.y = 0;
			}
			//przeszkoda z gory
			else {
				float overlap = getPosition().y - enemy.getYMax();
				this->direction.y -= overlap;
				this->velocity.y = 0;
			}
		}
		//Porusza siê tylko left/right
		else if (this->direction.y == 0) {
			//Przeszkoda z prawej
			if (this->direction.x >0) {
				float overlap = getPositionBottomRight().x - enemy.getXMin();
				this->direction.x -= overlap;
			}
			//przeszkoda z lewej
			else {
				float overlap = getPosition().x - enemy.getXMax();
				this->direction.x -= overlap;
			}

		}
		//Porusza siê w dwóch kierunkach
		else {
			float overlapY;
			float overlapX;

			if (this->direction.y > 0) {
				overlapY = getPositionBottomRight().y - enemy.getYMin();
			}
			else if (this->direction.y < 0) {
				overlapY = getPosition().y - enemy.getYMax();
			}

			if (this->direction.x > 0) {
				overlapX = getPositionBottomRight().x - enemy.getXMin();
			}
			else if (this->direction.x < 0) {
				overlapX = getPosition().x - enemy.getXMax();
			}

			if (fabs(overlapY) <= fabs(overlapX)) {
				//dominuje przeszkoda z do³u
				this->direction.y -= overlapY;
				this->velocity.y = 0;
			}
			else {
				this->direction.x -= overlapX;
				this->velocity.x = 0;
			}
		}
		return true;
	}
	else {
		return false;
	}
}



void ExplosiveFireBall::move()
{
	MovableRectangle::move(sf::Vector2f(getDirection().x, getDirection().y / 2));
}

Explosion* ExplosiveFireBall::explode()
{
	return new Explosion(EXPLOSION_SIZE, sf::Vector2f(getPosition().x + getSize().x/2, getPosition().y + getSize().y / 2), globalManager.getTexture(TextureName::explosion1), 0.03f);
}



