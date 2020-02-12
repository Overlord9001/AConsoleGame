#pragma once
#include "Enemy.h"

class Lizardman : public Enemy
{
public:
	void SpearThrow();

	Lizardman(int hitPoint, int damage, int armorClass, int speed);
	Lizardman();
};

