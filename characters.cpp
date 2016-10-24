#include "characters.h"
#include <string>
const int SizeofMap = 5;
const int PassGoAmount = 200;

Character::Character() {
	location = 0;
	currentMoney = 500;
	propertyDiscount = 0;
	race = "none";
};

void Character::move(int steps) {
	if (Character::location + steps < SizeofMap) {
		Character::location = Character::location + steps;
	}
	else {
			int temp = abs(Character::location - (SizeofMap));
			int tempsteps = abs(steps - temp);
			Character::AddMoney(PassGoAmount);
			Character::location = 0;
			Character::move(tempsteps);
			
	}
};

void Character::RemoveMoney(int amount) {
	Character::currentMoney = Character::currentMoney - amount;
};

void Character::AddMoney(int amount) {
	Character::currentMoney = Character::currentMoney + amount;
};

string Character::getRace() {
	return(Character::race);
};

Human::Human() {
	Character::race = "Human";
	Character::currentMoney = 800;
};

NightElf::NightElf() {
	Character::race = "NightElf";
	Character::currentMoney = 700;
};

Dwarf::Dwarf() {
	Character::race = "Dwarf";
	Character::currentMoney = 1000;
};

Gnome::Gnome() {
	Character::race = "Gnome";
	Character::currentMoney = 900;
};