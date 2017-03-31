#include "Wizard.h"
#include <iostream>


using namespace std;

Wizard::Wizard()
{
	health = 350;
	intellect = 4;
}


int Wizard::fireball()
{
	return randnum() + 15;
}

int Wizard::blizzard()
{
	return randnum() + 12;
}

int Wizard::water()
{
	return randnum() + 11;
}

int Wizard::heal()
{
	return randnum() + 25;
}

int Wizard::randnum()
{
	return rand() % 20 + 1;
}