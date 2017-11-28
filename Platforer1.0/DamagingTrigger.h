#pragma once
#include "Trigger.h"


class DamagingTrigger :
	public Trigger
{
public:
	DamagingTrigger();
	DamagingTrigger(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, int damage);
	~DamagingTrigger();

	void actionOnEnter(Player& player);

protected:
	int damage;
};

