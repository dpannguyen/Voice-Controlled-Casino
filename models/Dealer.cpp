#include "Dealer.h"
#include "Hand.h"
#include <vector>

using namespace std;

Dealer::Dealer() {
    parent = NULL;
    vector<Hand> hand(0, 0);
}

Dealer::~Dealer() {}