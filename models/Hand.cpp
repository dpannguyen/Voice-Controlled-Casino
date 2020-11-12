#include "Hand.h"
#include "Card.h"
#include <vector>

using namespace std;

Hand::Hand() {
	totalValue = 0;
}

Hand::Hand(vector<Card> cardHand, int total) {
	cards = cardHand;
	totalValue = total;
}

Hand::~Hand() {}

void Hand :: addCard(Card newCard) {
	cards.push_back(newCard);
	totalValue = totalValue + newCard.getNumber();
}

bool Hand :: checkBust() {
	if (totalValue > 21) {
		return true;
	}
	else {
		return false;
	}
}

bool Hand :: checkBlackjack() {
	if (totalValue == 21) {
		return true;
	}
	else {
		return false;
	}
}
