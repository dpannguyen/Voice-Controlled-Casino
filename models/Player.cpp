/**
 * @file Player.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that defines a Player object with a hand.
 * 
 * This file initializes an object of class Player with a hand, contains setters to assign a specific Hand object to the Player,
 * and a specific name for the Player's Hand, getters to return the name of the Hand, value associated with the Hand, and the cards
 * in the Hand, and methods to add a card to the Player's Hand, remove the most recent Card from the Player's Hand, and check
 * if the Player has Blackjack or Bust.
 */

#include "Player.h"

using namespace std;

/**
 * @brief Constructor for a Player object.
 */
Player::Player() {}

/**
 * @brief Constructor for a Player object that initializes a Player with a Hand.
 * @param h The Hand object to be assigned to the Player.
 */
Player::Player(Hand h)
{
	hand = h;
}

/**
 * @brief Destructor for a Player object.
 */
Player::~Player() {}

/**
 * @brief Setter method that assigns a Hand to a Player.
 * @param h The Hand object to be assigned to the Player.
 * @return Void.
 */
void Player::setHand(Hand h)
{
	hand = h;
}

/**
 * @brief Getter method that returns the total value of the Player's Hand.
 * @return Int representing the total value of the Player's Hand.
 */
int Player ::getHandTotal()
{
	return hand.getTotalValue();
}

/**
 * @brief Getter method that returns the name of the Player's Hand.
 * @return String representing the name of the Player's Hand.
 */
string Player ::getHandName()
{
	return hand.getName();
}

/**
 * @brief Setter method that assigns a name to a Player's Hand.
 * @param name String representing the name of the Player's Hand.
 * @return Void.
 */
void Player::setHandName(string name)
{
	hand.setName(name);
}

/**
 * @brief Method that adds a Card object to the Player's Hand.
 * @param c Card object to be added to the Player's Hand.
 * @return Void.
 */
void Player ::addCardToHand(Card c)
{
	hand.addCard(c);
}

/**
 * @brief Method that removes the most recent card added from the Player's Hand.
 * @param c Card object to be removed from the Player's Hand.
 * @return Void.
 */
void Player ::removeLastCardFromHand(Card c)
{
	hand.removeLastCard(c);
}

/**
 * @brief Method that checks if a Player has busted.
 * @return bool. True if the Player has busted, false if not.
 */
bool Player ::checkBust()
{
	return hand.checkBust();
}

/**
 * @brief Method that checks if a Player has won Blackjack.
 * @return bool. True if the Player has won, false if not.
 */
bool Player ::checkBlackjack()
{
	return hand.checkBlackjack();
}

/**
 * @brief Method that returns a vector of the Cards in a Player's Hand.
 * @return vector<Card>. A vector of Card objects that the Player has in their Hand.
 */
vector<Card> Player ::getHandCards()
{
	return hand.getCards();
}
