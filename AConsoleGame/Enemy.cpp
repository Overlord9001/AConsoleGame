#include "Map.h"
#include <iostream>
#include "Enemy.h"
#include <time.h>

Map* map = Map::Instance();

bool Enemy::Move()
{
	int oldY = y;
	int oldX = x;
	int r = rand() % 4;
	switch (r)
	{
	case 0:
		x++;
		break;
	case 1:
		x--;
		break;
	case 2:
		y++;
		break;
	case 3:
		y--;
		break;
	}

	if(map->map[y][x] == ' ' || map->map[y][x] == PLAYER)
	{
		map->Move(oldX, oldY, x, y, icon);
	}
	else // if trying to move into a wall
	{
		y = oldY;
		x = oldX;
	}
	return false;
}

void Enemy::UseItem()
{
}

void Enemy::Attack(Player * player)
{
	float tmpRandom = rand() % 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tmpRandom / 100) - 0.01));

	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		std::cout << "Enemy strikes you for " << (currentDamage - player->armor) << " damage \n";
		std::cout << "You have " << player->currentHealth << " health left \n \n";
	}
	else
	{
		std::cout << "Your armor repels the attack";
	}
}

Enemy::Enemy(int hitPoint, int damage, int armorClass)
{
	Player* player = Player::Instance();

	do // spawn on a random place that is not on top of the player
	{
		x = rand() % (MAPX - 2) + 1;
		y = rand() % (MAPY - 2) + 1;
	} while (player->x == x && player->y == y);

	this->maxHealth = hitPoint;
	this->damage = damage;
	this->armor = armorClass;
	currentHealth = maxHealth;
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	map = nullptr;
}
