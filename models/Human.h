#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include <Hand.h>

class Human {
    private:
        std::vector<Hand> hand;
    
    public:
        Human();
        void splitHand();
        ~Human();
}

