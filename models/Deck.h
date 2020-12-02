/**
 * @file Deck.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header containing declarations that define a Deck object and initializes a classic 52-card deck, methods that shuffles the deck, returns the next card.
 */

#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
private:
  vector<Card> cards; /**< vector structure that contains cards */
  int pos;            /**< int variable that keeps track of position in a deck */
  /** @brief Helper function that returns a random integer. */
  int myRand(int i);

public:
  /** @brief Constructor for a deck object that initializes a classic 52-card deck. */
  Deck();
  /** @brief Destructor for a deck object. */
  ~Deck();
  
  /** @brief Method that shuffles a classic 52-card deck. */
  void shuffleDeck();
  /** @brief Method that returns the next Card object from the Deck. */
  Card getNextCard();
};

#endif
