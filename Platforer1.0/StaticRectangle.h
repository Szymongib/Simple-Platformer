#pragma once
#include "ObjectRectangle.h"


class StaticRectangle: public ObjectRectangle
{
public:
	StaticRectangle();
	StaticRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture);

	~StaticRectangle();
};

