#include "property.h"
#include <string>
#include <iostream>
using namespace std;
const int SizeofMap = 5;


Property::Property() {
		name = "Unnamed";
		int cost = 100;
		color = "White";
		int owner = 99;
		int rentincrease = 50;
		int housecost = 50;
		rent = 0;
		housenumber = 0;
};

Property::Property(string inname, int incost, int inrent, string incolor) {
	name = inname;
	cost = incost;
	rentincrease = inrent;
	rent = 0;
	color = incolor;
	owner = 99;
	housecost = 50;
	housenumber = 0;
};

void Property::AddHouse() {
	Property::housenumber = Property::housenumber + 1;
};

Property CreateStart() {
	return Property("Start", 0, 0, "White");
};

Property CreateStormwind() {
	return Property("Stormwind", 150, 60, "Blue");
};

Property CreateGoldshire() {
	return Property("Goldshire", 160, 65, "Blue");
};

Property CreateNorthshire() {
	return Property("Northshire", 140, 40, "Blue");
};

void CreateProperties(Property PropArray[]) {
	
	PropArray[0] = CreateStart();
	PropArray[1] = CreateStormwind();
	PropArray[2] = CreateGoldshire();
	PropArray[3] = CreateNorthshire();
	PropArray[4] = Property();

	
};
void PrintPropertyNames(Property PropertyArray[]) {
	for (int i = 0; i < SizeofMap; i++) {
		string temp;
		temp = PropertyArray[i].name;
		int temp2;
		temp2 = PropertyArray[i].owner;
		cout << "\n Property name " << temp << "\n";
		cout << "Property owned by Player " << temp2 << "\n";
	};
};

	