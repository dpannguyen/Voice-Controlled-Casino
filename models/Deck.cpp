#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// Initializes a classic 52-card deck.
Deck :: Deck(){
	pos = 0;

	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			Card newCard(i, j);
			cards.push_back(newCard);
		}
	}
}
/*
Deck(vector<Card> cardDeck){
	cards = cardDeck;
	pos = 0;
}
*/

// Helper function that returns a random integer.
int myrand (int i) { return std::rand() % i;}

// Shuffles a classic 52 card deck.
void Deck :: shuffleDeck(){
	std::srand( (unsigned) time(NULL));
	std::random_shuffle(cards.begin(), cards.end(), myrand);
	pos = 0;
}

// Returns the next card and increments the position variable accordingly.
Card Deck :: getNextCard(){
	Card nextCard = cards[pos];
	pos = pos + 1;
	return nextCard;
}

Deck :: ~Deck(){

}