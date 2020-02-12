
// includes
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector> 
#include <typeinfo>

#include "Map.h"
#include "Enemy.h"
#include "Goblin.h"
#include <Windows.h>
#include "Lizardman.h"


// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50


int main()
{
	//Window top left fullscreen
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, 1920, 1080, TRUE);

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

		switch (_getch()) // get arrow keys input
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
					if (strcmp(typeid(enemy).name(), "Goblin")) // check if enemy is a goblin
						Goblin * r = (Goblin*)enemy;
				}
			}
		}
		else // if not a wall or enemy
		{
			map->Move(oldX, oldY, playerX, playerY, 'M');
		}

		if (updateEnemies >= 2) // time between the enemies move. So the player can catch them.
		{
			for (Enemy * enemy : enemies)
			{
				enemy->Move();
			}
			updateEnemies = false;
		}
	}
}