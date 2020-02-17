#include "Kobold.h"
#include "Map.h"

bool horizontal = true;
bool vertical = false;

void Kobold::SlingShot()
{
}

bool Kobold::Move()
{
	Map* map = Map::Instance();
	int oldY = y;
	int oldX = x;
	int r = rand() % 2;

	if (horizontal)
	{
		if (r == 0)
		{
			x--;
		}
		else if (r == 1)
		{
			x++;
		}
		horizontal = false;
		vertical = true;
	}
	else if (vertical)
	{
		if (r == 0)
		{
			y--;
		}
		else if (r == 1)
		{
			y++;
		}
		horizontal = true;
		vertical = false;
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

Kobold::Kobold(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	icon = 'K';
}

Kobold::Kobold()
{
}
