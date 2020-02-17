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
	Player* player = Player::Instance();

	if (player->x > x)
	{
		x++;
	}
	else if (player->y > y)
	{
		y++;
	}
	else if (player->x < x)
	{
		x--;
	}
	else if (player->y < y)
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
	icon = ORC;
}

Orc::Orc()
{
}
