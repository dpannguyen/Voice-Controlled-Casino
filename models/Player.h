#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <Hand.h>

class Player {
    private:
        std::vector<Hand> hand;
    
    public:
        Player();
		Player(Hand h);
        int getHandTotal();
        void addCardToHand(Card c);
        boolean checkBust();
        boolean checkBlackjack();
        ~Player();
}
