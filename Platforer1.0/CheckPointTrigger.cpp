#pragma once
#include "CheckPointTrigger.h"



CheckPointTrigger::CheckPointTrigger(sf::Vector2f size, sf::Vector2f position):
	Trigger(size, position, globalManager.getTexture(TextureName::flagUnChecked))
{
}

CheckPointTrigger::~CheckPointTrigger()
{
}

void CheckPointTrigger::actionOnEnter(Player & player)
{
	if (getPosition().x > player.getCheckPoint().x) {
		player.setCheckPoint(getPosition());
		isActivated = true;
		setTexture(globalManager.getTexture(TextureName::flag));
	}
}
