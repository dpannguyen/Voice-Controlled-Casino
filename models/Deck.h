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
      Deck(std::vector<Card> cardDeck);

      void shuffle();
      Card getNextCard();

      ~Deck();
};
