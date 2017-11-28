#pragma once
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
#include "TextureManager.h"

static TextureManager globalManager;


class ObjectRectangle
{
public:
	ObjectRectangle();
	ObjectRectangle(sf::Vector2f size, sf::Vector2f position, TextureStruct& texture);
	~ObjectRectangle();

	void draw(sf::RenderWindow &window);

	sf::Vector2f getPosition();
	sf::Vector2f getPositionBottomRight();
	sf::Vector2f getPositionTopRight();
	sf::Vector2f getPositionBottomLeft();
	sf::Vector2f getSize();
	
	void setFillColor(sf::Color color);
	void setTexture(TextureStruct& texture);

	float getXMax();
	float getXMin();
	float getYMax();
	float getYMin();

	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

	void addTag(std::string tag);
	bool checkIfHasTag(std::string tag);
	void removeTag(std::string tag);

protected:
	sf::RectangleShape object;

private:
	std::vector<std::string> tags;
};

