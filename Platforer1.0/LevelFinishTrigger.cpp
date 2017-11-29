#include "LevelFinishTrigger.h"



LevelFinishTrigger::LevelFinishTrigger(sf::Vector2f size, sf::Vector2f position, TextureStruct & texture):
	Trigger(size, position, texture)
{
	levelFinished = false;
}

LevelFinishTrigger::~LevelFinishTrigger()
{
}

void LevelFinishTrigger::actionOnEnter(Player & player)
{
	levelFinished = true;
}

bool LevelFinishTrigger::isLevelFinished()
{
	return levelFinished;
}



