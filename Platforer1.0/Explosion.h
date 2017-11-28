#pragma once
#include "SFML\Graphics.hpp"
#include "Enemy.h"


class Explosion
{
public:
	Explosion(float radius, sf::Vector2f position, TextureStruct& texture, float switchTime);
	~Explosion();

	sf::Vector2f getPosition();
	float getRadius();
	sf::Vector2f getCenter();
	void setCenter(sf::Vector2f position);
	float checkDistanceToCenter(sf::Vector2f position);

	void drawExplosion(sf::RenderWindow& window);

	void update(float deltaTime);

	bool checkCollisionsWithEnemie(Enemy& enemy);

	void updateAnimation(float deltaTime);
	void drawAnimation(float deltaTime);


	float duration;
	bool enabeled;

private:
	sf::Vector2f centerPosition;
	sf::CircleShape explosion;

	Animation animation;
	TextureStruct texture;
	float switchTime;

};

