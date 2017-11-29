#pragma once
#include <vector>
#include "StaticRectangle.h"
#include "Enemy.h"
#include "MovingObject.h"
#include "Trigger.h"
#include "PredefinedObjectsGenerator.h"

class PredefinedObjectsGenerator;

class MapCreator
{
private:
	PredefinedObjectsGenerator objectGenerator;

public:
	MapCreator();
	~MapCreator();

	void CreateMapFromTextFile(
		int* mapWidth,
		std::string fileName,
		std::vector<StaticRectangle>* obstacles,
		std::vector<Enemy*>* enemies,
		std::vector<MovingObject>* movingObjects,
		std::vector<Trigger*>* triggers,
		Player* player,
		LevelFinishTrigger** finishTrigger);

};

