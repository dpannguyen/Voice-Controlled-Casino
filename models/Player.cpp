/**
 * @file Player.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Player with a hand, contains setters to assign a specific Hand object to the Player,
 * and a specific name for the Player's Hand, getters to return the name of the Hand, value associated with the Hand, and the cards
 * in the Hand, and methods to add a card to the Player's Hand, remove the most recent Card from the Player's Hand, and check
 * if the Player has Blackjack or Bust.
 */

#include "Player.h"

using namespace std;

/**
 * Constructor for a Player object.
 */
Player::Player() {}

/**
 * onstructor for a Player object that initializes a Player with a Hand.
 * @param h The Hand object to be assigned to the Player.
 */
Player::Player(Hand h)
{
	hand = h;
}

/**
 * Destructor for a Player object.
 */
Player::~Player() {}

/**
 * @param h The Hand object to be assigned to the Player.
 * @return Void.
 */
void Player::setHand(Hand h)
{
	hand = h;
}

/**
 * @return Int representing the total value of the Player's Hand.
 */
int Player ::getHandTotal()
{
	return hand.getTotalValue();
}

/**
 * @return String representing the name of the Player's Hand.
 */
string Player ::getHandName()
{
	return hand.getName();
}

/**
 * @param name String representing the name of the Player's Hand.
 * @return Void.
 */
void Player::setHandName(string name)
{
	hand.setName(name);
}

/**
 * @param c Card object to be added to the Player's Hand.
 * @return Void.
 */
void Player ::addCardToHand(Card c)
{
	hand.addCard(c);
}

/**
 * @param c Card object to be removed from the Player's Hand.
 * @return Void.
 */
void Player ::removeLastCardFromHand(Card c)
{
	hand.removeLastCard(c);
}

/**
 * @return bool. True if the Player has busted, false if not.
 */
bool Player ::checkBust()
{
	return hand.checkBust();
}

/**
 * @return bool. True if the Player has won, false if not.
 */
bool Player ::checkBlackjack()
{
	return hand.checkBlackjack();
}

/**
 * @return vector<Card>. A vector of Card objects that the Player has in their Hand.
 */
vector<Card> Player ::getHandCards()
{
	return hand.getCards();
}
