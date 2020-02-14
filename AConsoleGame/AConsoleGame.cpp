
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
#include "Kobold.h"
#include "Orc.h"
#include "BlackDragon.h"
#include "Player.h"


// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50

Enemy enemy = Enemy();
Player * player = Player::Instance();
Enemy * enemyPTR = &enemy;
int state = 0;
vector<Enemy*> enemies;


void Combat(Player * player, Enemy * enemy)
{
	Goblin * r = nullptr;
	if (strcmp(typeid(enemy).name(), "Goblin")) // check if enemy is a goblin
		r = (Goblin*)enemy;

	// test
	enemies.erase(find(enemies.begin(), enemies.end(), enemy)); // remove from vector
	delete r;
	r = nullptr;
	// test

	// clear screen
	// draw combat screen
	// do combat
	// draw map again
}

int main()
{
	srand(static_cast<int>(time(0)));

	//Window fullscreen
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_SHOWMAXIMIZED);

	Map* map = Map::Instance();

	map->MapSetup(MAPX, MAPY);

	
	enemies.push_back(new Goblin(10, 10, 10, 10));
	enemies.push_back(new Kobold(10, 10, 10, 10));
	enemies.push_back(new Lizardman(10, 10, 10, 10));
	enemies.push_back(new Orc(10, 10, 10, 10));
	enemies.push_back(new BlackDragon(10, 10, 10, 10));
	
	
	int oldX = 0;
	int oldY = 0;
	map->map[playerY][playerX] = PLAYER;
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

		if (map->map[playerY][playerX] == '#') // if moving into a wall
		{
			playerY = oldY;
			playerX = oldX;
		}
		else if (map->map[playerY][playerX] != 'O' && map->map[playerY][playerX] != ' ') // if moving onto an enemy
		{
			for (Enemy* enemy : enemies)
			{
				if (enemy->x == playerX && enemy->y == playerY)
				{
					// begin combat
					Combat(player, enemy);
				}
			}

			map->Move(oldX, oldY, playerX, playerY, PLAYER); // move after combat
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
				updateEnemies = 0;
			}

#pragma region DrawingStats

			map->SetCursorPosition(0, MAPY + 2);

			std::cout << "Gold:" << player->gold;

			map->SetCursorPosition(20, MAPY + 2);

			std::cout << "Armor:" << player->armor;

			map->SetCursorPosition(40, MAPY + 2);

			std::cout << "Health:" << player->currentHealth;

			map->SetCursorPosition(0, MAPY + 4);

			std::cout << "AVG DMG:" << (int)(player->damage);

			map->SetCursorPosition(20, MAPY + 4);

			std::cout << "MIN DMG:" << (int)(player->damage * 0.75);

			map->SetCursorPosition(40, MAPY + 4);

			std::cout << "MAX DMG:" << (int)(player->damage * 1.25);

			map->SetCursorPosition(0, 0);

#pragma endregion
		}

		//Combat state
		if (state == 1)
		{
			player->Attack(enemyPTR);
			Sleep(2000);
			enemy.Attack(player);
			Sleep(2000);
		}
	}
}