#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Human.h"
#include "Dealer.h"
#include "Deck.h"
#include "Output.h"

class Table {
    private:
        Human human;
        Player player;
        Dealer dealer;
        Deck cardDeck;
        int win;
        int checkWin();
        
    public:
        Table();
        ~Table();
        void runGame();
        void doHit(Player player);
        void doStand(Player player);
        void doSplit(Player player);
        string getHumanHand();
        string getDealerHand();
};
#endif
