#include "MapCreator.h"
#include <fstream>

class PredefinedObjectsGenerator;

MapCreator::MapCreator()
{
	objectGenerator = PredefinedObjectsGenerator();
}


MapCreator::~MapCreator()
{
}

void MapCreator::CreateMapFromTextFile(
	int* mapWidth,
	std::string fileName,
	std::vector<StaticRectangle>* obstacles, 
	std::vector<Enemy*>* enemies,
	std::vector<MovingObject>* movingObjects,
	std::vector<Trigger*>* triggers,
	Player* player,
	LevelFinishTrigger** finishTrigger)
{
	std::fstream file;
	file.open(fileName);
	std::string line;
	int lineNum = 0;
	int maxLineLength = 0;

	while (getline(file, line))
	{
		for (int i = 0; i < line.length(); i++) {
			sf::Vector2f position(BASE_BLOCK_SIZE*i, BASE_BLOCK_SIZE*lineNum);
			char ch = line[i];
			switch (ch) {
			case 'S':
				obstacles->push_back(objectGenerator.generateSurfaceBlock(position));
				break;
			case 'G':
				obstacles->push_back(objectGenerator.generateGroundBlock(position));
				break;
			case 'C':
				triggers->push_back(objectGenerator.generateCoin(position));
				break;
			case 'H':
				triggers->push_back(objectGenerator.generateSmallHealingPotion(position));
				break;
			case 'P':
				triggers->push_back(objectGenerator.generateCheckPoint(position));
				break;
			case '2':
				enemies->push_back(objectGenerator.generateChargingEnemy(position, player));
				break;
			case 'F':
				*finishTrigger = objectGenerator.generateLevelFinishTrigger(position);
				break;
			}
		}
		if (line.length() > maxLineLength)
			maxLineLength = line.length();
		lineNum++;

	}

	*mapWidth = maxLineLength*BASE_BLOCK_SIZE;
	file.close();
}
