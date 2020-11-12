#include "Table.h"

using namespace std;

Table::Table() {
	cardDeck.shuffleDeck();
	win = 0;
	
}

Table::~Table() {}

void Table::doHit(Player player) {}

void Table::doStand(Player player) {}

void Table::doSplit(Player player) {}

int Table::checkWin() {
	return win;
}

void Table::runGame() {
	cout << "Welcome to the game!" << endl;
	cout << "Deck has been shuffled!" << endl;

	cardDeck.shuffleDeck();

	human.addCardToHand(cardDeck.getNextCard());
	dealer.addCardToHand(cardDeck.getNextCard());
	human.addCardToHand(cardDeck.getNextCard());
	dealer.addCardToHand(cardDeck.getNextCard());

	while(!checkWin()){
		cout << "In your hand, you have: ";
		for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
			if( human.getHand().getCards().at(counter).getNumber() == 11 ){
				cout << "J ";
			} else if (human.getHand().getCards().at(counter).getNumber() == 12) {
				cout << "Q ";
			} else if (human.getHand().getCards().at(counter).getNumber() == 13) {
				cout << "K ";
			} else {
				cout << human.getHand().getCards().at(counter).getNumber() << " ";
			}
		}
		cout << endl;
		
		cout << "In dealer's hand, it has: ";
		for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
			if( dealer.getHand().getCards().at(counter).getNumber() == 11 ){
				cout << "J ";
			} else if (dealer.getHand().getCards().at(counter).getNumber() == 12) {
				cout << "Q ";
			} else if (dealer.getHand().getCards().at(counter).getNumber() == 13) {
				cout << "K ";
			} else {
				cout << dealer.getHand().getCards().at(counter).getNumber() << " ";
			}
		}
		cout << endl;
		win = 1;
	}
}
