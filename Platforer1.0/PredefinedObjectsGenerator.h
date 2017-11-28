#pragma once
#include "Constants.h"
#include "TextureManager.h"
#include "CheckPointTrigger.h"
#include "StaticRectangle.h"
#include "PickUp.h"
#include "Enemy.h"
#include "Player.h"
#include "ChargingEnemy.h"

class StaticRectangle;

class PredefinedObjectsGenerator
{
public:
	PredefinedObjectsGenerator();
	~PredefinedObjectsGenerator();

	StaticRectangle generateSurfaceBlock(sf::Vector2f position);
	StaticRectangle generateGroundBlock(sf::Vector2f position);

	PickUp* generateCoin(sf::Vector2f position);
	PickUp* generateSmallHealingPotion(sf::Vector2f position);
	
	CheckPointTrigger* generateCheckPoint(sf::Vector2f position);

	Enemy* generateChargingEnemy(sf::Vector2f position, Player* player);

};

