#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }


enum class currency{dollars=0, sterling, rouble 
};

class Money {
public:
	Money(int cents, currency c)
		:amount{ cents }, curr{ c } {}

	double get_amount();
	void add(int dollars) { amount += dollars * 100; };
	void subtract(int dollars) { amount -= dollars * 100; };
	currency get_currency() { return curr; }
private:
	long int amount{ 1023 }; // stored as cents
	currency curr;
};

double Money::get_amount() {
	if (curr == currency::dollars)
		return (double)amount / 100;  // casts the int into a double to display as $ and cents
	else if (curr == currency::sterling)
		return (double)(amount / 100) * 0.8;
	else if (curr == currency::rouble)
		return (double)(amount / 100) * 57.76;
}

ostream& operator<<(ostream& os, Money& m) {
	if (m.get_currency() == currency::dollars)
		return os << "$" << m.get_amount();
	else if (m.get_currency() == currency::sterling)
		return os << "£" << m.get_amount();
	else if (m.get_currency() == currency::rouble)
		return os << "R" << m.get_amount();

}


int main() {
	Money c = Money(50000, currency::sterling);
	cout << "Charles has " << c << endl;
	c.subtract(5);
	cout << "After taking $5, Charles has " << c << endl;
	c.add(5);
	cout << "After taking $5, Charles has " << c << " again." << endl;
	char ch(36);
	int s(ch);
	cout << "pound: " << s;
	return 1;
}