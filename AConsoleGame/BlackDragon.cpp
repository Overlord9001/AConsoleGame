#include "BlackDragon.h"
#include "Map.h"

void BlackDragon::BreathAttack()
{
}

bool BlackDragon::Move()
{
	Map* map = Map::Instance();

	int oldY = y;
	int oldX = x;
	int r = rand() % 8;

	switch (r)
	{
	case 0: //left-up
		x -= 2;
		y--;
		break;
	case 1: //left-down
		x -= 2;
		y++;
		break;
	case 2: //down-left
		y += 2;
		x--;
		break;
	case 3: //down-right
		y += 2;
		x++;
		break;
	case 4: //right-down
		x += 2;
		y++;
		break;
	case 5: //right-up
		x += 2;
		y--;
		break;
	case 6: //up-right
		y -= 2;
		x++;
		break;
	case 7: //up-left
		y -= 2;
		x--;
		break;
	}

	if (x < 0 || y < 0 || x > MAPX - 1 || y > MAPY - 1)
	{
		x == oldX;
		y = oldY;
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

BlackDragon::BlackDragon(int hitPoint, int damage, int armorClass) : Enemy (hitPoint, damage, armorClass)
{
	icon = BLACKDRAGON;
}

BlackDragon::~BlackDragon()
{

}
