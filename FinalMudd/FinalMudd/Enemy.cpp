#include <iostream>
#include "Enemy.h"

using namespace std;


Enemy::Enemy()
{
	health = 100;
	strength = 10;
}

int Enemy::magic()
{
	return randnum() + 12;
}

int Enemy::swing()
{
	return randnum() + 5;
}

int Enemy::randnum()
{
	return rand() % 20 + 1;
}

int Boss::strengthUp()
{
	strength = strength++;
	return strength;
}