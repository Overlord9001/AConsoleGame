#pragma once
#include "Enemy.h"

class Lizardman : public Enemy
{
public:
	bool Move() override;
	void Attack(Player * player) override;

	Lizardman(int hitPoint, int damage, int armorClass);
	Lizardman();
};

