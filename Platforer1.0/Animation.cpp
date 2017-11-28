#pragma once
#include "Animation.h"


Animation::Animation()
{
}

Animation::Animation(TextureStruct& texture, float switchTime)
{
	this->imageCount = texture.imageCount;
	this->switchTime = switchTime;

	totalTime = 0;
	currentImage.x = 0;
	currentImage.y = 0;


	uvRect.width = texture.texture.getSize().x / float(imageCount.x);
	uvRect.height = texture.texture.getSize().y / float(imageCount.y);

	increase = 1;
}


Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
	if (previousRow != row) {
		currentImage.x = 0;
		increase = 1;
	}

	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;

		if (increase == 1) {
			currentImage.x++;
		}
		else if(increase == -1) {
			currentImage.x--;
		}

		if (currentImage.x >= imageCount.x ){
			increase = -1;
			currentImage.x-=2;
		}
		else if (currentImage.x == 0) {
			increase = 1;
		}

		previousRow = currentImage.y;
	}

	
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight==true)
	{
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}

void Animation::updateExplosion(float deltaTime)
{
		totalTime += deltaTime;

		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage.x++;
			

			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
				currentImage.y++;
			}
		}


		uvRect.top = currentImage.y * uvRect.height;
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
}
