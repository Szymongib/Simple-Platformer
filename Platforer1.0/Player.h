#pragma once
#include "Entity.h"
#include "ExplosiveFireBall.h"
#include "Enemy.h"
#include "Bullet.h"
#include "MovingObject.h"
#include "Trigger.h"
#include <vector>

class Trigger;

class Player :
	public Entity
{
public:

	Player(sf::Vector2f size, sf::Vector2f position, std::vector<Projectile*> &vecProjectiles, TextureStruct& texture, float switchTime);
	~Player();

	Bullet* shoot();
	ExplosiveFireBall* fireBall(float power, float radius, float range);

	void jump();
	void secondJump();

	//Update
	void handleMovement(float deltaTime);
	void InputManager(float deltaTime);
	void updateAnimation(float deltaTime);

	bool collisionWithStaticObject(StaticRectangle & obstacle);
	bool collisionWithEnemy(Enemy& enemy);
	bool collisionWithMovingObject(MovingObject & object);
	bool collisionWithTrigger(Trigger& trigger);

	void takeDamage(int dmg);
	void enableImmunity(float immunityTime);
	void decreaseImmunityDuration(float deltaTime);

	int dealFallDamage();

	sf::Vector2f getCheckPoint();
	void setCheckPoint(sf::Vector2f newCheckPoint);

	void pickUpCoin();
	int getCoins();
	int getLives();

	void respawn();

private:
	int lives;	
	int fallDamage;
	int bulletDamage;
	int explosionDamage;
	int coins;

	bool affectedByCollisionsWithEnemies;

	sf::Vector2f checkPoint;
	std::vector<Projectile*> &vecProjectiles;
	
	bool shootingFireBall;
	float nextFireBallRange;
	bool isImmune;
	float immunityTime;
	float bulletCountDown;
	float fireBallCountDown;
	float secJumpCountDown;

};

