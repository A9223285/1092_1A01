#include "Card.h"
#include "Money.h"
#include <string>
#include <sstream>
#ifndef Bet_h
#define Bet_h
class Bet {
private:
	Money money;
	int lastAmount;
public:
	Bet();
	Money getMoney() const;
	void betAction(int newMoney);
	int getLastAmount() const;
};
#endif