#include "characters.h"
#include <string>
static int SizeofMap = 25;

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
};

NightElf::NightElf() {
	Character::race = "NightElf";
};

Dwarf::Dwarf() {
	Character::race = "Dwarf";
};

Gnome::Gnome() {
	Character::race = "Gnome";
};