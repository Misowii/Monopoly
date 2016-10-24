#include "characters.h"
#include <string>
const int SizeofMap = 40;

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
			Character::location = Character::location - steps;
	}
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