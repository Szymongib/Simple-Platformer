#pragma once
#include "SFML\Window.hpp"
#include "SFML\graphics.hpp"

class MainMenu
{
private:
	sf::RenderWindow* window;
	bool gameStarted;

public:
	MainMenu(sf::RenderWindow* window);
	~MainMenu();

	bool getGameStarted();

	void display();
	void startGame();
};

