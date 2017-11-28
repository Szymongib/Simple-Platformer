#pragma once
#include "ObjectRectangle.h"
#include "Player.h"

class Player;

class Trigger :
	public ObjectRectangle
{
public:
	Trigger();
	Trigger(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture);
	~Trigger();

	virtual void actionOnEnter(Player& player);

	bool isActivated;
	bool isPickable;

};

