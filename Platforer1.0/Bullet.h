#pragma once
#include "Projectile.h"
#include "Constants.h"

class Bullet :
	public Projectile
{
public:
	Bullet(sf::Vector2f size, sf::Vector2f position, float power, int facingDirection);
	~Bullet();

	bool destroyBasedOnDistance();
	void handleMovement(float deltaTime);


	float distacePassed;

};

