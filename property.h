#include <string>
using namespace std;

class Property {
	public:
	Property();
	Property(string inname, int incost, int inrent, string incolor);

	int owner;
	int cost;
	int rentincrease;
	int rent;
	int housecost;
	int housenumber;
	string color;
	string name;
	
	void AddHouse();
	void addRent(int amount);
};
void PrintPropertyNames(Property[]);

void CreateProperties(Property[]);

void BuyProperty(int loc);

Property CreateStormwind();

Property CreateGoldshire();

Property CreateNorthshire();