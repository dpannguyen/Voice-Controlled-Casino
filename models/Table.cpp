#include "Table.h"

using namespace std;

Table::Table() {
	cardDeck.shuffleDeck();
	win = 0;
	
}

Table::~Table() {}

// Takes another card from the top of the deck.
void Table::doHit(Player player) {}

// Allows a player to hold their total and end their turn.
void Table::doStand(Player player) {}

// Splits the hand into two hands. Adds a bet to the second hand.
void Table::doSplit(Player player) {}

// Returns a human's hand.
string Table :: getHumanHand(){
	string humanHandString;
	for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
		if( human.getHand().getCards().at(counter).getNumber() == 11 ){
			humanHandString = humanHandString + "J ";
		} else if (human.getHand().getCards().at(counter).getNumber() == 12) {
			humanHandString = humanHandString + "Q ";
		} else if (human.getHand().getCards().at(counter).getNumber() == 13) {
			humanHandString = humanHandString + "K ";
		} else {
			humanHandString = humanHandString + to_string(human.getHand().getCards().at(counter).getNumber()) + " ";
		}
	}
	return humanHandString;
}

// Returns the dealer's hand.
string Table :: getDealerHand(){
	string dealerHandString;
	for(int counter = 0; counter < dealer.getHand().getCards().size(); counter++){
		if( dealer.getHand().getCards().at(counter).getNumber() == 11 ){
			dealerHandString = dealerHandString + "J ";
		} else if (dealer.getHand().getCards().at(counter).getNumber() == 12) {
			dealerHandString = dealerHandString + "Q ";
		} else if (dealer.getHand().getCards().at(counter).getNumber() == 13) {
			dealerHandString = dealerHandString + "K ";
		} else {
			dealerHandString = dealerHandString + to_string(dealer.getHand().getCards().at(counter).getNumber()) + " ";
		}
	}
	return dealerHandString;
}

// Checks if a player or dealer has won.
int Table::checkWin() {
	return win;
}

// Starts the game, configures the cards for dealer and players, provides narration of game updates as the game progresses.
void Table::runGame() {
	Output output;

	output.outputAsString("Welcome to the game!");
	output.outputAsVoice("Welcome to the game!");

	output.outputAsString("Deck has been shuffled!");
	output.outputAsVoice("Deck has been shuffled!");

	cardDeck.shuffleDeck();

	human.addCardToHand(cardDeck.getNextCard());
	dealer.addCardToHand(cardDeck.getNextCard());
	human.addCardToHand(cardDeck.getNextCard());
	dealer.addCardToHand(cardDeck.getNextCard());

	while(!checkWin()){
		output.outputAsString("In your hand, you have: ");
		output.outputAsVoice("In your hand, you have: ");

		for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
			if( human.getHand().getCards().at(counter).getNumber() == 11 ){
				output.outputAsString("J");
				output.outputAsVoice("J");
			} else if (human.getHand().getCards().at(counter).getNumber() == 12) {
				output.outputAsString("Q");
				output.outputAsVoice("Q");
			} else if (human.getHand().getCards().at(counter).getNumber() == 13) {
				output.outputAsString("K");
				output.outputAsVoice("K");
			} else {
				string number = to_string(human.getHand().getCards().at(counter).getNumber());
				output.outputAsString(number);
				output.outputAsVoice(number);
			}
		}
		cout << endl;
		
		output.outputAsString("In dealer's hand, it has: ");
		output.outputAsVoice("In dealer's hand, it has: ");

		for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
			if( dealer.getHand().getCards().at(counter).getNumber() == 11 ){
				output.outputAsString("J");
				output.outputAsVoice("J");
			} else if (dealer.getHand().getCards().at(counter).getNumber() == 12) {
				output.outputAsString("Q");
				output.outputAsVoice("Q");
			} else if (dealer.getHand().getCards().at(counter).getNumber() == 13) {
				output.outputAsString("K");
				output.outputAsVoice("K");
			} else {
				string number = to_string(dealer.getHand().getCards().at(counter).getNumber());
				output.outputAsString(number);
				output.outputAsVoice(number);
			}
		}
		cout << endl;
		win = 1;
	}
}
