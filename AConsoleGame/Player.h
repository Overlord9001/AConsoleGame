#pragma once
#include "Enemy.h"

class Enemy;
class Player
{
public:
	int gold = 30;
	int damage = 15;
	int maxHealth = 100;
	int currentHealth = 100;
	int armor = 1;
	int item;
	int x;
	int y;
	float difficultyIncrease = 0.0f;

	static Player * Instance();
	void Attack(Enemy * enemy);
	void UseItem();

	~Player();

private:
	static Player * instance;
	Player();
};

