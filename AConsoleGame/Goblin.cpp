#include "Goblin.h"
#include "Map.h"



void Goblin::Backstab()
{

}

void Goblin::Move()
{
	Map* map = Map::Instance();
	int oldY = y;
	int oldX = x;
	int r = rand() % 4;
	switch (r)
	{
	case 0:
		x++;
		y++;
		break;
	case 1:
		x++;
		y--;
		break;
	case 2:
		x--;
		y++;
		break;
	case 3:
		x--;
		y--;
		break;
	}
	
	Player* player = Player::Instance();

	if (player->y < y)
	{
		y--;
	}
	else if (player->y > y)
	{
		y++;
	}
	else if (player->x < x)
	{
		x--;
	}
	else if (player->x > x)
	{
		x++;
	}

	if (map->map[y][x] == ' ')
	{
		map->Move(oldX, oldY, x, y, GOBLIN);
	}
	else // if trying to move into an invalid spot
	{
		y = oldY;
		x = oldX;
	}
}

Goblin::Goblin(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	Map* map = Map::Instance();
	map->map[15][15] = GOBLIN;
}

Goblin::~Goblin()
{
}
