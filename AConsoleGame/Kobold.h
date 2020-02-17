#pragma once
#include "Enemy.h"

class Kobold : public Enemy
{
public:
	void SlingShot();
	void Move() override;

	Kobold(int hitPoint, int damage, int armorClass, int speed);
	Kobold();
};

