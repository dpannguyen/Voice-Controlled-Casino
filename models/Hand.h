#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"

class Hand
{
private:
    std::vector<Card> cards;
    int totalValue;
    std::string handName;

public:
    Hand();
    Hand(std::string name);
    ~Hand();
    
    std::vector<Card> getCards() { return cards; }
    int getTotalValue() { return totalValue; }
    std::string getName() { return handName; }
    void addCard(Card newCard);
    void removeLastCard(Card lastCard);
    void setName(std::string newName);
    bool checkBust();
    bool checkBlackjack();
};

#endif