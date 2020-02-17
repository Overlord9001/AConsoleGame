#include "BlackDragon.h"
#include "Map.h"

void BlackDragon::BreathAttack()
{
}

void BlackDragon::Move()
{
	Map* map = Map::Instance();
	Enemy::Move();
}

BlackDragon::BlackDragon(int hitPoint, int damage, int armorClass, int speed) : Enemy (hitPoint, damage, armorClass, speed)
{
	icon = 'B';
}
