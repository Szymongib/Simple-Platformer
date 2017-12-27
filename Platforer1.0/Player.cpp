#pragma once
#include "Player.h"
#include "Constants.h"
#include <iostream>



Player::Player(sf::Vector2f size, sf::Vector2f position, std::vector<Projectile*> &vecProjectiles, TextureStruct& texture, float switchTime) :
	Entity(size, position, texture, switchTime, 200), vecProjectiles(vecProjectiles)
{
	lives = 5;
	isImmune = false;
	shootingFireBall = false;
	nextFireBallRange = 1;
	bulletDamage = 20;
	fallDamage = 20;
	explosionDamage = 50;
	coins = 0;
	affectedByCollisionsWithEnemies = true;

	secJumpCountDown = 0;
	bulletCountDown = 0;
	fireBallCountDown = 0;

	checkPoint = sf::Vector2f(100, 100);

	object.setTexture(&texture.texture);
	object.setTextureRect(animation.uvRect);
}

Player::~Player()
{
}

Bullet* Player::shoot()
{
	return new Bullet(sf::Vector2f(12,10), sf::Vector2f(getPosition().x + getSize().x/2, getPosition().y + getSize().y/2), bulletDamage, facingDirection);
}

ExplosiveFireBall* Player::fireBall(float power, float radius, float range)
{
	sf::Vector2f shootPosition;
	if (this->facingDirection == 1) {
		shootPosition = sf::Vector2f(this->getPositionBottomRight().x, this->getPosition().y);
	}
	else {
		shootPosition = sf::Vector2f(this->getPosition().x, this->getPosition().y);
	}

	return new ExplosiveFireBall(sf::Vector2f(20, 20), shootPosition , power, range, facingDirection);
}




void Player::jump()
{
	this->velocity.y = -sqrtf(2.0f*JUMP_HEIGHT*GRAVITY);
	inTheAir = true;
}
void Player::secondJump()
{
	this->velocity.y = -sqrtf(2.0f*JUMP_HEIGHT*GRAVITY);
	this->canSecJump = false;
	inTheAir = true;
}



bool Player::collisionWithStaticObject(StaticRectangle & obstacle)
{
	if (Entity::collisionWithStaticObject(obstacle)) {
		return true;
	}

	return false;
}

bool Player::collisionWithEnemy(Enemy & enemy)
{
	float xMax = this->getXMax() + this->getDirection().x;
	float xMin = this->getXMin() + this->getDirection().x;
	float yMax = this->getYMax() + this->getDirection().y;
	float yMin = this->getYMin() + this->getDirection().y;

	if (isImmune)
	{
		return false;
	}

	if (enemy.velocity.x == 0 && enemy.velocity.y == 0) {
		if ((xMin >= enemy.getXMax() || xMax <= enemy.getXMin()) || (yMin >= enemy.getYMax() || yMax <= enemy.getYMin())) {
			return false;
		}
		else {
			//Porusza siê tylko up/down
			if (this->direction.x == 0) {
				//Przeszkoda z do³u
				if (this->direction.y > 0) {
					float overlap = yMax - enemy.getYMin();
					this->direction.y -= overlap;
					this->inTheAir = true;
					this->canSecJump = true;
					this->velocity.y = -sqrtf(2.0f*BOUNCE_UP_ON_ENEMY*GRAVITY);
					enemy.takeDamage(this->dealFallDamage());
				}
				//przeszkoda z gory
				else {
					float overlap = yMin - enemy.getYMax();
					this->direction.y -= overlap;
					this->velocity.y = 0;
					this->takeDamage(enemy.dealDamageOnTouch());
				}
			}
			//Porusza siê tylko left/right
			else if (this->direction.y == 0) {
				//Przeszkoda z prawej
				if (this->direction.x > 0) {
					float overlap = xMax - enemy.getXMin();
					this->direction.x -= overlap;
					this->takeDamage(enemy.dealDamageOnTouch());
				}
				//przeszkoda z lewej
				else {
					float overlap = xMin - enemy.getXMax();
					this->direction.x -= overlap;
					this->takeDamage(enemy.dealDamageOnTouch());
				}

			}
			//Porusza siê w dwóch kierunkach
			else {
				float overlapY;
				float overlapX;

				if (this->direction.y > 0) {
					overlapY = yMax - enemy.getYMin();
				}
				else if (this->direction.y < 0) {
					overlapY = yMin - enemy.getYMax();
				}

				if (this->direction.x > 0) {
					overlapX = xMax - enemy.getXMin();
				}
				else if (this->direction.x < 0) {
					overlapX = xMin - enemy.getXMax();
				}

				if (fabs(overlapY) <= fabs(overlapX)) {
					//dominuje przeszkoda z do³u
					if (overlapY > 0) {
						this->inTheAir = true;
						this->canSecJump = true;
						this->velocity.y = -sqrtf(2.0f*BOUNCE_UP_ON_ENEMY*GRAVITY);
						enemy.takeDamage(this->dealFallDamage());
					}
					else {
						//domunuje przeszkoda z góry
						this->takeDamage(enemy.dealDamageOnTouch());
					}
					this->direction.y -= overlapY;
					//this->velocity.y = 0;
				}
				else {
					this->direction.x -= overlapX;
					this->takeDamage(enemy.dealDamageOnTouch());
				}
			}
			return true;
		}
	}
	else {
		if ((xMin >= (enemy.getXMax()+enemy.direction.x) || xMax <= (enemy.getXMin() + enemy.direction.x)) || (yMin >= (enemy.getYMax()+ enemy.direction.y) || yMax <= (enemy.getYMin())+ enemy.direction.x)) {
			return false;
		}
		else {
			float overlapY = INFINITY;
			float overlapX = INFINITY;

			sf::Vector2f directionSum();

			
			if (enemy.getYMax() > getYMin()) {
				overlapY = yMax - enemy.getYMin() + enemy.direction.y;
			}
			else {
				overlapY = yMin - enemy.getYMax() + enemy.direction.y;
			}

			if(enemy.getXMin() > getXMin()){
				overlapX = xMax - enemy.getXMin() + enemy.direction.x;
			}
			else {
				overlapX = xMin - enemy.getXMax() - enemy.direction.x;
			}


			if (fabs(overlapY) <= fabs(overlapX)) {
				//dominuje przeszkoda z do³u
				if (overlapY > 0) {
					this->inTheAir = true;
					this->canSecJump = true;
					this->velocity.y = -sqrtf(2.0f*BOUNCE_UP_ON_ENEMY*GRAVITY);
					enemy.takeDamage(this->dealFallDamage());
				}
				else {
					//domunuje przeszkoda z góry
					this->takeDamage(enemy.dealDamageOnTouch());
				}
				this->direction.y -= overlapY;	

			}
			else {
				this->direction.x -= overlapX;
				this->takeDamage(enemy.dealDamageOnTouch());
			}
		}
		return true;
	}
}

