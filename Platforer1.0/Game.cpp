#include "Game.h"



Game::Game():
	mainMenu(MainMenu(window))
{
}


Game::~Game()
{
}

void Game::initialize()
{
	initializeWindow();
	initializePlayer();
	initializeMap();
	initializeEnemies();
}

void Game::initializeWindow()
{
	screenSize = sf::Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
	window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), "Okno");
	arialFont.loadFromFile("Fonts/arial.ttf");
	view.reset(sf::FloatRect(0, 0, (float)screenSize.x, (float)screenSize.y));
	cameraPosition = sf::Vector2f(0, 0);

}

void Game::initializeMap()
{
	// TODO - path to constant
	mapCreator.CreateMapFromTextFile(&mapWidth,"Maps\\map1.txt", &obstacles, &enemies, &movingObjects, &triggers, player);
	
	coinCounter = sf::Text("Coins: ", arialFont, 100);

	// Initialize Background

	backgroundSize = sf::Vector2f((globalManager.getTexture(TextureName::background).texture).getSize());

	int backgroundsNeeded = mapWidth / backgroundSize.x + 1;
	for (int i = 0; i < backgroundsNeeded; i++) {
		sf::Sprite background = sf::Sprite(globalManager.getTexture(TextureName::background).texture);
		background.setPosition(sf::Vector2f(i*backgroundSize.x, 0));
		backgroundSprites.push_back(background);
	}


	MovingObject mObject1(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 2, sf::Vector2f(1250, 500), sf::Vector2f(1600, 500));
	MovingObject mObject2(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 2, sf::Vector2f(1050, 100), sf::Vector2f(1050, 600));
	MovingObject mObject3(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 1, sf::Vector2f(1400, 700), sf::Vector2f(2000, 400));

	movingObjects.push_back(mObject1);
	movingObjects.push_back(mObject2);
	movingObjects.push_back(mObject3);

	DamagingTrigger *spikes = new DamagingTrigger(sf::Vector2f(200, 40), sf::Vector2f(2070, 780), globalManager.getTexture(TextureName::spikes), 50);

	triggers.push_back(spikes);
}

void Game::initializePlayer()
{
	player = new Player(sf::Vector2f(BASE_BLOCK_SIZE-10, BASE_BLOCK_SIZE-5), sf::Vector2f(100, 100), projectiles, globalManager.getTexture(TextureName::player), 0.2f);
}

void Game::initializeEnemies()
{
	/*Enemy *enemy1 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(20, 790), globalManager.getTexture(TextureName::enemy), 0, 100, 40);
	Enemy *enemy2 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(600, 690), globalManager.getTexture(TextureName::enemy), 0, 200, 40);
	Enemy *enemy3 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(720, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy4 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1400, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy5 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1450, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy6 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1500, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *patrolingEnemy = new PatrolingEnemy(sf::Vector2f(30, 30), sf::Vector2f(1700, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40, 1, 1650, 2000);
	Enemy *chargingEnemy = new ChargingEnemy(sf::Vector2f(30, 30), sf::Vector2f(2500, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 100, player);*/
	Enemy *jumpingChargingEnemy = new JumpingChargingEnemy(sf::Vector2f(30, 30), sf::Vector2f(3000, 690), globalManager.getTexture(TextureName::enemy), 0, 30, 10, player);

	//enemies.push_back(enemy1);
	//enemies.push_back(enemy2);
	//enemies.push_back(enemy3);
	//enemies.push_back(enemy4);
	//enemies.push_back(enemy5);
	//enemies.push_back(enemy6);
	//enemies.push_back(patrolingEnemy);
	//enemies.push_back(chargingEnemy);
	enemies.push_back(jumpingChargingEnemy);

}

void Game::runMainGameLoop()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		//if(mainMenu.getGameStarted()) {

			deltaTime = clock.getElapsedTime().asSeconds();;
			if (deltaTime > 1.0f / 20.0f) {
				deltaTime = 1.0f / 20.0f;
			}
			clock.restart();
			window->setFramerateLimit(60);

			changeSpeed();
			handleCollisions();
			checkDeathsAndMove();
			moveCamera();
			updateInterface();
			drawAll();

			resetPlayerVelocity();
	/*	}
		else {
			mainMenu.display();
		}*/
	}
}

void Game::changeSpeed()
{
	player->updateVelocity(deltaTime);

	for (unsigned int i = 0; i < enemies.size(); i++) {
		enemies[i]->updateVelocity(deltaTime);
	}
}

