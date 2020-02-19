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

void Orc::Attack(Player * player)
{
	float tmpRandom = rand() % 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tmpRandom / 100) - 0.01));

	TEXTRED;
	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		cout << "The orc strikes you for " << (currentDamage - player->armor) << " damage \n";
		cout << "You have " << player->currentHealth << " health left \n \n";
	}
	else
	{
		cout << "Your armor repels the attack";
	}
	TEXTWHITE;
}

Orc::Orc(int hitPoint, int damage, int armorClass) : Enemy(hitPoint, damage, armorClass)
{
	icon = ORC;
}

Orc::Orc()
{
}
