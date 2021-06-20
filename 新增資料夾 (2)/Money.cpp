#include "Money.h"
Money::Money() {

}
Money::Money(int newMoney) {
	amount = newMoney;
}
int Money::getAmount() const {
	return amount;
}
void Money::setAmount(int newAmount) {
	amount = newAmount;
}
void Money::moneyPrint() {
	cout << getAmount() << endl;
}
