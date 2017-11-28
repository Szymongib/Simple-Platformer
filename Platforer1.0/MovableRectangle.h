#pragma once
#include "ObjectRectangle.h"
#include "Animation.h"


class MovableRectangle: public ObjectRectangle
{
public:
	MovableRectangle();
	MovableRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime);
	~MovableRectangle();

	sf::Vector2f getDirection();
	void setDirection(sf::Vector2f);

	void resetDirectionX();
	void resetDirectionY();

	virtual void updateVelocity(float deltaTime);
	void applyGravity(float deltaTime);
	virtual void handleMovement(float deltaTime);
	

	virtual void updateAnimation(float deltaTime);
	void drawAnimation(float deltaTime);

	void move();
	void move(sf::Vector2f dir);


	sf::Vector2f direction;
	sf::Vector2f velocity;

protected:
	unsigned int animationRow;
	Animation animation;

	bool inTheAir;
	int facingDirection;
	bool affectedByGravity;
};

