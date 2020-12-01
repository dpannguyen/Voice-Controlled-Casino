#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "Betting.h"
#include "Card.h"
#include "Deck.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"


class Table
{
private:
    Deck cardDeck;
    Input input;
    Output output;
    Betting *bet;	//pointer point to the bet
    bool secondHandExists = false;

public:
    Table();
    Table(Betting* bet);
    ~Table();
    
    void doHit(Player *player);
    void getCardsInHand(Player *player);
    void doBet(std::string handName);
    void dealCards(Player *firstHand, Player *secondHand, Player *dealer);
    bool playHand(Player *player);
    void playDealer(Player *dealer, Player *hand);
    void playDealer(Player *dealer, Player *hand1, Player *hand2);
    void runGame();
};

#endif
