#include "Game.h"

int main() {
	while (true) {
		int round = 0;
		Game g(round);
		if (g.getIsGameOver()) {
			cout << "��������" << endl;
		}
		round++;
	}
}