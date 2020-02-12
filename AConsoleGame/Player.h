#pragma once
#include "Enemy.h"

class Player
{
public:
	int gold = 3333;
	int damage = 5;
	int health = 100;
	int armor = 10;

	virtual void Attack(Enemy enemy);
	virtual void SpecialMove(Enemy enemy);

	Player();
	~Player();
};

