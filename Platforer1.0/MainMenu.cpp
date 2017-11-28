#include "MainMenu.h"



MainMenu::MainMenu(sf::RenderWindow* window):
	window(window)
{
}


MainMenu::~MainMenu()
{
}

bool MainMenu::getGameStarted()
{
	return gameStarted;
}

void MainMenu::display()
{
	// TODO - implement 
}

void MainMenu::startGame()
{
	gameStarted = true;
}
