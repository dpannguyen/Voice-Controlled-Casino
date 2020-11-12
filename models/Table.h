#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Human.h"
#include "Dealer.h"
#include "Deck.h"

class Table {
    private:
        Human human;
        Dealer dealer;
        Deck cardDeck;
        int win;
        void doHit(Player player);
        void doStand(Player player);
        void doSplit(Player player);
        int checkWin();
        
    public:
        Table();
        ~Table();
        void runGame();
};
#endif
