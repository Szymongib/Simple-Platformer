#include "JumpingChargingEnemy.h"



JumpingChargingEnemy::JumpingChargingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture, float switchTime, int maxHealth, int touchDamage, Player* player) :
	ChargingEnemy(size, position, texture, switchTime, maxHealth, touchDamage, player)
{
	affectedByGravity = true;
}


JumpingChargingEnemy::~JumpingChargingEnemy()
{
}

void JumpingChargingEnemy::aiAlghoritm()
{
	if (triggered) {
		int r = rand() % 1000;

		if (r <= 5) {
			if (!inTheAir) {
				this->velocity.y = -sqrtf(2.0f*JUMPING_ENEMY_BASE_JUMP_HEIGHT*GRAVITY);
				inTheAir = true;
			}
		}
	}
	
	ChargingEnemy::aiAlghoritm();
}
