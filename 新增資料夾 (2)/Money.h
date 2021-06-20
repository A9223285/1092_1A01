#include <iostream>
using namespace std;

#ifndef Money_h
#define Money_h
class Money {
private:
	int amount;
public:
	Money();
	Money(int newMoney);
	void moneyPrint();
	int getAmount() const;
	void setAmount(int newAmount);
};
#endif