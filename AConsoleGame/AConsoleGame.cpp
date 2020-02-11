
// includes
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector> 

#include "Map.h"
#include "Enemy.h"
#include "Goblin.h"

// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50


int main()
{
	
	Map* map = Map::Instance();
	
	vector<Enemy*> enemies;
	enemies.push_back(new Goblin(10, 10, 10, 10));
	
	map->MapSetup(MAPX, MAPY);

	int playerX = 5;
	int playerY = 5;
	int oldX = 0;
	int oldY = 0;
	map->map[playerY][playerX] = 'M';
	map->map[15][15] = 'E';
	bool run = true;

	for (int y = 0; y < MAPY; y++)
	{
		for (int x = 0; x < MAPX; x++)
		{
			cout << map->map[y][x] << " ";
		}
		cout << endl;
	}
	
	int updateEnemies = 0;
	while (run)
	{
		// save old position
		oldY = playerY;
		oldX = playerX;

		switch (_getch())
		{
		case ARROW_UP:
			playerY--;
			updateEnemies++;
			break;
		case ARROW_DOWN:
			playerY++;
			updateEnemies++;
			break;
		case ARROW_RIGHT:
			playerX++;
			updateEnemies++;
			break;
		case ARROW_LEFT:
			playerX--;
			updateEnemies++;
			break;
		}

		if (map->map[playerY][playerX] == 'O') // if moving into a wall
		{
			playerY = oldY;
			playerX = oldX;
		}
		else if (map->map[playerY][playerX] == 'E') // if moving onto an enemy
		{
			for (Enemy* enemy : enemies)
			{
				if (enemy->x == playerX && enemy->y == playerY)
				{
					// begin combat
					Goblin * g = dynamic_cast<Goblin*>(enemy);
				}
			}
		}
		else // if not a wall or enemy
		{
			map->Move(oldX, oldY, playerX, playerY, 'M');
		}

		if (updateEnemies >= 2)
		{
			for (Enemy * enemy : enemies)
			{
				enemy->Move();
			}
			updateEnemies = false;
		}
	}
}