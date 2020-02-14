#include "Orc.h"
#include "Player.h"
#include "Map.h"



void Orc::Rage()
{
}

void Orc::Move()
{
	Map* map = Map::Instance();
	int oldY = y;
	int oldX = x;
	if (map->playerX > x)
	{
		x++;
	}
	else if (map->playerY > y)
	{
		y++;
	}
	else if (map->playerX < x)
	{
		x--;
	}
	else if (map->playerY < y)
	{
		y--;
	}

	if (map->map[y][x] == ' ')
	{
		map->Move(oldX, oldY, x, y, icon);
	}
	else // if trying to move into a wall
	{
		y = oldY;
		x = oldX;
	}
}

Orc::Orc(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = 'O';
}

Orc::Orc()
{
}
