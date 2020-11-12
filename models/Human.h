#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
#include "Player.h"

using namespace std;

class Human : public Player{
    private:
        vector<Hand> handSplits;
	int sum;
    
    public:
        Human();
        void splitHand();
        ~Human();
};

#endif
