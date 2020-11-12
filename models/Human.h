#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include <Hand.h>

class Human: public Player {
    private:
        std::vector<Hand> hand;
    
    public:
        Human();
        void splitHand();
        ~Human();
};

