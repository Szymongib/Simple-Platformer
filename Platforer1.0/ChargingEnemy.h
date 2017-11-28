#pragma once
#include "Player.h"
#include "Enemy.h"

class ChargingEnemy : public Enemy
{
public:
	ChargingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, float switchTime, int maxHealth, int touchDamage, Player* player);

	~ChargingEnemy();

	void aiAlghoritm();

protected:
	bool triggered;

private:
	Player* player;	
	sf::Vector2f startingPosition;
	int prevFrameLives;
	sf::Vector2f prevFrameVelocity;
};

