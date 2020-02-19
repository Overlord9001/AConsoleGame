#pragma once
#include "Enemy.h"
class Orc : public Enemy
{
public:
	bool Move() override;
	void Attack(Player * player) override;

	Orc(int hitPoint, int damage, int armorClass);
	Orc();
};

