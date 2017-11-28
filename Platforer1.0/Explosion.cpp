#pragma once
#include "Explosion.h"
#include "Constants.h"
#include <iostream>


Explosion::Explosion(float radius, sf::Vector2f position, TextureStruct& texture, float switchTime):
	animation(texture, switchTime)
{
	explosion = sf::CircleShape(radius);
	setCenter(position);
	centerPosition = position;
	enabeled = true;
	duration = texture.imageCount.x*texture.imageCount.y*switchTime;
	this->texture = texture;
	this->switchTime = switchTime;
	explosion.setTexture(&texture.texture);
	explosion.setTextureRect(animation.uvRect);
}

Explosion::~Explosion()
{
}

sf::Vector2f Explosion::getPosition()
{
	return explosion.getPosition();
}

float Explosion::getRadius()
{
	return explosion.getRadius();
}

sf::Vector2f Explosion::getCenter()
{
	return explosion.getPosition() + sf::Vector2f(getRadius(), getRadius());
}

void Explosion::setCenter(sf::Vector2f position)
{
	explosion.setPosition(position - sf::Vector2f(getRadius(), getRadius()));
}

float Explosion::checkDistanceToCenter(sf::Vector2f position)
{
	return fabs(sqrtf((getCenter().x - position.x)*(getCenter().x - position.x) + (getCenter().y - position.y)*(getCenter().y - position.y)));
}

void Explosion::drawExplosion(sf::RenderWindow & window)
{
	window.draw(explosion);
}

void Explosion::update(float deltaTime)
{
	
}

bool Explosion::checkCollisionsWithEnemie(Enemy & enemy)
{
	float xMax = getCenter().x + getRadius();
	float xMin = getCenter().x - getRadius();
	float yMax = getCenter().y + getRadius();
	float yMin = getCenter().y - getRadius();

	if ((xMin >= enemy.getXMax() || xMax <= enemy.getXMin()) || (yMin >= enemy.getYMax() || yMax <= enemy.getYMin())) {
		return false;
	}
	else {
		if ((getCenter().x >= enemy.getXMax() || getCenter().x <= enemy.getXMin()) || (getCenter().y >= enemy.getYMax() || getCenter().y <= enemy.getYMin())) {
			if (checkDistanceToCenter(enemy.getPosition()) <= getRadius() || checkDistanceToCenter(enemy.getPositionTopRight()) <= getRadius() || 
				checkDistanceToCenter(enemy.getPositionBottomLeft()) <= getRadius() || checkDistanceToCenter(enemy.getPositionBottomRight()) <= getRadius()) {

				enemy.takeDamage(50);
				//std::cout << "DELT DMG   " << enemy.getPosition().x<< std::endl;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			enemy.takeDamage(50);
			//std::cout << "DELT DMG   " << enemy.getPosition().x << std::endl;

			return true;
		}
	}
}

void Explosion::updateAnimation(float deltaTime)
{
	duration -= deltaTime;
}

void Explosion::drawAnimation(float deltaTime)
{
	animation.updateExplosion(deltaTime);
	explosion.setTextureRect(animation.uvRect);
}

