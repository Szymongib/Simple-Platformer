#pragma once
#include <iostream>
#include <math.h>

#include "MovableRectangle.h"
#include "Constants.h"



MovableRectangle::MovableRectangle()
{
}

MovableRectangle::MovableRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime) :
	ObjectRectangle(size, position, texture), animation(texture, switchTime)
{
	direction = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);

	inTheAir = false;
	facingDirection = 1;
}

MovableRectangle::~MovableRectangle()
{
}


sf::Vector2f MovableRectangle::getDirection()
{
	return direction;
}
void MovableRectangle::setDirection(sf::Vector2f newDirection)
{
	this->direction = newDirection;
}

void MovableRectangle::resetDirectionX()
{
	this->direction.x = 0;
}
void MovableRectangle::resetDirectionY()
{
	this->direction.y = 0;
}




void MovableRectangle::updateVelocity(float deltaTime)
{
	if (affectedByGravity) {
		applyGravity(deltaTime);
	}
	handleMovement(deltaTime);

	direction = velocity * deltaTime;
	inTheAir = true;
}

void MovableRectangle::applyGravity(float deltaTime)
{
		//  v = vp + a*t
		this->velocity.y += GRAVITY * deltaTime;
}

void MovableRectangle::handleMovement(float deltaTime)
{
}


void MovableRectangle::updateAnimation(float deltaTime)
{
	if (velocity.x == 0.0f) {
		animationRow = 0;
	}
	if (velocity.x > 0.0f) {
		animationRow = 1;
	}
	if (velocity.x < 0.0f) {
		animationRow = 1;
	}
	if (inTheAir == true) {
		animationRow = 2;
	}
	
}

void MovableRectangle::drawAnimation(float deltaTime)
{
	bool faceRight;

	if (facingDirection == 1) {
		faceRight = true;
	}
	else {
		faceRight = false;
	}

	animation.update(animationRow, deltaTime, faceRight);
	object.setTextureRect(animation.uvRect);
}

void MovableRectangle::move()
{
	object.move(this->direction);
}

void MovableRectangle::move(sf::Vector2f dir)
{
	object.move(dir);
}

