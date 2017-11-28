#pragma once
#include "MovableRectangle.h"
#include "Enemy.h"
#include "Explosion.h"



class Projectile : public MovableRectangle
{
public:
	Projectile(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, float power, int facingDirection);
	~Projectile();


	bool collisionWithStaticObject(StaticRectangle &obs);
	bool checkCollisionEnemy(Enemy& enemy);
	virtual Explosion* explode();

	bool destroy = false;
	bool isExplosive = false;

protected:
	float power;
	int damageDecrease;
};

