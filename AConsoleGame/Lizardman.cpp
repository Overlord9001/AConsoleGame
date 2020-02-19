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

void Lizardman::Attack(Player * player)
{
	float tmpRandom = rand() % 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tmpRandom / 100) - 0.01));

	TEXTRED;
	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		cout << "The lizardman strikes you for " << (currentDamage - player->armor) << " damage \n";
		cout << "You have " << player->currentHealth << " health left \n \n";
	}
	else
	{
		cout << "Your armor repels the attack";
	}
	TEXTWHITE;
}

Lizardman::Lizardman(int hitPoint, int damage, int armorClass) : Enemy(hitPoint, damage, armorClass)
{
	icon = LIZARDMAN;
}

Lizardman::Lizardman()
{
}
