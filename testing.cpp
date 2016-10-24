#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "characters.h"
#include "property.h"

using namespace std;
int NumberofPlayers;
int CurrentPlayer;
const int SizeofMap = 5;

class Dice {
	int die1, die2;
	public:
		Dice () {
			die1 = 1;
			die2 = 1;
		};
		void roll () { 
			die1 = (rand() % 6 + 1);
			die2 = (rand() % 6 + 1);
			return;
		};
		int showDice() {
			return (die1,die2);
		};
		void printDice() {
			cout << die1 << "," << die2 << "\n";
			return;
		};
		int showDie1 () {
			return die1;
		};
		int showDie2 () {
			return die2;
		};
		int addDice() {
			return die1 + die2;
		};
};

Dice dice;

class Player {

	public:
		string name;
		Character selectedRace;
		Player (string inputname, Character inputrace) {
			name = inputname;
			selectedRace = inputrace;
		};
		Player () {
			name = "blank";
		};
};

void changePlayer() {
	if (CurrentPlayer < NumberofPlayers - 1) {
		CurrentPlayer = CurrentPlayer + 1;
	}
	else {
		CurrentPlayer = 0;
	}
};

Player *PlayerArray;

Property PropertyArray[SizeofMap];


Character DetermineCharacter(string inputname) {
	if (inputname == "Dwarf")
		return Dwarf();
	else if (inputname == "Human")
		return Human();
	else if (inputname == "NightElf")
		return NightElf();
	else if (inputname == "Gnome")
		return Gnome();
	/*else if (inputname == "Orc")
		return Orc();
	else if (inputname == "Undead")
		return Undead();
	else if (inputname == "Tauren")
		return Tauren();
	else if (inputname == "Troll")
		return Troll();*/
};

void CreatePlayer(string nam, Character rac, int playernumber) {
	PlayerArray[playernumber] = Player(nam, rac);
};	

void NewGame() {
	cout << "How many players? \n";
	int numplayers;
	cin >> numplayers;
	NumberofPlayers = numplayers;
	cout << "Number of players is " << numplayers << "\n";
	PlayerArray = new Player[numplayers];
	int i, n;
	for (n = 0; n < numplayers; n++) {
		i = n + 1;
		string tempname;
		string charrace;
		cout << "Player " << n + 1 << " desired character name?\n";
		cin >> tempname;
		cout << "Desired character race?\n";
		cin >> charrace;
		cout << "Player " << n + 1 << " name is " << tempname << "\n";
		cout << "Player " << n + 1 << " race is " << charrace << "\n";
		CreatePlayer(tempname, DetermineCharacter(charrace), n);
		
	};
	CurrentPlayer = 0;
	cout << "\nGame is Initialized.\n";
};

void BuyProperty(Player curPlayer){
	int loc = curPlayer.selectedRace.location;
	int playermoney = curPlayer.selectedRace.currentMoney;
	int cost = PropertyArray[loc].cost;
	if (PropertyArray[loc].owner > NumberofPlayers){
		if (playermoney < cost) {
			cout << "\nPlayer does not have enough money!\n";
		}
		else {
			curPlayer.selectedRace.currentMoney = (playermoney - cost);
			PropertyArray[loc].owner = CurrentPlayer;
			cout << "\nProperty now owned by Player " << CurrentPlayer << "\n";
		};
	}
	else {
		cout << "\nProperty already owned by Player " << PropertyArray[loc].owner << "!\n";
		cout << "Please use BuyFrom command\n";
	};
};

void DisplayPlayers() {
	for ( int n = 0; n < NumberofPlayers; n++) {
		Player tempplayer = PlayerArray[n];
		cout << "\n\nPlayer " << n+1 << " name is " << tempplayer.name << "\n";
		cout << "Race is " << tempplayer.selectedRace.getRace() << "\n";
	};
};
bool RollFlag = true;

bool NextCommand() {
	 cout << "\nInput game command.\n";
	string inputcommand;
	cin >> inputcommand;
	
	if (inputcommand == "Roll"){
		if (RollFlag){
			dice.roll();
			dice.printDice();
			int temp = dice.addDice();
			cout << temp << "\n";
			PlayerArray[CurrentPlayer].selectedRace.move(temp);
			cout << "\n\nCurrent Location\n" << PlayerArray[CurrentPlayer].selectedRace.location << "\n";
			RollFlag = false;
			return true;
		}
		else {
			cout << "Cannot Roll Again This Turn\n";
			return true;
		}
	}
	else if (inputcommand == "Location"){
		int temploc = PlayerArray[CurrentPlayer].selectedRace.location;
		cout << "\n\nCurrent Location\n" << temploc << "\n";
		cout << "Current location is " << PropertyArray[temploc].name << "\n";
		cout << "Current cost to buy property is " << PropertyArray[temploc].cost << "\n";
		cout << "Property owned by Player " << PropertyArray[temploc].owner << "\n";
		return true;
	}
	else if (inputcommand == "NewGame") {
		NewGame();
		return true;
	}
	else if (inputcommand == "CheckMoney"){
		cout << "\nCurrent Balance\n" << PlayerArray[CurrentPlayer].selectedRace.currentMoney << "\n";
		return true;
	}
	else if (inputcommand == "BuyProperty") {
		if (CurrentPlayer.selectedRace.location == 0){
			cout << "Cannot buy start location" << "\n";
			return true;
		}
		else{
		BuyProperty(PlayerArray[CurrentPlayer]);
		return true;
		}
	}
	else if (inputcommand == "BuyHouse") {
		return true;
	}
	else if (inputcommand == "Quit")
		return false;
	else if (inputcommand == "EndTurn") {
		changePlayer();
		RollFlag = true;
		return true;
	}
	else {
		cout << "Not a valid command\n";
		return true;
	}
		
};

int main() {
	
	srand(time(0));

	/*DisplayPlayers();*/
	bool Status = true;
	CreateProperties(PropertyArray);
	while (Status == true) {
		cout << "Current Player is " << CurrentPlayer << "\n";
		Status = NextCommand();
	};	
	
	return 0;
}