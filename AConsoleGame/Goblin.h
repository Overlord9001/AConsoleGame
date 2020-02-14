#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
	void Backstab();
	void Move() override;

	Goblin(int hitPoint, int damage, int armorClass, int speed);
	~Goblin();

};

