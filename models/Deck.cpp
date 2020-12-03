/**
 * @file Deck.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Deck, contains a method that shuffles the deck, a helper method that returns a random
 * integer so that each shuffle order is unique, a method that returns the next card from the top of the deck, 
 * and a destructor for the Deck objects. 
 * Deck class follows the Singleton Design Pattern to ensure only one instance of deck exists.
 */

#include "Deck.h"

using namespace std;

/**
 * Instance of deck object
 */
Deck* Deck::deckInstance = NULL;

/**
 * Constructor for a deck object.
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
 * Returns only one instance of deck object
 * @return Deck instance
 */ 
Deck* Deck::instance() {
	if (deckInstance == NULL) {
		deckInstance = new Deck();
	}
	return deckInstance;
}

/**
 * Destructor for a deck object.
 */
Deck ::~Deck() {}

/**
 * Shuffles cards in deck
 * @return Void
 */
void Deck ::shuffleDeck()
{
	srand((unsigned)time(NULL));
	random_shuffle(cards.begin(), cards.end(), [](int i) -> int { return rand() % i; });
	pos = 0;
}

/**
 * Returns the next card and increments the position in the Deck accordingly.
 * @return Card object
 */
Card Deck ::getNextCard()
{
	Card nextCard = cards[pos];
	pos = pos + 1;
	return nextCard;
}
