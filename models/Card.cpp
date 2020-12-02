/**
 * @file Card.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Card, and contains constructors that initialize the card with the appropriate number and suit.
 */

#include "Card.h"

/**
 * Constructor that initializes card object with number and suit set as -1.
 */
Card::Card()
{
	number = -1;
	suit = -1;
}

/**
 * Constructor that initializes card object with specified number and suit.
 * @param n Integer value representing the number of the card.
 * @param s Integer value representing the suit of the card.
 */
Card::Card(int n, int s)
{
	number = n;
	suit = s;
}

/**
 * Destructor for a Card object.
 */
Card::~Card() {}
