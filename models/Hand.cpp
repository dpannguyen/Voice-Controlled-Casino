#include "Hand.h"

using namespace std;

// Initializes a hand of cards.
Hand::Hand()
{
	totalValue = 0;
	handName = "hand";
}

Hand::Hand(string name)
{
	totalValue = 0;
	handName = name;
}

Hand::~Hand() {}

// Adds a card to the hand, and adjusts the total value accordingly.
void Hand ::addCard(Card newCard)
{
	cards.push_back(newCard);
	int number;
	if (newCard.getNumber() > 10) number = 10;
	else number = newCard.getNumber();
	totalValue = totalValue + number;
}

void Hand ::removeLastCard(Card lastCard)
{
	cards.pop_back();
	int number;
	if (lastCard.getNumber() > 10) number = 10;
	else number = lastCard.getNumber();
	totalValue = totalValue - number;
}

void Hand ::setName(std::string newName)
{
	handName = newName;
}

// Checks the value of the cards (for player or dealer) to determine if there is a bust.
bool Hand ::checkBust()
{
	if (totalValue > 21) return true;
	else return false;
}

// Checks if the value of the cards (for player or dealer) to determine a win.
bool Hand ::checkBlackjack()
{
	if (totalValue == 21) return true;
	else return false;
}
