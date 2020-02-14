#pragma once
#include "Enemy.h"
class BlackDragon : public Enemy
{
public:
	void BreathAttack();
	void Move() override;

	BlackDragon(int hitPoint, int damage, int armorClass, int speed);
};

