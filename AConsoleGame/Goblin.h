#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
	void Backstab();
	bool Move() override;
	void Attack(Player * player);

	Goblin(int hitPoint, int damage, int armorClass);
	~Goblin();

};

