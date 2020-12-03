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
 * Constructor for a Player object that initializes a Player with a Hand.
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
 * Setter method that initializes a player's hand.
 * @param h The Hand object to be assigned to the Player.
 * @return Void.
 */
void Player::setHand(Hand h)
{
	hand = h;
}

/**
 * Getter method that returns a hand's value.
 * @return Int representing the total value of the Player's Hand.
 */
int Player ::getHandTotal()
{
	return hand.getTotalValue();
}

/**
 * Getter method that returns a hand's name.
 * @return String representing the name of the Player's Hand.
 */
string Player ::getHandName()
{
	return hand.getName();
}

/**
 * Setter method that sets a hand's name to an input string.
 * @param name String representing the name of the Player's Hand.
 * @return Void.
 */
void Player::setHandName(string name)
{
	hand.setName(name);
}

/**
 * Method that adds a card to a player's hand.
 * @param c Card object to be added to the Player's Hand.
 * @return Void.
 */
void Player ::addCardToHand(Card c)
{
	hand.addCard(c);
}

/**
 * Method that removes the most recently added card from the player's hand.
 * @param c Card object to be removed from the Player's Hand.
 * @return Void.
 */
void Player ::removeLastCardFromHand(Card c)
{
	hand.removeLastCard(c);
}

/**
 * Checks if a player has busted.
 * @return bool. True if the Player has busted, false if not.
 */
bool Player ::checkBust()
{
	return hand.checkBust();
}

/**
 * Checks if a player has blackjack.
 * @return bool. True if the Player has won, false if not.
 */
bool Player ::checkBlackjack()
{
	return hand.checkBlackjack();
}

/**
 * Getter method that returns the cards in the player's hand.
 * @return vector<Card>. A vector of Card objects that the Player has in their Hand.
 */
vector<Card> Player ::getHandCards()
{
	return hand.getCards();
}
