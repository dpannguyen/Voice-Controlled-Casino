#include "Player.h"

using namespace std;

Player::Player() {
}

Player::Player(Hand h) {
	hand = h;
}

int Player :: getHandTotal() {
	return hand.getTotalValue();
}

void Player :: addCardToHand(Card c) {
	hand.addCard(c);
}

bool Player :: checkBust() {
	return hand.checkBust();
}

bool Player :: checkBlackjack() {
	return hand.checkBlackjack();
}

Hand Player :: getHand(){
	return hand;
}

Player::~Player() {}
