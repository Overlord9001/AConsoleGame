#include "Goblin.h"
#include "Map.h"

void Goblin::Backstab()
{

}

bool Goblin::Move()
{
	Map* map = Map::Instance();

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

	if (map->map[y][x] == PLAYER)
	{
		map->Move(oldX, oldY, x, y, GOBLIN);
		return true;
	}
	else if (map->map[y][x] == ' ')
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

Goblin::Goblin(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	Map* map = Map::Instance();
	map->map[15][15] = GOBLIN;
	icon = GOBLIN;
}

Goblin::~Goblin()
{
}
