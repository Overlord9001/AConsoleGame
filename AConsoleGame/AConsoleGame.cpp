// includes
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector> 
#include <list>
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

Player * player = Player::Instance();
list<Enemy*> enemies; // we use list because its easier to add and remove individual elements in runtime
int shopLevel = 0;

void Reset()
{
	Map* map = Map::Instance();
	for (Enemy * enemy : enemies) // calls the destructor for all elements
	{
		delete enemy;
	}
	enemies.clear(); // clear vector

	enemies.push_back(new Goblin(10, 2, 0));
	enemies.push_back(new Kobold(15, 3, 0));
	enemies.push_back(new Lizardman(30, 4, 2));
	enemies.push_back(new Orc(20, 5, 1));
	enemies.push_back(new BlackDragon(50, 10, 5));

	map->MapSetup(MAPX, MAPY);
	delete player;
	player = Player::Instance();
	player->item = 3;
	map->map[player->y][player->x] = PLAYER;

	system("cls");
}

void Shop()
{
	system("cls"); // clear screen
	bool browsing = true;

	while (browsing == true)
	{
		std::cout << "Current Gold:  " << (player->gold) << "\n";
		std::cout << "Current Damage:  " << (player->damage) << "\n";
		std::cout << "Current Health:  " << (player->maxHealth) << "\n";
		std::cout << "Current Armor:  " << (player->armor) << "\n";
		std::cout << "Current Potions:  " << (player->item) << "\n\n";

		std::cout << "1) Upgrade Damage: " << (5 + (shopLevel * 2)) << "G\n";
		std::cout << "2) Upgrade Health: " << (4 + (shopLevel * 2)) << "G\n";
		std::cout << "3) Upgrade Armor: " << (7 + (shopLevel * 2)) << "G\n";
		std::cout << "4) Buy Potion: " << (3 + (shopLevel * 2)) << "G\n";
		std::cout << "Press E to Exit";

		char tempChar = _getch();

		if (tempChar == '1')
		{
			if (player->gold >= (5 + (shopLevel * 2)))
			{
				player->gold -= (5 + (shopLevel * 2));
			    shopLevel++;
				player->damage = (int)(player->damage++);
			}
		}

		if (tempChar == '2')
		{
			if (player->gold >= (4 + (shopLevel * 2)))
			{
				player->gold -= (4 + (shopLevel * 2));
				shopLevel++;
				player->maxHealth = (int)(player->maxHealth += 10);
			}
		}

		if (tempChar == '3')
		{
			if (player->gold >= (7 + (shopLevel * 2)))
			{
				player->gold -= (7 + (shopLevel * 2));
				shopLevel++;
				player->armor++;
			}
		}

		if (tempChar == '4')
		{
			if (player->gold >= (3 + (shopLevel * 2)))
			{
				player->gold -= (3 + (shopLevel * 2));
				shopLevel++;
				player->item++;
			}
		}

		system("cls"); // clear screen

		if (tempChar == 'e')
		{
			player->y += 2;
			browsing = false;
			Map::Instance()->DrawMap(); // draw map again
		}

		
	}

}

void Combat(Player * player, Enemy * enemy)
{
	system("cls"); // clear screen
	bool combatInProgress = true;
	bool playerTurn = true;

	string attacker;

	switch (enemy->icon) // determines which enemy the player are fighting
	{
	case 'G':
		attacker = "Goblin";
		break;
	case 'O':
		attacker = "Orc";
		break;
	case 'K':
		attacker = "Kobold";
		break;
	case 'L':
		attacker = "Lizardman";
		break;
	case 'B':
		attacker = "Black Dragon";
		break;
	}
	cout << "Your enemy is a(n) " << attacker << "\nTheir stats are:\n" << "Average damage: " << enemy->damage << "\nHealth: " << enemy->currentHealth << "\nArmor Class: " << enemy->armor << endl; // tells player which enemy they're fighting adn their stats

	while (combatInProgress)
	{
		if (playerTurn == true)
		{
			cout << "A to attack, U to use item\n\n"; 
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
			int goldLoot = rand() % 7 + 9; // between 9 and 15
			player->gold += goldLoot;

			player->difficultyIncrease += 0.05f;
			combatInProgress = false;
			enemies.remove(enemy);
			delete enemy;
			//system("cls"); // clear screen
			
			cout << "You defeated the enemy gaining ";
			TEXTORC;
			cout << goldLoot << " gold coins" << endl;
			TEXTWHITE;
			cout << "Press any key to continue" << endl;
			_getch();
			system("cls");
		}

		if (player->currentHealth <= 0)
		{
			combatInProgress = false;

			system("cls");
			TEXTRED;
			cout << "DEATH" << endl;
			TEXTWHITE;
			cout << "\nPress any key to restart" << endl;
			_getch();
			
			Reset();
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

	ISoundEngine * soundEngine = createIrrKlangDevice();
	soundEngine->play2D("bgMusic.wav");
	system("cls");

	Reset();
	map->DrawMap();

	int oldX = 0;
	int oldY = 0;

	int updateEnemies = 0;
	int spawnEnemies = 0;
	bool run = true;
	while (run) // game loop
	{
		// save old position
		oldY = player->y;
		oldX = player->x;

		switch (_getch()) // get arrow keys input
		{
		case ARROW_UP:
			player->y--;
			break;
		case ARROW_DOWN:
			player->y++;
			break;
		case ARROW_RIGHT:
			player->x++;
			break;
		case ARROW_LEFT:
			player->x--;
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

		if (player->x != oldX || player->y != oldY)
		{
			updateEnemies++;
			spawnEnemies++;
			if (player->currentHealth < player->maxHealth)
			{
				player->currentHealth++;
			}
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
					break;
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
				{
					Combat(player, enemy);
					break;
				}
			}
			updateEnemies = 0;
		}
		if (spawnEnemies >= 20)
		{
			switch (rand() % 5)
			{
			case 0:
				enemies.push_back(new Goblin(10 + 10.0f * player->difficultyIncrease, 2 + 2.0f * player->difficultyIncrease, 0));
				break;
			case 1:
				enemies.push_back(new Orc(20 + 20.0f * player->difficultyIncrease, 5 + 5.0f * player->difficultyIncrease, 1 + 1.0f * player->difficultyIncrease));
				break;
			case 2:
				enemies.push_back(new Kobold(15 + 15.0f * player->difficultyIncrease, 3 + 3.0f * player->difficultyIncrease, 0.5f + 0.5f * player->difficultyIncrease));
				break;
			case 3:
				enemies.push_back(new Lizardman(30 + 50.0f * player->difficultyIncrease, 4 + 4.0f * player->difficultyIncrease, 2 + 2.0f * player->difficultyIncrease));
				break;
			case 4:
				enemies.push_back(new BlackDragon(50 + 50.0f * player->difficultyIncrease, 10 + 10.0f * player->difficultyIncrease, 5 + 5.0f * player->difficultyIncrease));
				break;
			}
			spawnEnemies = 0;
		}
		// flyt til drawmap hvis man kun får ting når man har kæmpet
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

#pragma region Enter Shop

		map->SetCursorPosition(50, 1);
		std::cout << "S";
		map->SetCursorPosition(0, 0);

		if (player->x == 25 && player->y == 1)
		{
			Shop();
		}
#pragma endregion

	}

}

