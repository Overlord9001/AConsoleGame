#pragma once
#include "Enemy.h"

class Kobold : public Enemy
{
public:
	void SlingShot();
	bool Move() override;
	void Attack(Player * player) override;

	Kobold(int hitPoint, int damage, int armorClass);
	Kobold();
};

