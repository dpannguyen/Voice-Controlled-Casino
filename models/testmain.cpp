#include "Card.h"
#include "Input.h"
#include "Output.h"
#include "Deck.h"
#include "Hand.h"
#include "Human.h"
#include "Dealer.h"
#include "Player.h"
#include "Table.h"

int main(){
	cout << "Program is starting." << endl;
	Table blackjack;

	blackjack.runGame();

	string action;
	cout << "Would you like to play again?" << endl;
	cin >> action;

	while (action != "no") {
		blackjack = Table();
		blackjack.runGame();
		cout << "Would you like to play again?" << endl;
		cin >> action;
	}

	cout << "Program has ended." << endl;
	return 0;
}
