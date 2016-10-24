#include <string>
using namespace std;

class Property {
	public:
	Property();
	Property(string inname, int incost, int inrent, string incolor);
	void addRent(int amount);
	int owner;
	int cost;
	int rent;
	string color;
	string name;
};
void PrintPropertyNames(Property[]);

void CreateProperties(Property[]);

void BuyProperty(int loc);

Property CreateStormwind();

Property CreateGoldshire();

Property CreateNorthshire();