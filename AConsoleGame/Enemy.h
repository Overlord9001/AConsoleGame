#pragma once

#include <string>

using namespace std;

class Enemy
{
public:
	int hitPoint;
	int damage;
	int armorClass;
	int speed;
	int x;
	int y;

	void Move();
	void UseItem();
	void Attack();

	Enemy(int hitPoint, int damage, int armorClass, int speed);

};

