#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <time.h>

Player * Player::instance = 0;

Player * Player::Instance()
{
	if (instance == nullptr)
		instance = new Player;
	return instance;
}

void Player::Attack(Enemy * enemy)
{
	float tempRandom =  rand()% 51 + 1;
	//To get from 75% damage to 125% damage randomly
	int currentDamage = (int)(damage *(0.75 + (tempRandom / 100) - 0.01));

	if (currentDamage > enemy->armor)
	{
		enemy->currentHealth -= (currentDamage - enemy->armor);
		std::cout << "You strike for " << (currentDamage - enemy->armor) << " damage \n";
		std::cout << "Enemy has " << enemy->currentHealth << " health left \n \n";
	}

	else
	{
		std::cout << "Your strike was too shallow to deal damage";
	}
}

void Player::SpecialMove(Enemy * enemy)
{
}

void Player::UseItem()
{
	if (item == true)
	{
		currentHealth = maxHealth;
		std::cout << "You pull out and drink a potion regenerating your health to full";
	}

	else
	{
		std::cout << "You have no potions";
	}
}

Player::Player()
{
	x = 5;
	y = 5;
}

Player::~Player()
{
}
