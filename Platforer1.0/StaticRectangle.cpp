#pragma once
#include "StaticRectangle.h"



StaticRectangle::StaticRectangle()
{

}

StaticRectangle::StaticRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture) :
	ObjectRectangle(size, position, texture)
{
	
}

StaticRectangle::~StaticRectangle()
{
}
