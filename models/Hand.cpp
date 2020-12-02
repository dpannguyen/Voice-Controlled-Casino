/**
 * @file Hand.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Hand with a totalValue and a name, contains methods that add or remove a card to the hand 
 * and adjust the totalValue accordingly, a setter method that assigns a name to the Hand, and boolean methods that evaluate
 * if the Hand has Blackjack or has Busted.
 */

#include "Hand.h"

using namespace std;

/**
 * Constructor for a Hand object.
 */
Hand::Hand()
{
	totalValue = 0;
	handName = "hand";
}

/**
 * Constructor for a Hand object that initializes an input string.
 * @param name String representing the name of the hand.
 */
Hand::Hand(string name)
{
	totalValue = 0;
	handName = name;
}

/**
 * Destructor for a Hand object.
 */
Hand::~Hand() {}

/**
 * Takes a card as input, and adjusts the total value according to the card's number.
 * If the card's number is over 10, it is added as 10 because this is the max value of a card in Blackjack.
 * @param newCard The card to be added to the hand.
 * @return Void.
 */
void Hand ::addCard(Card newCard)
{
	cards.push_back(newCard);
	int number;
	if (newCard.getNumber() > 10)
		number = 10;
	else
		number = newCard.getNumber();
	totalValue = totalValue + number;
}

/**
 * Removes the most recently added card from the hand, specified by input variable lastCard, and adjusts the totalValue 
 * of the Hand according to that card's value.
 * If the card's number is over 10, it is subtracted as 10 because this is the max value of a card in Blackjack.
 * @param lastCard The card that was most recently added to the Hand.
 * @return Void.
 */
void Hand ::removeLastCard(Card lastCard)
{
	cards.pop_back();
	int number;
	if (lastCard.getNumber() > 10)
		number = 10;
	else
		number = lastCard.getNumber();
	totalValue = totalValue - number;
}

/**
 * Sets the handName of the Hand to the input string containing the new name.
 * @param newName A string containing the desired new name of the Hand.
 * @return Void.
 */
void Hand ::setName(std::string newName)
{
	handName = newName;
}

/**
 * Checks the value of the cards for a player to determine if there is a bust, i.e. the totalValue of the cards exceeds 21.
 * @return Bool, true if the Hand has busted, and false if the Hand has not.
 */
bool Hand ::checkBust()
{
	if (totalValue > 21)
		return true;
	else
		return false;
}

/**
 * Checks the value of the cards for a player to determine if there is blackjack, i.e. the totalValue of the cards is equal to 21.
 * @return Bool, true if the Hand has won, and false if the Hand has not.
 */
bool Hand ::checkBlackjack()
{
	if (totalValue == 21)
		return true;
	else
		return false;
}
