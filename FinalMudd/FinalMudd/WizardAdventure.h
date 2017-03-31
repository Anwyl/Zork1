#include <string>
#include <iostream>
#include "Map.h"



using namespace std;

class WizardAdventure
{
public:
	
	WizardAdventure();
	Map myMap;
	bool isGameOver;
	void startGame();
	void CombatSeq();
	string GetInput;
	void GameOver();
	void GameComplete();
	void BossScene();
	



};