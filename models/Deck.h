#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Card.h"

using namespace std;

class Deck {
    private:
      vector<Card> cards;
      int pos;
      int myRand(int i);

    public:
      Deck();
      ~Deck();
      
      void shuffleDeck();
      Card getNextCard();
};

#endif
