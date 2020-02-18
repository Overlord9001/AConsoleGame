#pragma once
#include <string>
#include "Player.h"


using namespace std;

class Player;
class Enemy
{
public:
	int currentHealth = 100;
	int maxHealth = 100;
	int damage = 10;
	int armor = 5;
	int x;
	int y;
	char icon = 'E';

	virtual bool Move(); // return true if moving into the player to begin combat
	void UseItem();
	void Attack(Player * player);

	Enemy(int hitPoint, int damage, int armorClass, int speed);
	Enemy();
	~Enemy();

};

