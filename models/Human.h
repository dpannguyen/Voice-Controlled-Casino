#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"

using namespace std;

class Human{
    private:
        vector<Hand> hand;
	int sum;
    
    public:
        Human();
        void splitHand();
        ~Human();
};

#endif
