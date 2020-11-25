#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
#include "Player.h"

class Human : public Player{
    private:
        std::vector<Hand> handSplits;
	int sum;
    
    public:
        Human();
        Human(Hand h);
        void splitHand();
        ~Human();
};

#endif