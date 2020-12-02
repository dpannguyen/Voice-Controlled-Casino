/**
 * @file Deck.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that defines a Deck object and initializes a classic 52-card deck, contains a method that shuffles the deck, and a method that returns the next card.
 * 
 * This file initializes an object of class Deck, contains a method that shuffles the deck, a helper method that returns a random
 * integer so that each shuffle order is unique, a method that returns the next card from the top of the deck, 
 * and a destructor for the Deck objects. 
 */

#include "Deck.h"

using namespace std;

/**
 * @brief Constructor for a deck object that initializes a classic 52-card deck.
 */
Deck ::Deck()
{
	pos = 0;
	for (int i = 1; i < 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Card newCard(i, j);
			cards.push_back(newCard);
		}
	}
}

/**
 * @brief Destructor for a deck object.
 */
Deck ::~Deck() {}

/**
 * @brief Helper function that returns a random integer.
 * @param i An integer value of the current time.
 * @return Random integer value generated from an integer of the current time.
 */
int myrand(int i) { return rand() % i; }

/**
 * @brief Method that shuffles a classic 52-card deck.
 * @return Void
 */
void Deck ::shuffleDeck()
{
	srand((unsigned)time(NULL));
	random_shuffle(cards.begin(), cards.end(), myrand);
	pos = 0;
}

/**
 * @brief Method that returns the next Card object from the Deck.
 * @return Card object
 * Returns the next card and increments the position in the Deck accordingly.
 */
Card Deck ::getNextCard()
{
	Card nextCard = cards[pos];
	pos = pos + 1;
	return nextCard;
}
