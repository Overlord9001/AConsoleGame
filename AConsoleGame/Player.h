#pragma once
#include "Enemy.h"

class Enemy;
class Player
{
public:
	int gold = 3333;
	int damage = 15;
	int maxHealth = 100;
	int currentHealth = 100;
	int armor = 5;
	bool item = true;

	void Attack(Enemy * enemy);
	void SpecialMove(Enemy * enemy);
	void UseItem();

	Player();
	~Player();
};

