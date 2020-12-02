/**
 * @file Hand.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that defines a Hand object and initializes the value and name, contains methods that add and remove a card to the hand, set the name of the hand, and check if that hand has blackjack or bust.
 */

#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"

class Hand
{
private:
    std::vector<Card> cards; /**< vector structure that contains the cards in a hand */
    int totalValue;          /**< integer representing the total value of the cards in a hand */
    std::string handName;    /**< string representing the name of a hand */

public:
    /** @brief Constructor for a Hand object that initializes totalValue to 0 and the handName to "hand". */
    Hand();
    /** @brief Constructor for a Hand object that initializes totalValue to 0 and initializes the name to an input string. */
    Hand(std::string name);
    /** @brief Destructor for a Hand object. */
    ~Hand();

    /** @brief getter method that returns the cards in a hand */
    std::vector<Card> getCards() { return cards; }
    /** @brief getter method that returns the total value of the cards in a hand */
    int getTotalValue() { return totalValue; }
    /** @brief getter method that returns the name of a hand */
    std::string getName() { return handName; }
    /** @brief Method that adds a card to a Hand. */
    void addCard(Card newCard);
    /** @brief Method that removes the last card that was added to a Hand from the Hand. */
    void removeLastCard(Card lastCard);
    /** @brief Method that sets the name of a Hand to a specified input string. */
    void setName(std::string newName);
    /** @brief Method that checks if a Hand has busted. */
    bool checkBust();
    /** @brief Method that checks if a Hand has won Blackjack. */
    bool checkBlackjack();
};

#endif