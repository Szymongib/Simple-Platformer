#pragma once
#include "Projectile.h"
#include "Constants.h"
#include "Explosion.h"


class ExplosiveFireBall : public Projectile
{
public:
	ExplosiveFireBall(sf::Vector2f size, sf::Vector2f position, float power, float range, int facingDirection);
	~ExplosiveFireBall();

	bool collisionWithStaticObject(StaticRectangle &obs);
	bool checkCollisionEnemy(Enemy& enemy);

	void move();

	Explosion* explode();

private:
	float radius;
	float range;
};

