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
        int getHandTotal();
        void addCardToHand();
        boolean checkBust();
        boolean checkBlackjack();
        ~Player();
}
