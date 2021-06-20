#include "Card.h"
#include "Money.h"
#include "Bet.h"
#include <string>
#include <sstream>

Money Bet::getMoney() const {
	return money;
}
void Bet::betAction(int newMoney)
{
	money.setAmount(money.getAmount() + newMoney);
	lastAmount = newMoney;
}
int Bet::getLastAmount() const {
	return lastAmount;
}
Bet::Bet() {

}