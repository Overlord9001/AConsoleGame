
// includes
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector> 
#include <typeinfo>
#include <Windows.h>
#include <time.h>

#include "Map.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Lizardman.h"
#include "Player.h"


// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50

Player player = Player();
Enemy enemy = Enemy();
Player * playerPTR = &player;
Enemy * enemyPTR = &enemy;
int state = 1;


int main()
{
	srand(static_cast<int>(time(0)));
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
	map->map[playerY][playerX] = PLAYER;
	map->map[15][15] = 'E';
	bool run = true;

	map->DrawMap();
	
	int updateEnemies = 0;
	while (run) // game loop
	{
		//World roam state
		if (state == 0)
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

			map->Move(oldX, oldY, playerX, playerY, PLAYER);
		}
		else // if not a wall or enemy
		{
			map->Move(oldX, oldY, playerX, playerY, PLAYER);
		}

			if (updateEnemies >= 2) // time between the enemies move. So the player can catch them.
			{
				for (Enemy * enemy : enemies)
				{
					enemy->Move();
				}
				updateEnemies = false;
			}

#pragma region DrawingStats

			map->SetCursorPosition(0, MAPY + 2);

			std::cout << "Gold:" << player.gold;

			map->SetCursorPosition(20, MAPY + 2);

			std::cout << "Armor:" << player.armor;

			map->SetCursorPosition(40, MAPY + 2);

			std::cout << "Health:" << player.currentHealth;

			map->SetCursorPosition(0, MAPY + 4);

			std::cout << "AVG DMG:" << (int)(player.damage);

			map->SetCursorPosition(20, MAPY + 4);

			std::cout << "MIN DMG:" << (int)(player.damage * 0.75);

			map->SetCursorPosition(40, MAPY + 4);

			std::cout << "MAX DMG:" << (int)(player.damage * 1.25);

			map->SetCursorPosition(0, 0);

#pragma endregion
		}

		//Combat state
		if (state = 1)
		{
			player.Attack(enemyPTR);
			Sleep(2000);
			enemy.Attack(playerPTR);
			Sleep(2000);
		}
	}
}