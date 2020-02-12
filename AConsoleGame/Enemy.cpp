#include "Enemy.h"
#include "Map.h"

Map* map = Map::Instance();

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

void Enemy::Attack()
{
}

Enemy::Enemy(int hitPoint, int damage, int armorClass, int speed)
{
	x = 15;
	y = 15;

}

Enemy::Enemy()
{
}