void Game::handleCollisions()
{
	//Sprawdza czy player jest niewrazliwy i zmniejsza czas niewrazliwosci o delta time
	player->decreaseImmunityDuration(deltaTime);

	//Grasz - otoczenie
	for (unsigned int i = 0; i < obstacles.size(); i++) {
		player->collisionWithStaticObject(obstacles[i]);
	}

	//Gracz - trigger
	for (unsigned int i = 0; i < triggers.size(); i++) {
		if (player->collisionWithTrigger(*triggers[i])) {
			if (triggers[i]->isPickable) {
				delete triggers[i];
				triggers.erase(triggers.begin() + i);
				i--;
			}
		}
	}

	//Gracz - poruszaj¹cy siê obiekt
	for (unsigned int i = 0; i < movingObjects.size(); i++) {
		movingObjects[i].updateVelocity(deltaTime);
		player->collisionWithMovingObject(movingObjects[i]);
		movingObjects[i].move();
	}

	//Przeciwnik - otoczenie
	for (unsigned int i = 0; i < enemies.size(); i++) {
		for (unsigned int k = 0; k < obstacles.size(); k++) {
			enemies[i]->collisionWithStaticObject(obstacles[k]);
		}
	}

	if (fabs(player->direction.y) < 0.01) {
		player->resetDirectionY();
	}
	for (unsigned int i = 0; i < enemies.size(); i++) {
		if (fabs(enemies[i]->direction.y) < 0.01) {
			enemies[i]->resetDirectionY();
		}
	}


	//Gracz - przeciwnik
	for (unsigned int i = 0; i < enemies.size(); i++) {
		player->collisionWithEnemy(*enemies[i]);
	}


	//Kolizje pocisków
	for (unsigned int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->updateVelocity(deltaTime);
		bool destroyed = false;

		if (projectiles[i]->destroy == true) {
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
			i--;
			destroyed = true;
		}
		else {
			for (unsigned int k = 0; k < obstacles.size(); k++) {
				if (projectiles[i]->collisionWithStaticObject(obstacles[k]) == true) {

					if (projectiles[i]->isExplosive) {
						explosions.push_back(projectiles[i]->explode());
					}
					delete projectiles[i];
					projectiles.erase(projectiles.begin() + i);
					i--;
					destroyed = true;
					break;
				}
			}
			if (destroyed == false) {
				for (unsigned int k = 0; k < enemies.size(); k++) {
					if (projectiles[i]->checkCollisionEnemy(*enemies[k]) == true) {

						if (projectiles[i]->isExplosive) {
							explosions.push_back(projectiles[i]->explode());
						}
						delete projectiles[i];
						projectiles.erase(projectiles.begin() + i);
						destroyed = true;
						i--;
						break;
					}
				}
			}
		}

		if (destroyed == false) {
			projectiles[i]->move();
		}
	}

	//Kolizje eksplozji
	for (unsigned int i = 0; i < explosions.size(); i++) {
		if (explosions[i]->enabeled) {

			for (unsigned int k = 0; k < enemies.size(); k++) {
				explosions[i]->checkCollisionsWithEnemie(*enemies[k]);
			}
			explosions[i]->enabeled = false;
		}
		else {
			if (explosions[i]->duration < 0) {
				delete explosions[i];
				explosions.erase(explosions.begin() + i);
				i--;
			}
		}
	}
}

void Game::checkDeathsAndMove()
{
	for (unsigned int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->checkDeath()) {
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}
		else {
			enemies[i]->move();
		}
	}

	if (player->checkDeath() == true) {
		player->respawn();
	}

	player->updateAnimation(deltaTime);
	player->drawAnimation(deltaTime);
	player->move();
}

void Game::moveCamera()
{
	if ((player->getPosition().x - cameraPosition.x) < (screenSize.x / 3)) {
		cameraPosition.x = player->getPosition().x - (screenSize.x / 3);
	}
	else if ((player->getPosition().x - cameraPosition.x) > 2 * (screenSize.x / 3)) {
		cameraPosition.x = player->getPosition().x - 2 * (screenSize.x / 3);
	}

	if (cameraPosition.x < 0) {
		cameraPosition.x = 0;
	}
	else if (cameraPosition.x > mapWidth - screenSize.x) {
		cameraPosition.x = mapWidth - screenSize.x;
	}

	view.reset(sf::FloatRect(cameraPosition.x, cameraPosition.y, (float)screenSize.x, (float)screenSize.y));

	window->setView(view);
}

void Game::updateInterface()
{
	// CoinCounter
	coinCounter.setString("Coins: " + to_string(player->getCoins()));
	coinCounter.setPosition(cameraPosition);
}

void Game::drawAll()
{
	window->clear();

	// Backgrounds
	for (int i = 0; i < backgroundSprites.size(); i++) {
		window->draw(backgroundSprites[i]);
	}

	//Otoczenie - nieruchome
	for (unsigned int i = 0; i < obstacles.size(); i++) {
		obstacles[i].draw(*window);
	}

	//Triggery
	for (unsigned int i = 0; i < triggers.size(); i++) {
		triggers[i]->draw(*window);
	}

	//Przeciwnicy
	for (unsigned int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw(*window);
	}

	//Otoczenie - ruchome
	for (unsigned int i = 0; i < movingObjects.size(); i++) {
		movingObjects[i].draw(*window);
	}

	//Pociski
	for (unsigned int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->draw(*window);
	}

	player->draw(*window);

	//Eksplozje
	for (unsigned int i = 0; i < explosions.size(); i++) {
		explosions[i]->updateAnimation(deltaTime);
		explosions[i]->drawAnimation(deltaTime);
		explosions[i]->drawExplosion(*window);
	}

	window->draw(coinCounter);

	window->display();
}

void Game::resetPlayerVelocity()
{ 
	player->velocity.x = 0;
}
