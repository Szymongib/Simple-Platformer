#pragma once
#include "SFML\Graphics.hpp"
#include <map>



enum class TextureName {
	player, bullet, fireBall, enemy, ground, spikes, gear, background, flag, bullet2, flagUnChecked, explosion1, coin, smallHpPotion,
	groundSurface2, ground2,
};

struct TextureStruct {

	TextureStruct()	{}

	TextureStruct(sf::Texture texture, sf::Vector2u imageCount):
		texture(texture), imageCount(imageCount)
	{}

	sf::Texture texture;
	sf::Vector2u imageCount;
};


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	TextureStruct & getTexture(TextureName name);

	void addTexture(TextureName name, sf::Vector2u imageCount, const std::string& filePath);

	std::map<TextureName, TextureStruct> texturesMap;

};