bool Player::collisionWithMovingObject(MovingObject & object)
{
	float xMax = this->getXMax() + this->getDirection().x;
	float xMin = this->getXMin() + this->getDirection().x;
	float yMax = this->getYMax() + this->getDirection().y;
	float yMin = this->getYMin() + this->getDirection().y;

	if (object.dealingDamage == true) {
		if ((xMin >= (object.getXMax() + object.direction.x) || xMax <= (object.getXMin() + object.direction.x))
			|| (yMin >= (object.getYMax() + object.direction.y) || yMax <= (object.getYMin()) + object.direction.x)) {
			return false;
		}
		else {
			takeDamage(MOVING_OBJECT_BASE_DAMAGE);
			return true;
		}
	}
	else {
		return false;
	}
}

bool Player::collisionWithTrigger(Trigger & trigger)
{
	float xMax = this->getXMax() + this->getDirection().x;
	float xMin = this->getXMin() + this->getDirection().x;
	float yMax = this->getYMax() + this->getDirection().y;
	float yMin = this->getYMin() + this->getDirection().y;

	if ((xMin >= trigger.getXMax() || xMax <= trigger.getXMin()) || (yMin >= trigger.getYMax() || yMax <= trigger.getYMin())) {
		return false;
	}
	else {
		trigger.actionOnEnter(*this);
		return true;
	}
}




void Player::enableImmunity(float immunityTime)
{
	if (isImmune == false) {
		isImmune = true;
		object.setFillColor(sf::Color::Magenta);
		this->immunityTime = immunityTime;
		affectedByCollisionsWithEnemies = false;
	}
}
void Player::decreaseImmunityDuration(float deltaTime)
{
	if (isImmune == true) {
		immunityTime -= deltaTime;
		if (immunityTime <= 0) {
			isImmune = false;
			object.setFillColor(sf::Color::White);
			immunityTime = 0;
			affectedByCollisionsWithEnemies = true;
		}
	}
}
void Player::takeDamage(int dmg)
{
	if (isImmune == false) {
		health -= dmg;
		if (health <= 0) {
			//Die
		}
		enableImmunity(IMMUNITY_TIME);
	}
}

int Player::dealFallDamage()
{
	return fallDamage;
}

sf::Vector2f Player::getCheckPoint()
{
	return checkPoint;
}

void Player::setCheckPoint(sf::Vector2f newCheckPoint)
{
	this->checkPoint = newCheckPoint;
}

void Player::pickUpCoin()
{
	coins++;
}


void Player::handleMovement(float deltaTime)
{
	InputManager(deltaTime);
}

void Player::InputManager(float deltaTime) {

	bulletCountDown -= deltaTime;
	fireBallCountDown -= deltaTime;
	secJumpCountDown -= deltaTime;

	if (bulletCountDown <= 0) {
		isShooting = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (facingDirection == 1) {
			velocity.x = SPEED_STRAIGHT;
		}
		else {
			facingDirection = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (facingDirection == -1) {
			velocity.x = -SPEED_STRAIGHT;
		}
		else {
			facingDirection = -1;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (inTheAir == false) {
			jump();
			secJumpCountDown = SECOND_JUMP_DELAY;
		}
		else if (inTheAir == true && canSecJump == true && secJumpCountDown <= 0) {
			secondJump();
			canSecJump = false;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletCountDown <= 0) {
		vecProjectiles.push_back(shoot());
		bulletCountDown = BULLET_DELAY;
		isShooting = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && shootingFireBall == false && fireBallCountDown <= 0) {
		shootingFireBall = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && shootingFireBall == true) {
		if (nextFireBallRange < EXPLOSIVE_FIRE_BALL_MAX_RANGE) {
			nextFireBallRange += 1 * deltaTime;
		}
	}
	else if (shootingFireBall == true) {
		vecProjectiles.push_back(fireBall(50, 1, nextFireBallRange));
		shootingFireBall = false;
		nextFireBallRange = 1;
		fireBallCountDown = EXPLOSIVE_FIRE_BALL_DELAY;
	}

}

void Player::updateAnimation(float deltaTime)
{
	Entity::updateAnimation(deltaTime);

	if (shootingFireBall == true) {
		animationRow = 3;
	}
}



void Player::respawn()
{
	this->setPosition(checkPoint);
	health = maxHealth;
	lives--;
	velocity = sf::Vector2f(0, 0);
	bulletCountDown = 0;
	fireBallCountDown = 0;
	secJumpCountDown = 0;
}

int Player::getCoins()
{
	return coins;
}

int Player::getLives()
{
	return lives;
}
