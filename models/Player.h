#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"

using namespace std;

class Player {
    private:
        Hand hand;
    
    public:
        Player();
	Player(Hand h);
        int getHandTotal();
        void addCardToHand(Card c);
        bool checkBust();
        bool checkBlackjack();
        ~Player();
};
#endif
