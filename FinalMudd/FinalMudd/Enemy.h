#include <string>
#include <iostream>

using namespace std;


class Enemy
{
public:
	Enemy();
	int health;
	int swing();
	int magic();
	int randnum();
	int strength;
	

};

class Boss:public Enemy
{
public:

	virtual int strengthUp();
};