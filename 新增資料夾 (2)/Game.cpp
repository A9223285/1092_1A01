#include "Game.h"
#include "Card.h"
#include "Money.h"
#include "Player.h"
#include <ctime>
#include <cstdlib>

int CheckCard(int card[5])
{
	int flush = 0, straight = 0, four_of_a_kind = 0, three_of_a_king = 0, i;
	int pair = 0, count = 0, a_straight = 0, start, end;
	int kind[4] = { 0 }, scard[13] = { 0 };
	for (i = 0; i < 5; i++)
	{
		kind[card[i] / 13]++;
		scard[card[i] % 13]++;
	}
	for (i = 0; i < 4; i++)
	{
		if (kind[i] == 5)
			flush = 1;
	}
	for (i = 0; i < 13; i++)
	{
		if (scard[i] != 0)
		{
			end = i;
			if (scard[i] == 4)
				four_of_a_kind = 1;
			else if (scard[i] == 3)
				three_of_a_king = 1;
			else if (scard[i] == 2)
				pair++;
			else if (scard[i] == 1)
				count++;
		}
	}

	if (count == 5)
	{
		if (scard[0] && scard[9] && scard[10] && scard[11] && scard[12])
			a_straight = 1;
		else

		{
			start = end - count + 1;
			for (i = start; i <= end; i++)
				if (scard[i])
					count--;
			if (count == 0)
				straight = 1;
		}
	}

	if (a_straight && flush)
		return 9;
	else if (straight && flush)
		return 8;
	else if (four_of_a_kind)
		return 7;
	else if (three_of_a_king && pair)
		return 6;
	else if (flush)
		return 5;
	else if (straight || a_straight)
		return 4;
	else if (three_of_a_king)
		return 3;
	else
		return pair;
}
void Game::cardsInIt() {
	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[index].setFlower(i);
			cards[index].setNumber(j);
			index++;
		}
	}
}
void Game::playCardForPlayer(int index) {
	for (int i = 0; i < 2; i++) {
		while (true) {
			srand(time(0));
			int cardindex = rand() % 52;
			Card& c = cards[cardindex];
			if (c.getIsSend() == true) {

			}
			else {
				c.setIsSend(true);
				if (index == 0) {
					player1.setCard(i, c);
					player1.setCardsAmount(player1.getCardsAmount() + 2);
				}
				else {
					player2.setCard(i, c);
					player2.setCardsAmount(player2.getCardsAmount() + 2);
				}
				break;
			}
		}
	}
}
void Game::playCardsForGameRound1() {
	for (int i = 0; i < 5; i++) {
		while (true) {
			int cardindex = rand() % 52;
			Card& c = cards[cardindex];
			if (c.getIsSend()) {

			}
			else {
				publicCards.setCard(i, c);
				publicCards.setCardsAmount(publicCards.getCardsAmount() + 5);
				c.setIsSend(true);
				break;
			}

		}
	}
}
bool Game::getIsGameOver() {
	return isGameOver;
}
void Game::setIsGameOver(bool newValue) {
	isGameOver = newValue;
}
Game::Game(int round) {
	int i = 0;
	int sum = rand() % 20000;
	int sum2 = 0;
	int player1index = round % 2;
	int player2index = 0;
	if (player1index == 0) {
		player2index = 1;
	}
	else {
		player2index = 0;
	}
	player1.setGameIndex(player1index);
	player2.setGameIndex(player2index);
	player1.bottomBetAction();
	player2.bottomBetAction();
	cardsInIt();

	playCardForPlayer(0);
	playCardForPlayer(1);
	playCardsForGameRound1();
	cout << player1.getName();
	player1.betLimitAmountPrint(i);
	cout << player2.getName();
	player2.betLimitAmountPrint(i);
	cout << player1.getName() << "的底牌: " << player1.getCard(0).toString() << "," <<
		player1.getCard(1).toString() << endl;
	cout << player2.getName() << "的底牌: " << player2.getCard(0).toString() << "," <<
		player2.getCard(1).toString() << endl;
	cout << player1.getName() << "請下注: ";
	player1.playerBet(sum, sum2);
	cout << player2.getName() << "請下注: ";
	player2.playerBet(sum2, sum2);

	if (player1.getBet().getLastAmount() <= player2.getBet().getLastAmount()) {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				cout << "公共牌: " << publicCards.getCard(i).toString();
			}
			else {
				cout << "," << publicCards.getCard(i).toString();
			}
		}
		cout << endl;
	}
	cout << player1.getName() << "請下注: ";
	player1.playerBet(sum, sum2);
	cout << player2.getName() << "請下注: ";
	player2.playerBet(sum, sum2);
	if (player1.getBet().getLastAmount() <= player2.getBet().getLastAmount()) {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				cout << "公共牌: " << publicCards.getCard(i).toString();
			}
			else {
				cout << "," << publicCards.getCard(i).toString();
			}
		}
		cout << endl;
	}
	cout << player1.getName() << "請下注: ";
	player1.playerBet(sum, sum2);
	cout << player2.getName() << "請下注: ";
	player2.playerBet(sum, sum2);
	if (player1.getBet().getLastAmount() <= player2.getBet().getLastAmount()) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				cout << "公共牌: " << publicCards.getCard(i).toString();
			}
			else {
				cout << "," << publicCards.getCard(i).toString();
			}
		}
		srand(time(0));
		int index = rand() % 100;
		if (index < 50) {
			cout << endl;
			cout << player1.getName() << "獲勝贏得" << sum << "塊籌碼";
		}
		else {
			cout << endl;
			cout << player2.getName() << "獲勝贏得" << sum << "塊籌碼";
		}
		cout << endl;
	}
	i++;
	setIsGameOver(true);
}




