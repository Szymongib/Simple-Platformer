#pragma once
#include "MovingObject.h"
#include "Constants.h"
#include <iostream>


MovingObject::MovingObject()
{
}

MovingObject::MovingObject(sf::Vector2f size, TextureStruct& texture, float switchTime, float speedMultiplier, sf::Vector2f point1, sf::Vector2f point2):
	MovableRectangle(size, point1, texture, switchTime)
{
	this->speedMultiplier = speedMultiplier;
	this->point1 = point1;
	this->point2 = point2;
	affectedByGravity = false;
	dealingDamage = true;
	facingDirection = 1;
	setFillColor(sf::Color(255, 128, 0));

}

MovingObject::~MovingObject()
{
}

void MovingObject::handleMovement(float deltaTime)
{
	double distanceRatio;
	int ySign = 0;

	if (point1.y != point2.y) {
		distanceRatio = fabs((point2.x - point1.x) / (point2.y - point1.y));
	}
	else {
		distanceRatio = 1;
	}

	if (point1.y > point2.y) {
		ySign = -1;
	}
	else if (point1.y < point2.y) {
		ySign = 1;
	}

	if (facingDirection == 1) {

		velocity.y = ySign*MOVING_OBJECT_BASE_SPEED*speedMultiplier;
		velocity.x = MOVING_OBJECT_BASE_SPEED*speedMultiplier*distanceRatio;

		if (distanceRatio != 0) {
			if (getPosition().x >= point2.x) {
				setPosition(point2);
			}
		}
		else {
			if (getPosition().y >= point2.y) {
				setPosition(point2);
			}
		}
		if (getPosition() == point2) {
			facingDirection = -1;
			velocity.y = 0;
			velocity.x = 0;
		}
	}
	else if (facingDirection == -1) {

		velocity.y = -ySign*MOVING_OBJECT_BASE_SPEED*speedMultiplier;
		velocity.x = -MOVING_OBJECT_BASE_SPEED*speedMultiplier*distanceRatio;
		
		if (distanceRatio != 0) {
			if (getPosition().x <= point1.x) {
				setPosition(point1);
			}
		}
		else {
			if (getPosition().y <= point1.y) {
				setPosition(point1);
			}
		}
		if (getPosition() == point1) {
			facingDirection = 1;
		}
	}


}

