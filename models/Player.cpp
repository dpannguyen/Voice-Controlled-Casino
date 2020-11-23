#include "Player.h"

using namespace std;

// Initializes a player.
Player::Player() {
}

// Initializes a player with a hand.
Player::Player(Hand h) {
	hand = h;
}

// Returns the total value of the player's hand.
int Player :: getHandTotal() {
	return hand.getTotalValue();
}

// Adds a card to the hand.
void Player :: addCardToHand(Card c) {
	hand.addCard(c);
}

// Checks if player has busted.
bool Player :: checkBust() {
	return hand.checkBust();
}

// Checks if player has won.
bool Player :: checkBlackjack() {
	return hand.checkBlackjack();
}

// Returns the player's hand.
Hand Player :: getHand(){
	return hand;
}

Player::~Player() {}