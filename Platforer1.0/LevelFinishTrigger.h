#pragma once
#include "Trigger.h"

class LevelFinishTrigger :
	public Trigger
{
private:
	bool levelFinished;
public:
	LevelFinishTrigger(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture);
	~LevelFinishTrigger();

	void actionOnEnter(Player& player);

	bool isLevelFinished();

};

