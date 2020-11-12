#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>

class Card {
    private:
      int suit;
      int number;
    
    public:
      Card();
      Card(int n, int s);

      int getSuit() { return suit; }
      int getNumber() { return number; }

      ~Card();
};
