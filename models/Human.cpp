#include "Human.h"
#include "Hand.h"
#include "Card.h"
#include <vector>

using namespace std;

// include hand class

Human::Human() {
    sum = 0;
    vector<Hand> hand(0, 0);
}

// if dealt 2 cards w same value, option to create another hand and add one card to each, 
// then can ask for new second card for each  
void splitHand(vector<Card> card1, vector<Card> card2) { 
    if card1.number == card2.number {
        vector<Hand> hand2(card2, card2.number);
    }
}

Human::~Human() {}