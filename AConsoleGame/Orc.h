#pragma once
#include "Enemy.h"
class Orc : public Enemy
{
public:
	void Rage();

	Orc(int hitPoint, int damage, int armorClass, int speed);
	Orc();
};

