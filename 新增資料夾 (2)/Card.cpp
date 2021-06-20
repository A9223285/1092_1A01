#include "Card.h"
#include "Player.h"
#include <string>
#include <sstream>


Card::Card() {

}
Card::Card(int newNumber, int newFlower) {
	number = newNumber;
	flower = newFlower;

}
int Card::getNumber() const {
	return number;
}
void Card::setNumber(int newNumber) {
	number = newNumber;
}
int Card::getFlower() const {
	return flower;
}
void Card::setFlower(int newFlower) {
	flower = newFlower;
}
bool Card::getIsSend() {
	return isSend;
}
void Card::setIsSend(bool newValue) {
	isSend = newValue;
}
string Card::toString(){
	stringstream ss;
	//cout << endl;
	switch (flower) {
	case 0:
		ss << "梅花";
		break;
	case 1:
		ss << "方塊";
		break;
	case 2:
		ss << "紅心";
		break;
	case 3:
		ss << "黑桃";
		break;
	default:
		cout << "Error " << endl;
		break;
	}
	ss << number + 1;
	return ss.str();
}