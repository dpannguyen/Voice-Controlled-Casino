#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"

class Player {
    protected:
        Hand hand;
        Hand hand2;
    
    public:
        Player();
	Player(Hand h);
        Player(Hand h, Hand h2);
        int getHandTotal();
        void addCardToHand(Card c);
        bool checkBust();
        bool checkBlackjack();
	Hand getHand();
        Hand addHand();
        void addCardToHand2(Card c);
        ~Player();
};
#endif