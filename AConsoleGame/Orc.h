#pragma once
#include "Enemy.h"
class Orc : public Enemy
{
public:
	void Rage();
	bool Move() override;

	Orc(int hitPoint, int damage, int armorClass);
	Orc();
};

