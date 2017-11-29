#pragma once
#include "TextureManager.h"



TextureManager::TextureManager()
{
	addTexture(TextureName::player, sf::Vector2u(3,9), "Sprites/tux_from_linux.png");
	addTexture(TextureName::bullet, sf::Vector2u(1, 1), "Sprites/bullet.png");
	addTexture(TextureName::fireBall, sf::Vector2u(1, 1), "Sprites/fireBall.png");
	addTexture(TextureName::enemy, sf::Vector2u(1, 1), "Sprites/enemy.png");
	addTexture(TextureName::ground, sf::Vector2u(1, 1), "Sprites/ground.png");
	addTexture(TextureName::spikes, sf::Vector2u(1, 1), "Sprites/spikes.png");
	addTexture(TextureName::gear, sf::Vector2u(1, 1), "Sprites/gear.png");
	addTexture(TextureName::background, sf::Vector2u(1, 1), "Sprites/background.png");
	addTexture(TextureName::flag, sf::Vector2u(1, 1), "Sprites/flag3.png");
	addTexture(TextureName::flagUnChecked, sf::Vector2u(1, 1), "Sprites/flagUnChecked.png");
	addTexture(TextureName::bullet2, sf::Vector2u(1, 1), "Sprites/ball.png");
	addTexture(TextureName::explosion1, sf::Vector2u(9, 9), "Sprites/explosion1.png");
	addTexture(TextureName::coin, sf::Vector2u(1, 1), "Sprites/Coin1.png");
	addTexture(TextureName::smallHpPotion, sf::Vector2u(1, 1), "Sprites/smallHpPotion.png");
	addTexture(TextureName::groundSurface2, sf::Vector2u(1, 1), "Sprites/groundSurface2.png");
	addTexture(TextureName::ground2, sf::Vector2u(1, 1), "Sprites/ground2.png");
	addTexture(TextureName::castledoors, sf::Vector2u(1, 1), "Sprites/castledoors.png");
}


TextureManager::~TextureManager()
{
}

TextureStruct & TextureManager::getTexture(TextureName name)
{
	return texturesMap.at(name);
}

void TextureManager::addTexture(TextureName name, sf::Vector2u imageCount, const std::string & filePath)
{
	sf::Texture texture;
	texture.loadFromFile(filePath);

	TextureStruct textureStruct(texture, imageCount);

	texturesMap.insert(std::make_pair(name, textureStruct));
}
