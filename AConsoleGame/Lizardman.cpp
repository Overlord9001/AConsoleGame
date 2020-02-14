#include "Lizardman.h"
#include "Enemy.h"

void Lizardman::SpearThrow()
{
	
}

Lizardman::Lizardman(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = 'L';
}

Lizardman::Lizardman()
{
}
