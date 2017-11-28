#include "ChargingEnemy.h"
#include <math.h>



ChargingEnemy::ChargingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture, float switchTime, int maxHealth, int touchDamage, Player* player):
	Enemy(size,position,texture, switchTime, maxHealth,touchDamage), player(player)
{
	triggered = false;
	startingPosition = position;
	prevFrameVelocity = sf::Vector2f(0, 0);
}

ChargingEnemy::~ChargingEnemy()
{
}

void ChargingEnemy::aiAlghoritm()
{
	if (prevFrameLives > player->getLives()) {
		triggered = false;
		velocity = sf::Vector2f(0,0);
	}

	if (!triggered && fabs(getPosition().x - player->getPosition().x) < CHARGING_ENEMY_DISTANCE_TRIGGER) {
		triggered = true;
	}



	if (triggered) {
		if (player->getPosition().x > getPosition().x) {
			facingDirection = 1;
		}
		else {
			facingDirection = -1;
		}

		if (fabs(velocity.x) < CHARGING_ENEMY_BASE_SPEED / 10) {
			velocity.x = prevFrameVelocity.x + facingDirection* CHARGING_ENEMY_BASE_SPEED / 20;
		}
		else {
			velocity.x = prevFrameVelocity.x + facingDirection* CHARGING_ENEMY_BASE_SPEED / 40;
		}
		
		if (fabs(velocity.x) > CHARGING_ENEMY_BASE_SPEED) {
			velocity.x = facingDirection* CHARGING_ENEMY_BASE_SPEED;
		}

		move();
	}

	prevFrameLives = player->getLives();
	prevFrameVelocity = velocity;
}
