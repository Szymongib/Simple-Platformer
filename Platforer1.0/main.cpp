#pragma once
#include "Constants.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticRectangle.h"
#include "Bullet.h"
#include "PatrolingEnemy.h"
#include "MovingObject.h"
#include "DamagingTrigger.h"
#include "CheckPointTrigger.h"
#include "PickUp.h"

#include "Game.h"

using namespace std;






int main() {

	Game game = Game();

	game.initialize();
	game.runMainGameLoop();

	//vector<StaticRectangle> obstacles;
	//vector<Enemy*> enemies;
	//vector<Projectile*> projectiles;
	//vector<Explosion*> explosions;
	//vector<MovingObject> movingObjects;
	//vector<Trigger*> triggers;


	//sf::Vector2i screenSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	//sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Okno");

	//sf::Sprite background(globalManager.getTexture(TextureName::background).texture);
	//sf::Vector2f backgroundSize((globalManager.getTexture(TextureName::background).texture).getSize());
	//
	//sf::Font arialFont;
	//if (!arialFont.loadFromFile("Fonts/arial.ttf"))
	//	std::cout << "Loading failed" << std::endl;

	//Player *player = new Player(sf::Vector2f(45, 55), sf::Vector2f(100, 100), projectiles, globalManager.getTexture(TextureName::player), 0.2f);

#pragma region Tworzenie przeciwników

	/*Enemy *enemy1 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(20, 790), globalManager.getTexture(TextureName::enemy), 0, 100, 40);
	Enemy *enemy2 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(600, 690), globalManager.getTexture(TextureName::enemy), 0, 200, 40);
	Enemy *enemy3 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(720, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy4 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1400, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy5 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1450, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *enemy6 = new Enemy(sf::Vector2f(30, 30), sf::Vector2f(1500, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40);
	Enemy *patrolingEnemy = new PatrolingEnemy(sf::Vector2f(30, 30), sf::Vector2f(1700, 690), globalManager.getTexture(TextureName::enemy), 0, 300, 40, 1, 1650, 2000);

	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);
	enemies.push_back(enemy5);
	enemies.push_back(enemy6);
	enemies.push_back(patrolingEnemy);*/

#pragma endregion


#pragma region Otoczenie

	/*StaticRectangle flor(sf::Vector2f(backgroundSize.x, 1000), sf::Vector2f(0, 820), globalManager.getTexture(TextureName::ground));
	StaticRectangle wall(sf::Vector2f(100, 500), sf::Vector2f(800, 820 - 500), globalManager.getTexture(TextureName::ground));
	StaticRectangle wall2(sf::Vector2f(100, 500), sf::Vector2f(100, 820 - 500), globalManager.getTexture(TextureName::ground));
	StaticRectangle cealing(sf::Vector2f(300, 100), sf::Vector2f(100, 300), globalManager.getTexture(TextureName::ground));
	StaticRectangle platform(sf::Vector2f(250, 100), sf::Vector2f(200, 510), globalManager.getTexture(TextureName::ground));
	StaticRectangle platform2(sf::Vector2f(100, 2), sf::Vector2f(500, 716), globalManager.getTexture(TextureName::ground));
	StaticRectangle box(sf::Vector2f(250, 250), sf::Vector2f(1100, 820 - 250), globalManager.getTexture(TextureName::ground));
	StaticRectangle leftFrontier(sf::Vector2f(200, 2000), sf::Vector2f(-200, -500), globalManager.getTexture(TextureName::ground));
	StaticRectangle rightFrontier(sf::Vector2f(200, 2000), sf::Vector2f(backgroundSize.x, -500), globalManager.getTexture(TextureName::ground));

	obstacles.push_back(flor);
	obstacles.push_back(wall);
	obstacles.push_back(wall2);
	obstacles.push_back(cealing);
	obstacles.push_back(platform);
	obstacles.push_back(platform2);
	obstacles.push_back(box);
	obstacles.push_back(leftFrontier);
	obstacles.push_back(rightFrontier);


	MovingObject mObject1(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 2, sf::Vector2f(1250, 500), sf::Vector2f(1600, 500));
	MovingObject mObject2(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 2, sf::Vector2f(1050, 100), sf::Vector2f(1050, 600));
	MovingObject mObject3(sf::Vector2f(30, 30), globalManager.getTexture(TextureName::gear), 0, 1, sf::Vector2f(1400, 700), sf::Vector2f(2000, 400));

	movingObjects.push_back(mObject1);
	movingObjects.push_back(mObject2);
	movingObjects.push_back(mObject3);

	PickUp *coin1 = new PickUp(sf::Vector2f(40, 40), sf::Vector2f(150, 250), globalManager.getTexture(TextureName::coin), Items::coin);
	PickUp *coin2 = new PickUp(sf::Vector2f(40, 40), sf::Vector2f(200, 250), globalManager.getTexture(TextureName::coin), Items::coin);
	PickUp *coin3 = new PickUp(sf::Vector2f(40, 40), sf::Vector2f(250, 250), globalManager.getTexture(TextureName::coin), Items::coin);
	PickUp *hpPotion1 = new PickUp(sf::Vector2f(50, 50), sf::Vector2f(300, 250), globalManager.getTexture(TextureName::smallHpPotion), Items::smallHpPotion);

	triggers.push_back(coin1);
	triggers.push_back(coin2);
	triggers.push_back(coin3);
	triggers.push_back(hpPotion1);

	DamagingTrigger *spikes = new DamagingTrigger(sf::Vector2f(200, 40), sf::Vector2f(2070, 780), globalManager.getTexture(TextureName::spikes), 50);
	CheckPointTrigger *checkPoint1 = new CheckPointTrigger(sf::Vector2f(40, 80), sf::Vector2f(200, 220));
	CheckPointTrigger *checkPoint2 = new CheckPointTrigger(sf::Vector2f(40, 80), sf::Vector2f(820, 240));

	triggers.push_back(spikes);
	triggers.push_back(checkPoint1);
	triggers.push_back(checkPoint2);*/

#pragma endregion



	/*sf::View view;
	view.reset(sf::FloatRect(0, 0, (float) screenSize.x, (float) screenSize.y));
	sf::Vector2f cameraPosition(0, 0);

	sf::Clock clock;
	sf::Text coinCounter("Coins: ", arialFont, 100);*/


//Game Loop

//	while (window.isOpen())
//	{
////Czas pomiedzy klatkami i limit klatek----------------------------------------------------------------------------------------------
//#pragma region Czas pomiedzy klatkami i limit klatek
//
//		float deltaTime = clock.getElapsedTime().asSeconds();;
//		if (deltaTime > 1.0f / 20.0f) {
//			deltaTime = 1.0f / 20.0f;
//		}
//		clock.restart();
//
//		window.setFramerateLimit(60);
//
//#pragma endregion
//
//
////Eventy okna------------------------------------------------------------------------------------------------------------------------
//#pragma region Eventy Okna
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}

