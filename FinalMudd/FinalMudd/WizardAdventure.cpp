#include "Wizardadventure.h"
#include "Enemy.h"
#include "Wizard.h"

#include <iostream>
#include <string>

using namespace std;

WizardAdventure::WizardAdventure()
{}


void WizardAdventure::startGame()
{

	Map myMap;
	

	cout << "You awaken to find yourself laying on the cold ground wondering how you ended back down on Mitarius.\n\n";
	cout << "The last thing you remember were the screams of the townspeople as the Necromancer made his way down the street.\n\n";
	cout << "You're King implored you to find some way to save the Imperial City and stop the Necromancer.\n\n";
	cout << "Just then the doors flew open as though they had been blown by a hurricane as the Necromancer entered.\n\n";
	cout << "It's from there that your memory of the whole ordeal becomes fuzzy.\n\n";
	cout << "You don't know how long you've been asleep, all you know is that you must return to the Cloud City above.\n\n";



	Room* Start = new Room("Vast open field below Valarthral. There isn't anything for miles but luckily your standing in the middle of a transporation circle.\n\n", "Field", 0);
	Room* CloudCity = new Room("You've arrive outside the gates of the ancient city in the sky Valarthral. It seems as though ages have passed since that fateful day. Moss has begun to grow on the gates of the once proud city in the sky", "South Gate", 1);
	Room* TownSquare = new Room("You walk into the townsquare shuddering as you take in the deafening silence all around.\n This city once beemd with life yet now seems as though any life it had was sucked away.\n", "Town Square\n\n", 2);
	Room* Alley = new Room("You arrive in the alleyway leading up to the Guards Quarters. Shops line the street with windows covered in dust from the years of neglect. You can hear faint sounds coming from deep within the shop. Maybe by some luck someone is alive!\n\n", "Alleyway", 3);
	Room* Shop = new Room("You walk into the shop hoping beyond hope that someone may be alive. You walk around noticing how weathered all of the items are, and wonder just how long you've been away, Suddenly from the shadows you hear an unhumanly screech as a figure jumps out at you!\n\n", "Imperial Arms Shop", 4);
	Room* Guardroom = new Room("You arrive in the home of the Imperial Guards. You yearn to know what happened here to your dear friends. You can see what looks to be an old note laying on the table.\n\n", "Guard Quarters", 4);
	Room* Basement = new Room("You begin the descent down the long dark stairs of the basement. You look around trying to find some clue as to what may have happened when again another figure comes out from shadows to attack!\n\n", "Basement", 5);
	Room* CastleYard = new Room("The vast yard leading up the Imperial castle of Valarthral\n\n", "Castle Yard", 6);
	Room* Castle = new Room("You stare at the yard in disbelief. The once revered castle Of Valarthral is now a mere shell of itself. Moss grows wildly along the walls and sections are beggining to crumbler under the weight of years of fierce battles.\n\n", "Main Floor\n\n", 7);
	Room* Hallway1 = new Room("Hallway leading the Kings Chambers", "Hallway\n\n", 8);
	Room* Hallway2 = new Room("Hallway leading the Kings Chambers", "Hallway2\n\n", 9);
	Room* Hallway3 = new Room("Hallway leading to the Royal Kitchen", "Hallway3\n\n", 10);
	Room* Hallway4 = new Room("Hallway leading to the Royal Kitchen", "Hallway4\n\n", 11);
	Room* KingsChamber = new Room(" You find yourself in the Bedroom for the King of Valarthral and His wife. You mourn wondering where your dear friends have gone. Out of the corner of your eye you see a glimmer of something.\n\n", "Kings Chambers", 12);
	Room* Kitchen = new Room("The royal kitchen for the castle. You spent many an hour here talking the days away the staff. They memories of this place warm your heart, unfortunately the memories are shortlived as another figure emerges upon you.", "Kitchen\n\n", 13);
	Room* Bedroom = new Room("You find yourself in your old bedroom. You yearn for the days of old when life was simple and your biggest worry was which foolish spell the King would wish to see. Now you are frantic trying to find your way inside the Throne Room praying you can save your friend.\n\n", "Bedroom", 14);
	Room* ThroneRoom = new Room("You've arrived in the throne room, and far accross the room you see him. It's the Necromancer lounging in the throne meant for the king. With an otherwordly yell you run towards the Necromancer for one final fight.\n\n", "Throne Room", 15);

	Start->up = CloudCity;
	CloudCity->north = TownSquare;
	TownSquare->south = CloudCity;
	TownSquare->east = Alley;
	TownSquare->north = CastleYard;
	Alley->west = TownSquare;
	Alley->north = Shop;
	Shop->south = Alley;
	Alley->east = Guardroom;
	Guardroom->west = Alley;
	Guardroom->down = Basement;
	Basement->up = Guardroom;
	CastleYard->south = TownSquare;
	CastleYard->north = Castle;
	Castle->south = CastleYard;
	Castle->west = Hallway1;
	Castle->east = Hallway3;
	Castle->north = ThroneRoom;
	Hallway1->east = Castle;
	Hallway1->west = Hallway2;
	Hallway2->east = Hallway1;
	Hallway2->north = KingsChamber;
	KingsChamber->south = Hallway2;
	Hallway3->west = Castle;
	Hallway3->east = Hallway4;
	Hallway4->west = Hallway3;
	Hallway4->north = Bedroom;
	Hallway4->south = Kitchen;
	Bedroom->south = Hallway4;
	Kitchen->north = Hallway4;
	
	
	Shop->Combat = true;
	Castle->Locked = true;
	ThroneRoom->Locked = true;
	Basement->Combat = true;
	Kitchen->Combat = true;
	Guardroom->roomItem = "Note";
	Basement->roomItem = "Key";
	KingsChamber->roomItem = "TabletShard";

	Room* beggining = Start;
	

	myMap.currentRoom = Start;
	isGameOver = false;

	cout << "Welcome to the world of Mitarious user!!! Here are some easy commands to move around!\n";
	cout << "Use the word Go followed by any direction, North, South, East, West, Up, Down to move around the map.\n";
	cout << "Use the word Grab whenever you wish to pick up an item. Any items grabbed will be instantly used.\n";
	cout << "When in battles you will be prompted to use different types of magic. Your options are Blizzard, Heal, Fireball, or Water.\n";
	cout << "Type in GetHelp to return to this panel if you ever get confused!.\n";
	cout << "Enjoy your adventuring!\n";


	while (!isGameOver)
	{

		
		
		myMap.currentRoom->GetDesc();

		if (myMap.currentRoom->GetName() == "Throne Room")
		{
			BossScene();
			break;
		}
		if (myMap.currentRoom->Combat == true)
		{
			CombatSeq();

			if (isGameOver == true)
			{
				break;
			}
		}
		if (myMap.currentRoom->GetName() == "Basement")
		{
			cout << "Unsure of what just happend you rush to the side of the creature you just slew.\n";
			cout << "You yell as you get closer realizing who exactly it is laying on the ground.\n";
			cout << "Your oldest friend Magnus is laying there raggedly breathing holding on for dear life.\n";
			cout << "He smiles at you and just barely manages to whisper. ";
				cout << " 'I Knew you would come for us my friend. Quickly take this key to unlock the castle your the only one who can save us now.'\n";
				cout << "Tears stream down you eyes as your friend lays lifeless in your arms. It's at that moment that you know no matter the cost you must defeat the Necromancer.";
				Basement->Combat = false;
		}

		myMap.currentRoom->PrintExits();
		

		cout << "What would you like to do? ";
		cin >> GetInput;


		if (GetInput == "GoNorth" || GetInput == "GoSouth" || GetInput == "GoEast" || GetInput == "GoWest" || GetInput == "GoUp" || GetInput == "GoDown")

		{
			myMap.Move(GetInput);
		}
		else if (GetInput == "Grab")
		{
			cout << "What would you like to grab?";
			cin >> GetInput;

			if (GetInput == "Note" && myMap.currentRoom->roomItem == "Note")
			{
				cout << "It has been 400 years since the Necromancer has taken over control of the city. Few remain who are strong enough to stand up to the power of this vile creature.\n";
				cout << "I still remain hopefull that my dear friend Jonathan, The Grand Mage Advisor, returns to us one day. I fear he is the only one who can save us from this aweful nightmare.\n";
				cout << "Signed -- Royal Guard to the King Magnus Year 1834ev.";
			}
			else if (GetInput == "Key" && myMap.currentRoom->roomItem == "Key")
			{
				cout << "You've found the royal guardsmen key to unlock the throneroom. ";
				Castle->Locked = false;
				
			}
			else if (GetInput == "TabletShard" && myMap.currentRoom->roomItem == "TabletShard")
			{
				cout << "You grab the magical orb needed to enter into the Throne Room. You hear a rumble as the door slides open!";
				ThroneRoom->Locked = false;
			}

		}
		else if (GetInput == "GetHelp")
		{
			cout << "Welcome to the world of Mitarious user!!! Here are some easy commands to move around!\n";
			cout << "Use the word Go followed by any direction, North, South, East, West, Up, Down to move around the map.\n";
			cout << "Use the word Grab whenever you wish to pick up an item. Any items grabbed will be instantly used.\n";
			cout << "When in battles you will be prompted to use different types of magic. Your options are Blizzard, Heal, Fireball, or Water.\n";
			cout << "Type in GetHelp to return to this panel if you ever get confused!.\n";
			cout << "Enjoy your adventuring!\n";
		}




	}
}

