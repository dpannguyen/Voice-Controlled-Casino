#include "Hand.h"
#include "Card.h"
#include <vector>

using namespace std;

// Initializes a hand of cards.
Hand::Hand() {
	totalValue = 0;
}

// Initializes a hand of cards with the total value.
Hand::Hand(vector<Card> cardHand, int total) {
	cards = cardHand;
	totalValue = total;
}

Hand::~Hand() {}

// Adds a card to the hand, and adjusts the total value accordingly.
void Hand :: addCard(Card newCard) {
	cards.push_back(newCard);
	int val = newCard.getNumber();
	if (newCard.getNumber() >= 10) {
		val = 10;
	}
	totalValue = totalValue + val;
}

// Checks the value of the cards (for player or dealer) to determine if there is a bust.
bool Hand :: checkBust() {
	if (totalValue > 21) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the value of the cards (for player or dealer) to determine a win.
bool Hand :: checkBlackjack() {
	if (totalValue == 21) {
		return true;
	}
	else {
		return false;
	}
}
