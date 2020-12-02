/**
 * @file Hand.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that defines a Hand object and initializes the value and name, contains methods that add and remove a card to the hand, set the name of the hand, and check if that hand has blackjack or bust.
 * 
 * This file initializes an object of class Hand with a totalValue and a name, contains methods that add or remove a card to the hand 
 * and adjust the totalValue accordingly, a setter method that assigns a name to the Hand, and boolean methods that evaluate
 * if the Hand has Blackjack or has Busted.
 */

#include "Hand.h"

using namespace std;

/**
 * @brief Constructor for a Hand object that initializes totalValue to 0 and the handName to "hand".
 */
Hand::Hand()
{
	totalValue = 0;
	handName = "hand";
}

/**
 * @brief Constructor for a Hand object that initializes totalValue to 0 and initializes the name to an input string.
 * @param name String representing the name of the hand.
 */
Hand::Hand(string name)
{
	totalValue = 0;
	handName = name;
}

/**
 * @brief Destructor for a Hand object.
 */
Hand::~Hand() {}

/**
 * @brief Method that adds a card to a Hand.
 * @param newCard The card to be added to the hand.
 * @return Void.
 * Takes a card as input, and adjusts the total value according to the card's number.
 * If the card's number is over 10, it is added as 10 because this is the max value of a card in Blackjack.
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
 * @brief Method that removes the last card that was added to a Hand from the Hand.
 * @param lastCard The card that was most recently added to the Hand.
 * @return Void.
 * Removes the most recently added card from the hand, specified by input variable lastCard, and adjusts the totalValue 
 * of the Hand according to that card's value.
 * If the card's number is over 10, it is subtracted as 10 because this is the max value of a card in Blackjack.
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
 * @brief Method that sets the name of a Hand to a specified input string.
 * @param newName A string containing the desired new name of the Hand.
 * @return Void.
 * Sets the handName of the Hand to the input string containing the new name.
 */
void Hand ::setName(std::string newName)
{
	handName = newName;
}

/**
 * @brief Method that checks if a Hand has busted.
 * @return Bool, true if the Hand has busted, and false if the Hand has not.
 * Checks the value of the cards for a player to determine if there is a bust, i.e. the totalValue of the cards exceeds 21.
 */
bool Hand ::checkBust()
{
	if (totalValue > 21)
		return true;
	else
		return false;
}

/**
 * @brief Method that checks if a Hand has won Blackjack.
 * @return Bool, true if the Hand has won, and false if the Hand has not.
 * Checks the value of the cards for a player to determine if there is blackjack, i.e. the totalValue of the cards is equal to 21.
 */
bool Hand ::checkBlackjack()
{
	if (totalValue == 21)
		return true;
	else
		return false;
}
