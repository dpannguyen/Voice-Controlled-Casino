/**
 * @file Player.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing declarations that define a Player object with a hand.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"

class Player
{
private:
        Hand hand; /**< Hand object that is used throughout the player class, to be assigned to a player */

public:
        /** @brief Constructor for a Player object. */
        Player();
        /** @brief Constructor for a Player object that initializes a Player with a Hand. */
        Player(Hand h);
        /** @brief Destructor for a Player object. */
        ~Player();
        
        /** @brief Setter method that assigns a Hand to a Player. */
        void setHand(Hand h);
        /** @brief Getter method that returns the total value of the Player's Hand. */
        int getHandTotal();
        /** @brief Getter method that returns the name of the Player's Hand. */
        std::string getHandName();
        /** @brief Setter method that assigns a name to a Player's Hand. */
        void setHandName(std::string name);
        /** @brief Method that adds a Card object to the Player's Hand. */
        void addCardToHand(Card c);
        /** @brief Method that removes the most recent card added from the Player's Hand. */
        void removeLastCardFromHand(Card c);
        /** @brief Method that checks if a Player has busted. */
        bool checkBust();
        /** @brief Method that checks if a Player has won Blackjack. */
        bool checkBlackjack();
        /** @brief Method that returns a vector of the Cards in a Player's Hand. */
        std::vector<Card> getHandCards();
};

#endif