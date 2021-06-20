#include <iostream>
using namespace std;

#ifndef Card_h
#define Card_h
class Card {
private:
	int number, flower;
	bool isSend = false;
public:
	Card();
	Card(int newNumber, int newFlower);
	int getNumber() const;
	void setNumber(int newNumber);
	int getFlower() const;
	void setFlower(int newFlower);
	bool getIsSend();
	void setIsSend(bool newValue);
	string toString();
};
#endif