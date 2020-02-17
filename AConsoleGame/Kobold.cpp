#include "Kobold.h"
#include "Map.h"

//Map* map = Map::Instance();

void Kobold::SlingShot()
{
}

void Kobold::Move()
{
	Enemy::Move();
}

Kobold::Kobold(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	icon = 'K';
}

Kobold::Kobold()
{
}
