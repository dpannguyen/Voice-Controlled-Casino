#include "Player.h"

using namespace std;

// Initializes a player.
Player::Player() {}

// Initializes a player with a hand.
Player::Player(Hand h) {
	hand = h;
}

Player::~Player() {}

void Player::setHand(Hand h) {
	hand = h;
}

// Returns the total value of the player's hand.
int Player ::getHandTotal()
{
	return hand.getTotalValue();
}

string Player ::getHandName()
{
	return hand.getName();
}

void Player::setHandName(string name) {
	hand.setName(name);
}

// Adds a card to the hand.
void Player ::addCardToHand(Card c)
{
	hand.addCard(c);
}

void Player ::removeLastCardFromHand(Card c)
{
	hand.removeLastCard(c);
}

// Checks if player has busted.
bool Player ::checkBust()
{
	return hand.checkBust();
}

// Checks if player has won.
bool Player ::checkBlackjack()
{
	return hand.checkBlackjack();
}

// Returns the player's hand.
vector<Card> Player ::getHandCards()
{
	return hand.getCards();
}
