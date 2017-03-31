#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(string desc, string name, int value):
north(NULL), south(NULL), east(NULL), west(NULL), up(NULL), down(NULL)
{
	roomDesc = desc;
	roomName = name;
	roomValue = value;
}



string Room::GetName()
{
	return roomName;
	
}

void Room::GetDesc()
{
	cout << roomDesc << endl;
}

void Room::PrintExits()
{
	if (north != NULL)
	{
		cout << "To the North you see the " << north->GetName() << endl;
		
		if (east != NULL)
		{
			cout << "To the East you see the " << east->GetName() << endl;
			
			if (south != NULL)
			{
				cout << "To the South you see the " << south->GetName() << endl;
				
				if (west != NULL)
				{
					cout << "To the West you see the " << west->GetName() << endl;

					if (up != NULL)
					{
						cout << "Above you, you can see the " << up->GetName() << endl;

						if (down != NULL)
						{
							cout << "Below you can hear noises coming from the " << down->GetName() << endl;
						}
					}
				}
			}
		}
	}
}