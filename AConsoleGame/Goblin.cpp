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

void Goblin::Attack(Player * player)
{
	float tmpRandom = rand() % 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tmpRandom / 100) - 0.01));

	TEXTRED;
	if (currentDamage > player->armor)
	{
		player->currentHealth -= (currentDamage - player->armor);
		cout << "The goblin strikes you for " << (currentDamage - player->armor) << " damage \n";
		cout << "You have " << player->currentHealth << " health left \n \n";
	}
	else
	{
		cout << "Your armor repels the attack" << endl;
	}
	TEXTWHITE;

}

Goblin::Goblin(int hitPoint, int damage, int armorClass) : Enemy (hitPoint, damage, armorClass)
{
	icon = GOBLIN;
}

Goblin::~Goblin()
{
}
