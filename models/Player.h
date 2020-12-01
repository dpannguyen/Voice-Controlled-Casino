#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"

class Player
{
private:
        Hand hand;

public:
        Player();
        Player(Hand h);
        ~Player();
        
        void setHand(Hand h);
        int getHandTotal();
        std::string getHandName();
        void setHandName(std::string name);
        void addCardToHand(Card c);
        void removeLastCardFromHand(Card c);
        bool checkBust();
        bool checkBlackjack();
        std::vector<Card> getHandCards();
};

#endif