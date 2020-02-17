#include "Lizardman.h"
#include "Enemy.h"
#include "Map.h"

//Map* map = Map::Instance();

void Lizardman::SpearThrow()
{
	
}

void Lizardman::Move()
{
	Enemy::Move();
}

Lizardman::Lizardman(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = 'L';
}

Lizardman::Lizardman()
{
}
