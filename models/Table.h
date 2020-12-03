/**
 * @file Table.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header containing declarations that define a Table object that is used to play Blackjack.
 */

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
    Deck *cardDeck; /**< Deck object that holds the deck of cards used for the game */
    Input input;   /**< Input object to handle user voice input */
    Output output; /**< Output object to handle voice output */
    Betting *bet;  /**< Pointer that points to the bet */
    /** @brief helper function that determines if a second hand has been added to the game */
    bool secondHandExists = false;

public:
    /** @brief Constructor for a Table object. Shuffles the deck of cards. */
    Table();
    /** @brief Constructor for a Table object. Shuffles the deck of cards and initializes the bet value. */
    Table(Betting *bet);
    /** @brief Destructor for a Table object. */
    ~Table();

    /** @brief Method that allows a specified Player to do a Hit, which is essentially adding the next Card from the Deck to their Hand. */
    void doHit(Player *player);
    /** @brief Method that outputs the Cards a Player has in their Hand as speech. */
    void getCardsInHand(Player *player);
    /** @brief Method that allows a Player to place a bet for one of their Hands. */
    void doBet(std::string handName);
    /** @brief Method that deals cards to a Player's one or two Hands, and to the Dealer's Hand. */
    void dealCards(Player *firstHand, Player *secondHand, Player *dealer);
    /** @brief Method that allows a Player to play their Hand. */
    bool playHand(Player *player);
    /** @brief Method that allows a Dealer to play their Hand. */
    void playDealer(Player *dealer, Player *hand);
    /** @brief Method that allows a Dealer to play their Hand against a Player's split Hand. */
    void playDealer(Player *dealer, Player *hand1, Player *hand2);
    /** @brief Method that starts the game, deals cards to the Player and Dealer, and controls the order of Player and Dealer turns. */
    void runGame();
};

#endif
