#pragma once
#include "DamagingTrigger.h"
#include <iostream>



DamagingTrigger::DamagingTrigger()
{
}

DamagingTrigger::DamagingTrigger(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, int damage):
	Trigger(size,position, texture)
{
	this->damage = damage;
}


DamagingTrigger::~DamagingTrigger()
{
}

void DamagingTrigger::actionOnEnter(Player & player)
{
	player.takeDamage(damage);
}
