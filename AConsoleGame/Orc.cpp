#include "Orc.h"
#include "Player.h"
#include "Map.h"

void Orc::Rage()
{
}

bool Orc::Move()
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

	if (map->map[y][x] == ' ' || map->map[y][x] == PLAYER)
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

Orc::Orc(int hitPoint, int damage = 5, int armorClass = 1) : Enemy(hitPoint, damage, armorClass)
{
	icon = ORC;
}

Orc::Orc()
{
}
