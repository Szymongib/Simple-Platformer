#pragma once
#include "Entity.h"
#include <iostream>



Entity::Entity()
{
}

Entity::Entity(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth) :
	MovableRectangle(size, position, texture, switchTime)
{
	affectedByGravity = true;
	this->maxHealth = maxHealth;
	health = maxHealth;
}


Entity::~Entity()
{
}


int Entity::getHealth()
{
	return health;
}
void Entity::setHealth(int health)
{
	this->health = health;
}



int Entity::getMana()
{
	return mana;
}

void Entity::setMana(int mana)
{
	this->mana = mana;
}

void Entity::takeDamage(int dmg)
{
	//std::cout << "Entity on position: x = " << getPosition().x << " y = " << getPosition().y << "  took damage:  " << dmg << std::endl;
	health -= dmg;
}

void Entity::heal(int hp)
{
	health += hp;
	if (health > maxHealth) {
		health = maxHealth;
	}
}

bool Entity::checkDeath()
{
	if (health <= 0) {
		return true;
	}

	return false;
}

void Entity::onCollisionWithStatic(StaticRectangle object)
{
}

bool Entity::collisionWithStaticObject(StaticRectangle &obstacle) {
	float xMax = this->getXMax() + this->getDirection().x;
	float xMin = this->getXMin() + this->getDirection().x;
	float yMax = this->getYMax() + this->getDirection().y;
	float yMin = this->getYMin() + this->getDirection().y;

	if ((xMin >= obstacle.getXMax() || xMax <= obstacle.getXMin()) || (yMin >= obstacle.getYMax() || yMax <= obstacle.getYMin())) {
		return false;
	}
	else {
		//Porusza siê tylko up/down
		if (this->direction.x == 0) {
			//Przeszkoda z do³u
			if (this->direction.y > 0) {
				float overlap = yMax - obstacle.getYMin();
				this->direction.y -= overlap;
				this->inTheAir = false;
				this->canSecJump = true;
				this->velocity.y = 0;
			}
			//przeszkoda z gory
			else {
				float overlap = yMin - obstacle.getYMax();
				this->direction.y -= overlap;
				this->velocity.y = 0;
			}
		}
		//Porusza siê tylko left/right
		else if (this->direction.y == 0) {
			//Przeszkoda z prawej
			if (this->direction.x > 0) {
				float overlap = xMax - obstacle.getXMin();
				this->velocity.x = 0;
				this->direction.x -= overlap;
			}
			//przeszkoda z lewej
			else {
				float overlap = xMin - obstacle.getXMax();
				this->direction.x -= overlap;
				this->velocity.x = 0;
			}
		}
		//Porusza siê w dwóch kierunkach
		else {
			float overlapY;
			float overlapX;

			if (this->direction.y > 0) {
				overlapY = yMax - obstacle.getYMin();
			}
			else if (this->direction.y < 0) {
				overlapY = yMin - obstacle.getYMax();
			}

			if (this->direction.x > 0) {
				overlapX = xMax - obstacle.getXMin();
			}
			else if (this->direction.x < 0) {
				overlapX = xMin - obstacle.getXMax();
			}

			if (fabs(overlapY) <= fabs(overlapX)) {
				if (overlapY > 0) {
					this->inTheAir = false;
					this->canSecJump = true;
				}
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
}

void Entity::updateAnimation(float deltaTime)
{
	MovableRectangle::updateAnimation(deltaTime);

	if (isShooting == true) {
		if (inTheAir == true) {
			animationRow = 6;
		}
		else {
			animationRow = 4;
		}
	}

}
