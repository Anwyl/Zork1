#include <iostream>
#include "WizardAdventure.h"
#include <string>



using namespace std;



int main()
{
	string answer;
	WizardAdventure Adventure1;





	cout << "Welcome to the world of Mitarius! Prepare yourself to go on a grand adventure to save the world.\n";
	cout << "Your mission is to save the great elf city in the sky from the evil Necromancer who terrorizes their people.\n";
	cout << "Are you ready to save the worl? Yes or No?";
	cin >> answer;






	if (answer == "Yes")
	{
		Adventure1.startGame();
	}
	else
	{
		cout << "Welcome to the world of Mitarius! Prepare yourself to go on a grand adventure to save the world.\n";
		cout << "Your mission is to save the great elf city in the sky from the evil Necromancer who terrorizes their people.\n";
		cout << "Are you ready to save the worl? Yes or No?";
		cin >> answer;
	}


	system("pause");
	return 0;

}