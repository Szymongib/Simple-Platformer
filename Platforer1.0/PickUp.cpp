#pragma once
#include "PickUp.h"
#include "Constants.h"

PickUp::PickUp()
{
}

PickUp::PickUp(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture, Items item) :
	Trigger(size, position, texture)
{
	isPickable = true;
	this->item = item;
}

PickUp::~PickUp()
{
}

void PickUp::actionOnEnter(Player & player)
{

	switch (item) {

	case Items::coin :
		player.pickUpCoin();
		break;
	case Items::smallHpPotion:
		player.heal(SMALL_POTION_HP);
		break;
	case Items::smallManaPotion:
		//mana potion
		break;
	}

}





/*void Coin::updateAnimation(float deltaTime)
{
Entity::updateAnimation(deltaTime);
animationRow = 1;

}
*/