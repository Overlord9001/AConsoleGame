#pragma once
#include "Enemy.h"
class Kobold : public Enemy
{
public:
	void SlingShot();

	Kobold(int hitPoint, int damage, int armorClass, int speed);
	Kobold();
};

