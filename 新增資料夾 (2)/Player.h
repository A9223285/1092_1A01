#include "Card.h"
#include "Money.h"
#include "Bet.h"
#include <string>
#include <sstream>
#ifndef Player_h
#define Player_h
class Player {
private:
	string name;
	Money money = 200000;
	Card cards[2];
	int cardsAmount;
	Bet bet;
	void betAction(int amount);
	int index;
public:
	Player();
	int getCardsAmount() const;
	void setCardsAmount(int newCardsAmount);
	string getName() const;
	void setName(string newName);
	Money getMoney() const;
	void setMoney(Money newMoney);
	void setCard(int index, Card card);
	Card getCard(int index);
	Bet getBet() const;
	void bottomBetAction();
	void playerBet(int sum, int sum2);
	void setGameIndex(int gameIndex);
	int betLimitAmount(int i) const;
	int getBetAmount() const;
	void betLimitAmountPrint(int i);
};
#endif