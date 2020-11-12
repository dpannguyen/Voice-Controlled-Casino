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


	cout << "Program has ended." << endl;
	return 0;
}
