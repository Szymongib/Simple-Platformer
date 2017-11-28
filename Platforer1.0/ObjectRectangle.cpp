#pragma once
#include "ObjectRectangle.h"



ObjectRectangle::ObjectRectangle()
{
}

ObjectRectangle::ObjectRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture)
{
	object = sf::RectangleShape(size);
	object.setPosition(position);
	object.setTexture(&texture.texture);
}

ObjectRectangle::~ObjectRectangle()
{
}

void ObjectRectangle::draw(sf::RenderWindow & window)
{
	window.draw(object);
}

//getters

sf::Vector2f ObjectRectangle::getPosition()
{
	return object.getPosition();
}
sf::Vector2f ObjectRectangle::getPositionBottomRight()
{
	return object.getPosition() + object.getSize();
}
sf::Vector2f ObjectRectangle::getPositionTopRight()
{
	return sf::Vector2f(object.getPosition().x + object.getSize().x, object.getPosition().y);
}
sf::Vector2f ObjectRectangle::getPositionBottomLeft()
{
	return sf::Vector2f(object.getPosition().x, object.getPosition().y + object.getSize().y);
}
sf::Vector2f ObjectRectangle::getSize()
{
	return object.getSize();
}

void ObjectRectangle::setFillColor(sf::Color color)
{
	object.setFillColor(color);
}

void ObjectRectangle::setTexture(TextureStruct& texture)
{
	object.setTexture(&texture.texture);
}

float ObjectRectangle::getXMax()
{
	return this->getPositionBottomRight().x;
}
float ObjectRectangle::getXMin()
{
	return this->getPosition().x;
}
float ObjectRectangle::getYMax()
{
	return this->getPositionBottomRight().y;
}
float ObjectRectangle::getYMin()
{
	return this->getPosition().y;
}


//setters

void ObjectRectangle::setPosition(sf::Vector2f position)
{
	object.setPosition(position);
}
void ObjectRectangle::setSize(sf::Vector2f size)
{
	object.setSize(size);
}

void ObjectRectangle::addTag(std::string tag)
{
	if (checkIfHasTag(tag)) {
		return;
	}
	tags.push_back(tag);
}

bool ObjectRectangle::checkIfHasTag(std::string tag)
{
	for (int i = 0; i < tags.size(); i++) {
		if (tag == tags[i]) {
			return true;
		}
	}
	return false;
}

void ObjectRectangle::removeTag(std::string tag)
{
	for (int i = 0; i < tags.size(); i++) {
		if (tag == tags[i]) {
			tags.erase(tags.begin() + i);
		}
	}
}


