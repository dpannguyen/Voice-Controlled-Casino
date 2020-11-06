#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <vector>
#include <Card.h>

class Hand {
    private:
        std::vector<Card> cards;
        int totalValue;
    
    public:
        Hand();
        ~Hand();
        std::vector<Card> getCards();
        int getTotalValue();
        void addCard();
        bool checkBust();
        bool checkBlackjack();
}
