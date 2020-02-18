
// includes
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector> 
#include <typeinfo>
#include <Windows.h>
#include <time.h>
#include <irrKlang.h>

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
using namespace irrklang;

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
	system("cls"); // clear screen
	bool enemyAlive = true;
	bool playerTurn = true;

	while (enemyAlive)
	{
		//Goblin * r = nullptr;
		//if (strcmp(typeid(enemy).name(), "Goblin")) // check if enemy is a goblin
		//	r = (Goblin*)enemy;

		if (playerTurn == true)
		{
			std::cout << "A to attack, U to use item\n\n"; 
			char tempChar = _getch();

			if (tempChar == 'a')
			{
				player->Attack(enemy);
				playerTurn = false;
				tempChar = 'P';
			}

			if (tempChar == 'u')
			{
					player->UseItem();
					playerTurn = false;
					tempChar = 'P';
			}
			
		}
		else
		{
			enemy->Attack(player);
			playerTurn = true;
		}

		if (enemy->currentHealth <= 0)
		{
			if (player->item < 4)
			{
				player->item++;
			}
			enemyAlive = false;
			enemies.erase(find(enemies.begin(), enemies.end(), enemy)); // remove from vector
			delete enemy;
			system("cls"); // clear screen
		}

		//Decision in combat
	}
	

	Map::Instance()->DrawMap(); // draw map again
}

int main()
{
	srand(static_cast<int>(time(0)));

	//Window fullscreen
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_SHOWMAXIMIZED);

	Map* map = Map::Instance();

	map->MapSetup(MAPX, MAPY);

	ISoundEngine * soundEngine = createIrrKlangDevice();
	soundEngine->play2D("bgMusic.wav");
	system("cls");
	
	enemies.push_back(new Goblin(10, 10, 10));
	enemies.push_back(new Kobold(10, 10, 10));
	enemies.push_back(new Lizardman(10, 10, 10));
	enemies.push_back(new Orc(10, 10, 10));
	enemies.push_back(new BlackDragon(10, 10, 10));
	
	int oldX = 0;
	int oldY = 0;
	map->map[player->y][player->x] = PLAYER;
	bool run = true;

	map->DrawMap();
	
	int updateEnemies = 0;
	while (run) // game loop
	{
		//World roam state
		if (state == 0)
		{
			// save old position
			oldY = player->y;
			oldX = player->x;

			switch (_getch()) // get arrow keys input
			{
			case ARROW_UP:
				player->y--;
				updateEnemies++;
				break;
			case ARROW_DOWN:
				player->y++;
				updateEnemies++;
				break;
			case ARROW_RIGHT:
				player->x++;
				updateEnemies++;
				break;
			case ARROW_LEFT:
				player->x--;
				updateEnemies++;
				break;
			case 'm': //mutes the music
				if (soundEngine->getSoundVolume() != 0)
				{
					soundEngine->setSoundVolume(0);
				}
				else
				{
					soundEngine->setSoundVolume(1);
				}
				break;
			case 'p': //stops / restarts the music
				if (soundEngine->isCurrentlyPlaying("bgMusic.wav"))
				{
					soundEngine->removeAllSoundSources(); //stops
				}
				else
				{
					soundEngine->play2D("bgMusic.wav"); //starts
				}
				break;
			}

		if (map->map[player->y][player->x] == '#') // if moving into a wall
		{
			player->y = oldY;
			player->x = oldX;
		}
		else if (map->map[player->y][player->x] != '#' && map->map[player->y][player->x] != ' ' && map->map[player->y][player->x] != PLAYER) // if moving onto an enemy
		{
			for (Enemy* enemy : enemies) // find the enemy colided with
			{
				if (enemy->x == player->x && enemy->y == player->y)
				{
					// begin combat
					Combat(player, enemy);
				}
			}

			map->Move(oldX, oldY, player->x, player->y, PLAYER); // move after combat
		}
		else // if not a wall or enemy
		{
			map->Move(oldX, oldY, player->x, player->y, PLAYER);
		}

			if (updateEnemies >= 2) // time between the enemies move. So the player can catch them.
			{
				for (Enemy * enemy : enemies)
				{
					if (enemy->Move()) // if enemy colides with player begin combat
						Combat(player, enemy);
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