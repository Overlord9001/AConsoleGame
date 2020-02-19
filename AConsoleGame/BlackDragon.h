#pragma once
#include "Enemy.h"

class BlackDragon : public Enemy
{
public:
	void BreathAttack();
	bool Move() override;
	void Attack(Player * player) override;

	BlackDragon(int hitPoint, int damage, int armorClass);
	~BlackDragon();
};

