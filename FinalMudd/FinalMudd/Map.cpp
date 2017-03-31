#include "Map.h"
#include <string>
#include <iostream>

using namespace std;


Map::Map() :
currentRoom(0)
{}


void Map::Move(string move)
{
	

	if (move == "GoNorth" && currentRoom->north != NULL && currentRoom->north->Locked == false)
	{
		currentRoom = currentRoom->north;

	}
	else if (move == "GoSouth" && currentRoom->south != NULL && currentRoom->south->Locked == false)
	{
		currentRoom = currentRoom->south;
	}
	else if (move == "GoEast" && currentRoom->east != NULL && currentRoom->east->Locked == false)
	{
		currentRoom = currentRoom->east;
	}
	else if (move == "GoWest" && currentRoom->west != NULL && currentRoom->west->Locked == false)
	{
		currentRoom = currentRoom->west;
	}
	else if (move == "GoUp" && currentRoom->up != NULL && currentRoom->up->Locked == false)
	{
		currentRoom = currentRoom->up;
	}
	else if (move == "GoDown" && currentRoom->down != NULL && currentRoom->down->Locked == false)
	{
		currentRoom = currentRoom->down;
	}
	else if (currentRoom->north->Locked == true)
	{
		cout << "Sorry this door is Locked you must find a Key before you can enter!" << endl;
		
	}
	else
	{
		cout << "Sorry you can't go that way" << endl;
	}
	
}


