/**
 * @file Betting.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header file containing declarations of a Betting object and methods that allow a user to place a bet while playing Blackjack.
 */

#ifndef BETTING_H
#define BETTING_H

class Betting
{
private:
    int humanMoney;         /**< Integer variable that contains the amount of money the player currently has */
    int betMoney;           /**< Integer variable that contains the amount of money the player chooses to bet during a round */
    int betMoneySecondHand; /**< Integer variable that contains the amount of money the player chooses to bet for their second hand during a round */

public:
    /** @brief Constructor for a betting object. */
    Betting();
    /** @brief Destructor for a betting object. */
    ~Betting();

    /** @brief Getter method that returns the amount of money a player has. */
    int getHumanMoney();
    /** @brief Getter method that returns the amount of money a player has placed as a bet. */
    int getBetMoney();
    /** @brief Getter method that returns the amount of money a player has placed as a bet in the case of a split for their second hand. */
    int getBetMoneySecondHand();
    /** @brief Checks if the player has enough money left to place a certain bet. */
    bool checkBetMoney(int money);
    /** @brief Allows a player to bet a specified amount of money during a round of Blackjack. */
    void betDatMoney(int datMoney);
    /** @brief Allows a player to bet a specified amount of money for their second hand in the event of a split. */
    void betDatMoneySecondHand(int datMoney);
    /** @brief Adds money to a player's total money when they win a round of Blackjack. */
    void winMoney();
    /** @brief Adds money to a player's total money in their second hand when they win a round of Blackjack. */
    void winMoneySecondHand();
    /** @brief When the player has lost, resets the amount the player has bet to 0 for subsequent rounds. */
    void loseMoney();
    /** @brief When the player has lost for their second hand, resets the amount the player has bet to 0 for subsequent rounds. */
    void loseMoneySecondHand();
};

#endif
