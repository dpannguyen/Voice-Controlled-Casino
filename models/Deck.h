#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Deck {
    private:
      std::vector<Card> cards;
      int pos;

    public:
      Deck();
      //Deck(vector<Card> cardDeck);

      int myRand(int i);
      void shuffleDeck();
      Card getNextCard();

      ~Deck();
};
#endif
