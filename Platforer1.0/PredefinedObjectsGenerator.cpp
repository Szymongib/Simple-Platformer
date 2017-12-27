#include "PredefinedObjectsGenerator.h"



PredefinedObjectsGenerator::PredefinedObjectsGenerator()
{
}


PredefinedObjectsGenerator::~PredefinedObjectsGenerator()
{
}



StaticRectangle PredefinedObjectsGenerator::generateSurfaceBlock(sf::Vector2f position)
{
	StaticRectangle block(sf::Vector2f(BASE_BLOCK_SIZE, BASE_BLOCK_SIZE), position, globalManager.getTexture(TextureName::groundSurface2));
	return block;
}


StaticRectangle PredefinedObjectsGenerator::generateGroundBlock(sf::Vector2f position)
{
	StaticRectangle block(sf::Vector2f(BASE_BLOCK_SIZE, BASE_BLOCK_SIZE), position, globalManager.getTexture(TextureName::ground2));
	return block;
}

PickUp* PredefinedObjectsGenerator::generateCoin(sf::Vector2f position)
{
	// Pozycja przesunieta o (BASE_BLOCK_SIZE-size.x)/2 zeby moneta znalazla sie w srodu kwadrata 50 na 50
	sf::Vector2f size(30, 30);
	PickUp* coin = new PickUp(size, position+sf::Vector2f((BASE_BLOCK_SIZE-size.x)/2, (BASE_BLOCK_SIZE - size.y) / 2), globalManager.getTexture(TextureName::coin), Items::coin);
	return coin;
}

PickUp * PredefinedObjectsGenerator::generateSmallHealingPotion(sf::Vector2f position)
{
	// Pozycja przesunieta o (BASE_BLOCK_SIZE-size.x)/2 zeby moneta znalazla sie w srodu kwadrata 50 na 50
	sf::Vector2f size(30, 30);
	PickUp* potion = new PickUp(size, position + sf::Vector2f((BASE_BLOCK_SIZE - size.x) / 2, (BASE_BLOCK_SIZE - size.y) / 2), globalManager.getTexture(TextureName::smallHpPotion), Items::smallHpPotion);
	return potion;
}

CheckPointTrigger * PredefinedObjectsGenerator::generateCheckPoint(sf::Vector2f position)
{
	sf::Vector2f size(40, 80);
	CheckPointTrigger* checkPoint = new CheckPointTrigger(size, position+sf::Vector2f((BASE_BLOCK_SIZE-size.x)/2, (BASE_BLOCK_SIZE - size.y) / 2));
	return checkPoint;
}

Enemy * PredefinedObjectsGenerator::generateBasicEnemy(sf::Vector2f position)
{
	sf::Vector2f size(30, 30);
	Enemy* enemy = new Enemy(size, position + sf::Vector2f((BASE_BLOCK_SIZE - size.x) / 2, (BASE_BLOCK_SIZE - size.y) / 2), globalManager.getTexture(TextureName::enemy), 0, BASE_ENEMY_HEALTH, BASE_ENEMY_TOUCH_DAMAGE);
	return enemy;
}

Enemy * PredefinedObjectsGenerator::generateChargingEnemy(sf::Vector2f position, Player* player)
{
	sf::Vector2f size(30, 30);
	Enemy *chargingEnemy = new ChargingEnemy
	(size, position + sf::Vector2f((BASE_BLOCK_SIZE - size.x) / 2, (BASE_BLOCK_SIZE - size.y) / 2), globalManager.getTexture(TextureName::enemy), 0, BASE_ENEMY_HEALTH, BASE_ENEMY_TOUCH_DAMAGE, player);
	return chargingEnemy;
}

Enemy * PredefinedObjectsGenerator::generateJumpingChargingEnemy(sf::Vector2f position, Player * player)
{
	sf::Vector2f size(30, 30);
	Enemy *jumpingEnemy = new JumpingChargingEnemy
	(size, position + sf::Vector2f((BASE_BLOCK_SIZE - size.x) / 2, (BASE_BLOCK_SIZE - size.y) / 2), globalManager.getTexture(TextureName::enemy), 0, BASE_ENEMY_HEALTH, BASE_ENEMY_TOUCH_DAMAGE, player);
	return jumpingEnemy;
}

LevelFinishTrigger * PredefinedObjectsGenerator::generateLevelFinishTrigger(sf::Vector2f position)
{
	sf::Vector2f size(2*BASE_BLOCK_SIZE, 3*BASE_BLOCK_SIZE);
	LevelFinishTrigger* finishTrigger = new LevelFinishTrigger(size, position-sf::Vector2f(0,size.y-BASE_BLOCK_SIZE), globalManager.getTexture(TextureName::castledoors));
	return  finishTrigger;
}
