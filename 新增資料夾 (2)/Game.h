#include "Card.h"
#include "Player.h"
#include "PublicCards.h"
#include <ctime>

#ifndef Game_h
#define Game_h
class Game {
private:
	Player player1;
	Player player2;
	PublicCards publicCards;
	Card cards[52];
	Card gameCards[5];
	bool isGameOver;
	
public:
	Game(int round);
	void playCardsForGameRound1();
	void playCardForPlayer(int index);
	bool getIsGameOver();
	void setIsGameOver(bool newValue);
	void cardsInIt();
};
#endif