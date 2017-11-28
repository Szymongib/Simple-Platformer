#pragma once
#include "MovableRectangle.h"


class MovingObject :
	public MovableRectangle
{
public:
	MovingObject();
	//MovingObject(sf::Vector2f size, sf::Vector2f position, sf::Vector2i movingPlane, float speedMultiplier, sf::Vector2f minRange, sf::Vector2f maxRange);
	MovingObject(sf::Vector2f size, TextureStruct& texture, float switchTime, float speedMultiplier, sf::Vector2f point1, sf::Vector2f point2);
	~MovingObject();

	bool dealingDamage;

	void handleMovement(float deltaTime);

protected:
	sf::Vector2f point1;
	sf::Vector2f point2;

	sf::Vector2i movingPlane;
	float speedMultiplier;
	sf::Vector2f minRange;
	sf::Vector2f maxRange;

};

