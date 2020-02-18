#pragma once
#include "Enemy.h"

class Lizardman : public Enemy
{
public:
	void SpearThrow();
	bool Move() override;

	Lizardman(int hitPoint, int damage, int armorClass);
	Lizardman();
};

