#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Hand {
    private:
        std::vector<Card> cards;
        int totalValue;
    
    public:
        Hand();
	    Hand(std::vector<Card> cardHand, int total);
        ~Hand();
        std::vector<Card> getCards() { return cards; }
        int getTotalValue() { return totalValue; }
        void addCard(Card newCard);
        bool checkBust();
        bool checkBlackjack();
};
#endif