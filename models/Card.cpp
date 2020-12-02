/**
 * @file Card.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that defines a Card object with a number and suit.
 * 
 * This file initializes an object of class Card, and contains constructors that initialize the card with the appropriate number and suit.
 */

#include "Card.h"

/**
 * @brief Constructor for a card object that initializes number and suit to -1.
 */
Card::Card()
{
	number = -1;
	suit = -1;
}

/**
 * @brief Constructor for a card object that takes an integer and suit as input and initialzies to those values.
 * @param n Integer value representing the number of the card.
 * @param s Integer value representing the suit of the card.
 */
Card::Card(int n, int s)
{
	number = n;
	suit = s;
}

/**
 * @brief Destructor for a Card object.
 */
Card::~Card() {}
