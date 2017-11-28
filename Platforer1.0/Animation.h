#pragma once
#include "TextureManager.h"

class Animation
{
public:
	Animation();
	Animation(TextureStruct& texture, float switchTime);
	~Animation();

	void update(int row, float deltaTime, bool faceRight);
	void updateExplosion(float deltaTime);

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

	int previousRow;

	int increase;


};