#include "Player.h"
#include "Card.h"
#include "Money.h"
#include "Bet.h"
#include <iostream>
using namespace std;
void Player::setGameIndex(int gameIndex) {
	index = gameIndex;
}
Player::Player() {
	cout << "�п�J�W�r: ";
	cin >> name;
}
string Player::getName() const {
	return name;
}
void Player::setName(string newName) {
	name = newName;
}
Money Player::getMoney() const {
	return money;
}
void Player::setMoney(Money newMoney) {
	money = newMoney;
}
void Player::setCard(int index, Card card) {
	cards[index] = card;
}
Card Player::getCard(int index) {
	return cards[index];
}
int Player::getCardsAmount() const {
	return cardsAmount;
}
void Player::setCardsAmount(int newCardsAmount) {
	cardsAmount = newCardsAmount;
}
Bet Player::getBet() const {
	return bet;
}

void Player::betAction(int amount) {
	getBet().betAction(amount);
}
int Player::getBetAmount() const {
	return getBet().getMoney().getAmount();
}
int Player::betLimitAmount(int i) const {
	srand(time(0));
	int index1 = rand() % 100;
	int index = rand() % 3000;
	int index2 = rand() % 4000;
	if (i == 0) {
		return getMoney().getAmount();
	}
	else if (index1 > 50) {
		return getMoney().getAmount() - index;
	}
	else {
		return getMoney().getAmount() - index2;
	}
}
void Player::bottomBetAction() {
	if (index == 0) {
		betAction(25);
	}
	else {
		betAction(50);
	}
}
void Player::playerBet(int sum, int sum2) {
	int betAmount;
	while (true) {
		cin >> betAmount;
			if (betAmount == 0) {
				betAction(betAmount);
				cout << getName() << "��P" << endl;
				break;
			}
			if (betAmount == bet.getLastAmount()) {
				betAction(betAmount);
				cout << getName() << "��`";
				break;
			}
			if(betAmount > bet.getLastAmount()){
				betAction(betAmount);
				cout << getName() << "�U�`�F" << betAmount << "���w�X" << endl;
				int sum = 0;
				sum += betAmount;
				break;
			}
		else {
			cout << "�Э��s��J: ";
		}
	}
}
void Player::betLimitAmountPrint(int i) {
	cout << "���w�X�q: " << betLimitAmount(i) << endl;
}