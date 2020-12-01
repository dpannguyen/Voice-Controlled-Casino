#ifndef CARD_H
#define CARD_H

class Card
{
private:
  int suit;
  int number;

public:
  Card();
  Card(int n, int s);
  ~Card();
  
  int getSuit() { return suit; }
  int getNumber() { return number; }
};

#endif
