#include "Card.h"

Card::Card() {
	number = -1;
	suit = -1;
}

Card::Card(int n, int s) {
	number = n;
	suit = s;
}

Card::~Card(){

}
