#include "Orc.h"

void Orc::Rage()
{
}

Orc::Orc(int hitPoint, int damage, int armorClass, int speed) : Enemy(hitPoint, damage, armorClass, speed)
{
	icon = 'O';
}

Orc::Orc()
{
}
