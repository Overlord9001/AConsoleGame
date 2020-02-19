#include "Kobold.h"
#include "Map.h"

bool horizontal = true;
bool vertical = false;

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
	else if (map->map[y][x] == PLAYER)
	{
		map->Move(oldX, oldY, x, y, icon);
		return true;
	}
	else // if trying to move into a wall
	{
		y = oldY;
		x = oldX;
	}
	return false;
}

void Kobold::Attack(Player * player)
{
	float tmpRandom = rand() % 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tmpRandom / 100) - 0.01));

	TEXTRED;
	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		cout << "The kobold strikes you for " << (currentDamage - player->armor) << " damage \n";
		cout << "You have " << player->currentHealth << " health left \n \n";
	}
	else
	{
		cout << "Your armor repels the attack" << endl;
	}
	TEXTWHITE;
}

Kobold::Kobold(int hitPoint, int damage, int armorClass) : Enemy (hitPoint, damage, armorClass)
{
	icon = KOBOLD;
}

Kobold::Kobold()
{
}