void WizardAdventure::CombatSeq()
{
	cout << "Prepare to enter Combat Sequence\n\n" << endl;

	Enemy Possessed;
	Wizard Player;

	int turn = 0;
	int dice = 0;
	int attack = 0;


	while (true)
	{
		if (Player.health < 0 || Possessed.health < 0)
			break;
		cout << "You have " << Player.health << " health remaining!" << endl;
		cout << "The townsperson has " << Possessed.health << " health remaining!" << endl;

		

		if (turn == 0)
		{
			cout << "Prepare your attack which spell would you like to use?";
			cin >> GetInput;

			dice = Player.randnum();

			if (GetInput == "Blizzard")
			{
				if (dice >= 18)
				{
					attack = Player.blizzard() + Player.intellect;
					cout << "Your blizzard does a crit for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;

				}
				else
				{
					attack = Player.blizzard();
					cout << "You attack with Blizzard for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;
				}

				turn = 1;

			}
			else if (GetInput == "Fireball")
			{
				if (dice >= 18)
				{
					attack = Player.fireball() + Player.intellect;
					cout << "Your fireball does a crit for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;
				}
				else
				{
					attack = Player.fireball();
					cout << "You attack with Fireball for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;
				}

				turn = 1;
			}
			else if (GetInput == "Water")
			{
				if (dice >= 18)
				{
					attack = Player.water() + Player.intellect;
					cout << "Your Water does a crit for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;
				}
				else
				{
					attack = Player.water();
					cout << "You attack with Water for " << attack << " damage!\n\n";
					Possessed.health = Possessed.health - attack;
				}

				turn = 1;
			}

			else if (GetInput == "Heal")
			{
				if (dice >= 18)
				{
					attack = Player.heal() + Player.intellect;
					cout << "Your Heal does a crit for " << attack << " health!\n\n";
					Player.health = Player.health + attack;
				}
				else
				{
					attack = Player.heal();
					cout << "You Heal for " << attack << " health!\n\n";
					Player.health = Player.health + attack;
				}

				turn = 1;
			}
		}


			else
			{
				dice = Possessed.randnum();
				cout << "The Possessed Townsperson prepares to attack!\n\n";

				if (dice < 17)
				{
					attack = Possessed.swing();
					cout << "The Townsperson swings at you for " << attack << " damage!\n\n";
					Player.health = Player.health - attack;
				}
				else
				{
					attack = Possessed.magic() + Possessed.strength;
					cout << "Someone is using the Townsperson to attack with magic!\n";
					cout << "They do " << attack << " damage!\n\n";
					Player.health = Player.health - attack;
				}
				turn = 0;
			}
	}

	if (Player.health <= 0)
	{
		GameComplete();
	}

	}



	void WizardAdventure::BossScene()
	{
		cout << "Prepare for boss combat sequence!\n";
		cout << "For every round the boss goes undefeated his strength increases so good luck!\n";

		Boss Necromancer;
		Wizard Player;

		int turn = 0;
		int dice = 0;
		int attack = 0;
		Necromancer.health = 300;


		while (true)
		{
			if (Player.health < 0 || Necromancer.health < 0)
				break;

			cout << "You have " << Player.health << " health remaining!" << endl;
			cout << "The Necromancer has " << Necromancer.health << " health remaining!" << endl;

			
			

			if (turn == 0)
			{
				cout << "Prepare your attack which spell would you like to use?";
				cin >> GetInput;

				dice = Player.randnum();

				if (GetInput == "Blizzard")
				{
					if (dice >= 18)
					{
						attack = Player.blizzard() + Player.intellect;
						cout << "Your blizzard does a crit for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;

					}
					else
					{
						attack = Player.blizzard();
						cout << "You attack with Blizzard for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;
					}

					turn = 1;

				}
				else if (GetInput == "Fireball")
				{
					if (dice >= 18)
					{
						attack = Player.fireball() + Player.intellect;
						cout << "Your fireball does a crit for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;
					}
					else
					{
						attack = Player.fireball();
						cout << "You attack with Fireball for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;
					}

					turn = 1;
				}
				else if (GetInput == "Water")
				{
					if (dice >= 18)
					{
						attack = Player.water() + Player.intellect;
						cout << "Your Water does a crit for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;
					}
					else
					{
						attack = Player.water();
						cout << "You attack with Water for " << attack << " damage!\n\n";
						Necromancer.health = Necromancer.health - attack;
					}

					turn = 1;
				}

				else if (GetInput == "Heal")
				{
					if (dice >= 18)
					{
						attack = Player.heal() + Player.intellect;
						cout << "Your Heal does a crit for " << attack << " health!\n\n";
						Player.health = Player.health + attack;
					}
					else
					{
						attack = Player.heal();
						cout << "You Heal for " << attack << " health!\n\n";
						Player.health = Player.health + attack;
					}

					turn = 1;
				}
			}


			else
			{
				dice = Necromancer.randnum();
				cout << "The Necromancer prepares to attack!\n\n";

				if (dice < 10)
				{
					attack = Necromancer.swing();
					cout << "The Necomancer swings at you for " << attack << " damage!\n\n";
					Player.health = Player.health - attack;
					Necromancer.strengthUp();
					cout << "Necromancers strength has increased to " << Necromancer.strength << ".";
				}
				else
				{
					attack = Necromancer.magic() + Necromancer.strength;
					cout << "The Necromancer fires magic at you for " << attack << " damage!\n\n";
					Player.health = Player.health - attack;
					Necromancer.strengthUp();
					cout << "Necromancers strength has increased to " << Necromancer.strength << ".\n";
				}
				turn = 0;
			}
		}
		
		if (Player.health <= 0)
		{
			GameOver();
		}
		else
		{
			GameComplete();
		}
	}





	void WizardAdventure::GameOver()
	{
		cout << "You fall to the ground as the laugher of the necromancer fills your ears.\n";
		cout << "With you're dying thoughts you thinks back to the adventures that you had with your loved ones, and pray another hero comes to save your city.\n";
		isGameOver = true;
	}


	void WizardAdventure::GameComplete()
	{
		cout << "With one final burst of magic the Necromancer falls to the ground defeated.\n";
		cout << "You quickly run towards him to ensure the final blow and restore peace to you land.\n";
		cout << "With a cry fueled by the suffering of your land you unleash the ultimate spell know to your people. Obliterate.\n";
		cout << "With a shout mixed with tears and sorrow you begin the encantation to wipe the Necromancer from existence.\n";
		cout << "You chanel all you fury and rage into what may become the final spell you will ever cast.\n";
		cout << "As the magic takes effect you hear the blood curtling scream of the Necromancer as everything that he ever was or would be was no more.";
		cout << "With one final sigh you pass out the toll of such powerful magic being almost to much even for you.";
		cout << "You close your eyes knowing that you've done it. You've saved your beloved city in the sky frm the Evil of the Necromancer.\n";
		cout << "2 WEEKS LATERS.\n\n";
		cout << "You awaken with a start frantically wondering what happened to you and where the Necromancer was.\n";
		cout << "As you begin to look around your beside your eyes fill with tears as you notice all your friends and family gathered around you.\n";
		cout << "At the sight of you finally awake they all begin to cheer and shout your name, a name that will forever be sang of to your people.\n\n\n";
		cout << "Congratulations Adventure on succesfully completing your story. Until Next Time!";
		isGameOver = true;
	}