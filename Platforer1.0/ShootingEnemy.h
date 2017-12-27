#pragma once
#include "Enemy.h"
#include "Player.h"

class ShootingEnemy :
	public Enemy
{
public:
	ShootingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture, float switchTime, int maxHealth, int touchDamage, Player* player);
	~ShootingEnemy();

	void aiAlghoritm();

private:
	Player * player;

};

