#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
	void Backstab();
	void Move();

	Goblin(int hitPoint, int damage, int armorClass, int speed);
	~Goblin();

};