#pragma endregion
		

//Input i zmiana prêdkoœci gracza i przeciwników-------------------------------------------------------------------------------------
#pragma region 

		/*player->updateVelocity(deltaTime);

		for (unsigned int i = 0; i < enemies.size(); i++) {
			enemies[i]->updateVelocity(deltaTime);
		}*/

#pragma endregion
				

//Kolizje----------------------------------------------------------------------------------------------------------------------------
#pragma region Kolizje

		////Sprawdza czy player jest niewrazliwy i zmniejsza czas niewrazliwosci o delta time
		//player->decreaseImmunityDuration(deltaTime);

		////Grasz - otoczenie
		//for (unsigned int i = 0; i < obstacles.size(); i++) {
		//	player->collisionWithStaticObject(obstacles[i]);
		//}

		////Gracz - trigger
		//for (unsigned int i = 0; i < triggers.size(); i++) {
		//	if (player->collisionWithTrigger(*triggers[i])) {
		//		if (triggers[i]->isPickable){
		//			delete triggers[i];
		//			triggers.erase(triggers.begin() + i);
		//			i--;
		//		}
		//	}
		//}

		////Gracz - poruszaj¹cy siê obiekt
		//for (unsigned int i = 0; i < movingObjects.size(); i++) {
		//	movingObjects[i].updateVelocity(deltaTime);
		//	player->collisionWithMovingObject(movingObjects[i]);
		//	movingObjects[i].move();
		//}

		////Przeciwnik - otoczenie
		//for (unsigned int i = 0; i < enemies.size(); i++) {
		//	for (unsigned int k = 0; k < obstacles.size(); k++) {
		//		enemies[i]->collisionWithStaticObject(obstacles[k]);
		//	}
		//}

		//if (fabs(player->direction.y) < 0.01) {
		//	player->resetDirectionY();
		//}
		//for (unsigned int i = 0; i < enemies.size(); i++) {
		//	if (fabs(enemies[i]->direction.y) < 0.01) {
		//		enemies[i]->resetDirectionY();
		//	}
		//}


		////Gracz - przeciwnik
		//for (unsigned int i = 0; i < enemies.size(); i++) {
		//	player->collisionWithEnemy(*enemies[i]);
		//}
		//

		////Kolizje pocisków
		//for (unsigned int i = 0; i < projectiles.size(); i++) {
		//	projectiles[i]->updateVelocity(deltaTime);
		//	bool destroyed = false;
		//	
		//	if (projectiles[i]->destroy == true) {
		//		delete projectiles[i];
		//		projectiles.erase(projectiles.begin() + i);
		//		i--;
		//		destroyed = true;
		//	}
		//	else {
		//		for (unsigned int k = 0; k < obstacles.size(); k++) {
		//			if (projectiles[i]->collisionWithStaticObject(obstacles[k]) == true) {

		//				if (projectiles[i]->isExplosive) {
		//					explosions.push_back(projectiles[i]->explode());
		//				}
		//				delete projectiles[i];
		//				projectiles.erase(projectiles.begin() + i);
		//				i--;
		//				destroyed = true;
		//				break;
		//			}
		//		}
		//		if (destroyed == false) {
		//			for (unsigned int k = 0; k < enemies.size(); k++) {
		//				if (projectiles[i]->checkCollisionEnemy(*enemies[k]) == true) {

		//					if (projectiles[i]->isExplosive) {
		//						explosions.push_back(projectiles[i]->explode());
		//					}
		//					delete projectiles[i];
		//					projectiles.erase(projectiles.begin() + i);
		//					destroyed = true;
		//					i--;
		//					break;
		//				}
		//			}
		//		}
		//	}

		//	if (destroyed == false) {
		//		projectiles[i]->move();
		//	}
		//}

		////Kolizje eksplozji
		//for (unsigned int i = 0; i < explosions.size(); i++) {
		//	if (explosions[i]->enabeled) {

		//		for (unsigned int k = 0; k < enemies.size(); k++) {
		//			explosions[i]->checkCollisionsWithEnemie(*enemies[k]);
		//		}
		//		explosions[i]->enabeled = false;
		//	}
		//	else {
		//		if (explosions[i]->duration < 0) {
		//			delete explosions[i];
		//			explosions.erase(explosions.begin() + i);
		//			i--;
		//		}
		//	}
		//}

