#pragma once

#include <string>

using namespace std;

class Enemy
{
	int hitPoint;
	int damage;
	int armorClass;
	int speed;

	void Move();
	void UseItem();
	void Attack();

	Enemy(int hitPoint, int damage, int armorClass, int speed);

};

