#include <string>
using namespace std;


class Character {
	public:
		int location;
		int currentMoney;
		int propertyDiscount;
		void move(int steps);
		string race;
		Character();
		string getRace();
		void RemoveMoney(int amount);
		void AddMoney(int amount);

};

class Human : public Character {
	public:
		string race;
		Human();
};

class NightElf : public Character {
	public:
		string race;
		NightElf();
};

class Dwarf : public Character {
	public:
		string race;
		Dwarf();
};

class Gnome : public Character {
	public:
		string race;
		Gnome();
};