#pragma endregion


//Sprawdzanie czy jednostki ¿yj¹ i poruszanie jednostek------------------------------------------------------------------------------
#pragma region CheckDeath i move

		/*for (unsigned int i = 0; i < enemies.size(); i++) {
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
		player->move();*/

#pragma endregion

	

//Ruch kamery------------------------------------------------------------------------------------------------------------------------
#pragma region Ruch kamery

		//if ((player->getPosition().x - cameraPosition.x) < (screenSize.x / 3)) {
		//	cameraPosition.x = player->getPosition().x - (screenSize.x / 3);
		//}
		//else if ((player->getPosition().x - cameraPosition.x) > 2 * (screenSize.x / 3)) {
		//	cameraPosition.x = player->getPosition().x - 2 * (screenSize.x / 3);
		//}

		//if (cameraPosition.x < 0) {
		//	cameraPosition.x = 0;
		//}
		//else if (cameraPosition.x > backgroundSize.x - screenSize.x) {
		//	cameraPosition.x = backgroundSize.x - screenSize.x;
		//}

		//view.reset(sf::FloatRect(cameraPosition.x, cameraPosition.y, (float) screenSize.x, (float) screenSize.y));

		//window.setView(view);


		//// CoinCounter
		//coinCounter.setString("Coins: " + to_string(player->getCoins()));
		//coinCounter.setPosition(cameraPosition);

#pragma endregion



//Rysowanie--------------------------------------------------------------------------------------------------------------------------
#pragma region Rysowanie

		//window.clear();

		//window.draw(background);


		////Otoczenie - nieruchome
		//for (unsigned int i = 0; i < obstacles.size(); i++) {
		//	obstacles[i].draw(window);
		//}

		////Triggery
		//for (unsigned int i = 0; i < triggers.size(); i++) {
		//	triggers[i]->draw(window);
		//}

		////Otoczenie - ruchome
		//for (unsigned int i = 0; i < movingObjects.size(); i++) {
		//	movingObjects[i].draw(window);
		//}

		////Pociski
		//for (unsigned int i = 0; i < projectiles.size(); i++) {
		//	projectiles[i]->draw(window);
		//}

		////Przeciwnicy
		//for (unsigned int i = 0; i < enemies.size(); i++) {
		//	enemies[i]->draw(window);
		//}

		////Eksplozje
		//for (unsigned int i = 0; i < explosions.size(); i++) {
		//	explosions[i]->updateAnimation(deltaTime);
		//	explosions[i]->drawAnimation(deltaTime);
		//	explosions[i]->drawExplosion(window);
		//}

		//player->draw(window);
		//window.draw(coinCounter);

		//window.display();

#pragma endregion

		
		//player->velocity.x = 0;
		
	//}

	//delete player;

	return 0;
}