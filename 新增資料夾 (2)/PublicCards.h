#include "Card.h"

#ifndef PublicCards_h
#define PublicCards_h
class PublicCards {
private:
	Card cards[5];
	int cardsAmount;
public:
	PublicCards();
	void setCard(int index, Card card);
	Card getCard(int index);
	int getCardsAmount() const;
	void setCardsAmount(int newCardsAmount);
};
#endif