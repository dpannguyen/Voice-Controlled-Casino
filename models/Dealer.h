#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <string>
#include <vector>
#include <Hand.h>

class Player {
    private:
        std::vector<Hand> hand;
    
    public:
        Dealer();
        ~Dealer();
}
