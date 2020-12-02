/**
 * @file Card.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header file containing declarations that define a Card object with a number and suit.
 */

#ifndef CARD_H
#define CARD_H

class Card
{
private:
  int suit;   /**< integer containing the suit of a card */
  int number; /**< integer containing the number of a card */

public:
  /** @brief Constructor for a card object that initializes number and suit to -1. */
  Card();
  /** @brief Constructor for a card object that takes an integer and suit as input and initialzies to those values. */
  Card(int n, int s);
  /** @brief Destructor for a Card object. */
  ~Card();

  /** @brief getter method that returns the suit of a card. */
  int getSuit() { return suit; }
  /** @brief getter method that returns the number of a card. */
  int getNumber() { return number; }
};

#endif
