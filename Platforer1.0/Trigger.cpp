#pragma once
#include "Trigger.h"
#include <iostream>



Trigger::Trigger()
{
}

Trigger::Trigger(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture):
	ObjectRectangle(size,position, texture)
{
	isPickable = false;
}


Trigger::~Trigger()
{
}

void Trigger::actionOnEnter(Player & player)
{
}
