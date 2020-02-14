#include "BlackDragon.h"
#include "Map.h"

//Map* map = Map::Instance();

void BlackDragon::BreathAttack()
{
}

void BlackDragon::Move()
{
	Enemy::Move();
}

BlackDragon::BlackDragon(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	icon = 'B';
}
