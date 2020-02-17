#include "Lizardman.h"
#include "Enemy.h"
#include "Map.h"

void Lizardman::SpearThrow()
{
	
}

void Lizardman::Move()
{
	Map* map = Map::Instance();
	Enemy::Move();
}

Lizardman::Lizardman(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = 'L';
}

Lizardman::Lizardman()
{
}
