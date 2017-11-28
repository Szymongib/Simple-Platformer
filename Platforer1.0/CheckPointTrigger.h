#pragma once
#include "Trigger.h"

class CheckPointTrigger :
	public Trigger
{
public:
	CheckPointTrigger(sf::Vector2f size, sf::Vector2f position);
	~CheckPointTrigger();

	void actionOnEnter(Player& player);

};

