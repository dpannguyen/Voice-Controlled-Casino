#include <iostream>
#include <string>
#include <vector>

class Card {
    private:
      int suit;
      int number;
    
    public:
      Card();

      int getSuit();
      int getNumber();

      ~Card();
};
