#pragma once
#include "ChargingEnemy.h"

class JumpingChargingEnemy :
	public ChargingEnemy
{
public:
	JumpingChargingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture, float switchTime, int maxHealth, int touchDamage, Player* player);
	~JumpingChargingEnemy();

	void aiAlghoritm();

};

