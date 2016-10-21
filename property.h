#include <string>
using namespace std;

class Property {
	public:
	Property();
	void addRent(int amount);
	int owner;
	int location;
	int cost;
	int rent;
	string color;
	string name;
};