#include "PublicCards.h"

PublicCards::PublicCards() {

}
void PublicCards::setCard(int index, Card card) {
	cards[index] = card;
}
Card PublicCards::getCard(int index) {
	return cards[index];
}
int PublicCards::getCardsAmount() const {
	return cardsAmount;
}
void PublicCards::setCardsAmount(int newCardsAmount) {
	cardsAmount = newCardsAmount;
}