#include "Map.h"
#include <iostream>
#include "Enemy.h"

Map* map = Map::Instance();
int tempRandom = rand() % 51 + 1;

void Enemy::Move()
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

	if(map->map[y][x] != 'O')
	{
		map->Move(oldX, oldY, x, y, 'E');
	}
	else // if trying to move into a wall
	{
		y = oldY;
		x = oldX;
		//Move();
	}
}

void Enemy::UseItem()
{
}

void Enemy::Attack(Player * player)
{


	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tempRandom / 100) - 0.01));

	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		std::cout << "Enemy strikes you for " << (currentDamage - player->armor) << " damage \n";
		std::cout << "You have " << player->currentHealth << " health left \n";
	}

	else
	{
		std::cout << "Your armor repels the attack";
	}
}

Enemy::Enemy(int hitPoint, int damage, int armorClass, int speed)
{
	x = 15;
	y = 15;

}

Enemy::Enemy()
{
}
