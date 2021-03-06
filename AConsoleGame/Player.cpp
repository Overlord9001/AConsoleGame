#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

Player * Player::instance = nullptr;

Player * Player::Instance()
{
	if (instance == nullptr)
		instance = new Player;
	return instance;
}

void Player::Attack(Enemy * enemy)
{
	string attacker;

	switch (enemy->icon) // determines which enemy the player are fighting
	{
	case 'G':
		attacker = "Goblin";
		break;
	case 'O':
		attacker = "Orc";
		break;
	case 'K':
		attacker = "Kobold";
		break;
	case 'L':
		attacker = "Lizardman";
		break;
	case 'B':
		attacker = "Black Dragon";
		break;
	}

	float tempRandom =  rand()% 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tempRandom / 100) - 0.01));

	TEXTPLAYER;
	if (currentDamage > enemy->armor)
	{
		enemy->currentHealth -= (currentDamage - enemy->armor);
		cout << "You strike for " << (currentDamage - enemy->armor) << " damage \n";
		cout << attacker << " has " << enemy->currentHealth << " health left \n \n";
	}
	else
	{
		cout << "Your strike was too shallow to deal damage" << endl;
	}
	TEXTWHITE;
}

void Player::UseItem()
{
	if (item >= 1 && currentHealth != maxHealth)
	{
		currentHealth = maxHealth;
		cout << "You pull out and drink a potion regenerating your health to full\n\n";
		item--;
	}

	else
	{
		cout << "You have no potions\n\n";
	}
}

Player::Player()
{
	x = 5;
	y = 5;
	this->item = 3;
}

Player::~Player()
{
	instance = nullptr;
}
