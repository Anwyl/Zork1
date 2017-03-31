#include <iostream>
#include <string>

using namespace std;

class Room
{
public:

	Room(string desc, string name, int value);
	int roomValue;
	Room *north, *south, *east, *west, *up, *down;
	string roomItem;
	string roomName;
	string roomDesc;	
	string GetName();
	void GetDesc();	
	void PrintExits();
	bool Combat = false;
	bool Locked = false;

	
};
