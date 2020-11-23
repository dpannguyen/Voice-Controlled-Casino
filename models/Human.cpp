#include "Human.h"
#include "Hand.h"
#include "Card.h"
#include <vector>

using namespace std;

Human::Human() {
    sum = 0;
}

Human::Human(Hand h) {
	hand = h;
}
/*
void splitHand(Card card1, Card card2) { 
    if card1.number == card2.number {
        vector<Hand> hand2(card2, card2.number);
    }
}
*/
Human::~Human() {}
