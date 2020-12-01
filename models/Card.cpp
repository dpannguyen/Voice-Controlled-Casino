#include "Card.h"

// Initializes a card with the appropriate number and suit.

Card::Card() {
	number = -1;
	suit = -1;
}

Card::Card(int n, int s) {
	number = n;
	suit = s;
}

Card::~Card(){}
