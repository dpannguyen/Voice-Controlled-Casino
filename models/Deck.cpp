#include "Deck.h"
#include <algorithm>
#include <vector>

using namespace std;

Deck :: Deck(){
	pos = 0;

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < 4; j++) {
			Card newCard(i, j);
			cards.push_back(newCard);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			Card newCard(10, j);
			cards.push_back(newCard);
		}
	}
	for (int j = 0; j < 3; j++) {
		Card newCard(11, j);
		cards.push_back(newCard);
	}
}
/*
Deck(vector<Card> cardDeck){
	cards = cardDeck;
	pos = 0;
}
*/
void Deck :: shuffle(){
	random_shuffle(cards.begin(), cards.end());
	pos = 0;
}

Card Deck :: getNextCard(){
	Card nextCard = cards[pos];
	pos = pos + 1;
	return nextCard;
}

Deck :: ~Deck(){

}
