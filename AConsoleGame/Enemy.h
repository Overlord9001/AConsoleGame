#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include "Player.h"


using namespace std;

class Player;
class Enemy
{
public:
	int maxHealth = 100;
	int currentHealth = maxHealth;
	int damage = 10;
	int armor = 5;
	int x;
	int y;
	char icon = 'E';

	virtual bool Move(); // return true if moving into the player to begin combat
	void UseItem();
	virtual void Attack(Player * player);

	Enemy(int hitPoint, int damage, int armorClass);
	Enemy();
	~Enemy();

};

