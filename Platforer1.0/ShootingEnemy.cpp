#include "ShootingEnemy.h"


ShootingEnemy::ShootingEnemy(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture, float switchTime, int maxHealth, int touchDamage, Player * player):
	Enemy(size, position, texture, switchTime, maxHealth, touchDamage)
{
	this->player = player;
}

ShootingEnemy::~ShootingEnemy()
{
}

void ShootingEnemy::aiAlghoritm()
{
}
