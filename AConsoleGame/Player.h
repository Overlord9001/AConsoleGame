#pragma once
#include "Enemy.h"

class Enemy;
class Player
{
public:
	int gold = 1337;
	int damage = 15;
	int maxHealth = 100;
	int currentHealth = 100;
	int armor = 1;
	int item;
	int x;
	int y;

	static Player * Instance();
	void Attack(Enemy * enemy);
	void SpecialMove(Enemy * enemy);
	void UseItem();

	~Player();

private:
	static Player * instance;
	Player();
};

