#pragma once
#include "Constants.h"
#include "MainMenu.h"
#include "MapCreator.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticRectangle.h"
#include "Bullet.h"
#include "PatrolingEnemy.h"
#include "ChargingEnemy.h"
#include "JumpingChargingEnemy.h"
#include "MovingObject.h"
#include "DamagingTrigger.h"
#include "CheckPointTrigger.h"
#include "PickUp.h"


using namespace std;


class Game
{
private:
	MapCreator mapCreator;
	Player *player;

	vector<StaticRectangle> obstacles;
	vector<Enemy*> enemies;
	vector<Projectile*> projectiles;
	vector<Explosion*> explosions;
	vector<MovingObject> movingObjects;
	vector<Trigger*> triggers;

	MainMenu mainMenu;

	int mapWidth;
	sf::Vector2i screenSize;
	sf::RenderWindow* window;
	vector<sf::Sprite> backgroundSprites;
	sf::Vector2f backgroundSize;
	sf::Font arialFont;
	sf::View view;
	sf::Vector2f cameraPosition;

	sf::Text coinCounter;

	sf::Clock clock;
	float deltaTime;

public:

	Game();
	~Game();

	void initialize();
	void initializeWindow();

	void initializeMap();
	void initializePlayer();
	void initializeEnemies();

	void runMainGameLoop();
	void changeSpeed();
	void handleCollisions();
	void checkDeathsAndMove();
	void moveCamera();
	void updateInterface();
	void drawAll();
	void resetPlayerVelocity();
};

