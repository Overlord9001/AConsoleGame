#include "Lizardman.h"
#include "Enemy.h"
#include "Map.h"

void Lizardman::SpearThrow()
{
	
}

bool Lizardman::Move()
{
	Map* map = Map::Instance();

	int oldY = y;
	int oldX = x;
	Player* player = Player::Instance();

	if (abs(player->x - x) > 3)
	{
		if (player->x > x)
		{
			x++;
		}
		else if (player->x < x)
		{
			x--;
		}
	}
	else if (abs(player->y - y) > 3)
	{
		if (player->y > y)
		{
			y++;
		}
		else if (player->y < y)
		{
			y--;
		}
	}
	else if (abs(player->x - x) < 3 || abs(player->y - y) < 3)
	{
		if (player->x > x)
		{
			x--;
		}
		else if (player->x < x)
		{
			x++;
		}
		else if (player->y > y)
		{
			y--;
		}
		else if (player->y < y)
		{
			y++;
		}
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
	return false;
}

Lizardman::Lizardman(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = LIZARDMAN;
}

Lizardman::Lizardman()
{
}
