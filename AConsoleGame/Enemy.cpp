#include "Enemy.h"
#include "Map.h"

Map* map = Map::Instance();
int playerX = 15;
int playerY = 15;
int oldX = 0;
int oldY = 0;

void Enemy::Move()
{
	oldY = playerY;
	oldX = playerX;
	int r = rand() % 4;
	switch (r)
	{
	case 0:
		playerX++;
		break;
	case 1:
		playerX--;
		break;
	case 2:
		playerY++;
		break;
	case 3:
		playerY--;
		break;
	}

	if(map->map[playerY][playerX] != 'O')
	{
		map->Move(oldX, oldY, playerX, playerY, 'E');
	}
	else // if trying to move into a wall
	{
		playerY = oldY;
		playerX = oldX;
		Move();
	}
}

void Enemy::UseItem()
{
}

void Enemy::Attack()
{
}

Enemy::Enemy(int hitPoint, int damage, int armorClass, int speed)
{
}
