#include "Player.h"
#include "Hand.h"

using namespace std;

Player::Player() {
	hand = null;
}

Player::Player(Hand h) {
	hand = h;
}

int getHandTotal() {
	return hand.getTotalValue();
}

void addCardToHand(Card c) {
	hand.addCard(c);
}

bool checkBust() {
	return hand.checkBust();
}

bool checkBlackjack() {
	return hand.checkBlackjack();
}

Player::~Player() {}
