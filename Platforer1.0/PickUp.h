#pragma once
#include "Trigger.h"
#include <SFML\Graphics.hpp>
#include <iostream>


enum class Items {
	coin, smallHpPotion, smallManaPotion,
};


class PickUp :
	public Trigger
{
public:
	PickUp();
	PickUp(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, Items item);
	~PickUp();

	void actionOnEnter(Player & player);

	Items item;
};

