/**
 * @file Betting.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header file containing definitions of methods that allow a user to place a bet while playing Blackjack.
 * 
 * This file initializes an object of class Betting, contains setters and getters for betting money for a player's 
 * first and second hands, methods that allow a specified amount of money to be allocated to a bet in each round, 
 * and methods that add or deduct money from the hands corresponding to wins and losses.
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
    /**
     * @brief Constructor for a betting object. 
     * Initializes money that the player currently has. The default is 5000.
     * Initializes betMoney (the money player places as a bet during a round) to 0.
     * Initializes betMoneySecondHand (the money player places as a bet when their hand has been split) to 0.
     */
    Betting();
    /**
    * @brief Destructor for a betting object.
    */
    ~Betting();

    int getHumanMoney();
    int getBetMoney();
    int getBetMoneySecondHand();
    bool checkBetMoney(int money);
    void betDatMoney(int datMoney);
    void betDatMoneySecondHand(int datMoney);
    void winMoney();
    void winMoneySecondHand();
    void loseMoney();
    void loseMoneySecondHand();
};

#endif
