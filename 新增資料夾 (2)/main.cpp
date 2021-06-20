#include "Game.h"

int main() {
	while (true) {
		int round = 0;
		Game g(round);
		if (g.getIsGameOver()) {
			cout << "¥»§½µ²§ô" << endl;
		}
		round++;
	}
}