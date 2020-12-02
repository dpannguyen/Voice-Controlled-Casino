/**
 * @file Betting.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief File containing code that allows a user to place a bet while playing Blackjack.
 * 
 * This file initializes an object of class Betting, contains setters and getters for betting money for a player's 
 * first and second hands, methods that allow a specified amount of money to be allocated to a bet in each round, 
 * and methods that add or deduct money from the hands corresponding to wins and losses.
 */

#include "Betting.h"

/**
 * @brief Constructor for a betting object. 
 * Initializes money that the player currently has. The default is 5000.
 * Initializes betMoney (the money player places as a bet during a round) to 0.
 * Initializes betMoneySecondHand (the money player places as a bet when their hand has been split) to 0.
 */
Betting ::Betting()
{
	humanMoney = 5000;
	betMoney = 0;
	betMoneySecondHand = 0;
}

/**
 * @brief Destructor for a betting object.
 */
Betting ::~Betting() {}

/**
 * @brief Getter method that returns the amount of money a player has.
 * @return The amount of money a player has.
 */
int Betting ::getHumanMoney()
{
	return humanMoney;
}

/**
 * @brief Getter method that returns the amount of money a player has placed as a bet.
 * @return The amount of money a player places as a bet.
 */
int Betting ::getBetMoney()
{
	return betMoney;
}

/**
 * @brief Getter method that returns the amount of money a player has placed as a bet in the case of a split for their second hand.
 * @return The amount of money a player places as a bet for their second hand.
 */
int Betting ::getBetMoneySecondHand()
{
	return betMoneySecondHand;
}

/**
 * @brief Checks if the player has enough money left to place a certain bet. 
 * @param money Takes in the player's amount of money left as input.
 * @return A boolean value: true if the player has enough money to place the bet, false if they do not have enough money to place the bet.
 */
bool Betting ::checkBetMoney(int money)
{
	if ((humanMoney - money) < 0)
		return false;
	return true;
}

/**
 * @brief Allows a player to bet a specified amount of money during a round of Blackjack.
 * @param datMoney Input is the desired denomination of money to be used as a bet.
 * @return Void.
 * Subtracts the desired bet from the total amount of money the player has.
 */
void Betting ::betDatMoney(int datMoney)
{
	betMoney = datMoney;
	humanMoney = humanMoney - betMoney;
}

/**
 * @brief Allows a player to bet a specified amount of money for their second hand in the event of a split.
 * @param datMoney Input is the desired denomination of money to be used as a bet for the player's second hand.
 * @return Void.
 * Assigns the amount of money to be bet for the second hand to the input value datMoney.
 * Subtracts the desired bet from the total amount of money the player has.
 */
void Betting ::betDatMoneySecondHand(int datMoney)
{
	betMoneySecondHand = datMoney;
	humanMoney = humanMoney - betMoneySecondHand;
}

/**
 * @brief Adds money to a player's total money when they win a round of Blackjack.
 * @return Void.
 * When a player wins, twice the amount that they bet is added to their total.
 * This method also resets the betting amount for subsequent rounds.
 */
void Betting ::winMoney()
{
	humanMoney = humanMoney + (betMoney * 2);
	betMoney = 0;
}

/**
 * @brief Adds money to a player's total money in their second hand when they win a round of Blackjack.
 * @return Void.
 * When a player wins for their second hand, twice the amount that they bet is added to their total for their second hand. 
 * This method also resets the betting amount for the second hand for subsequent rounds.
 */
void Betting ::winMoneySecondHand()
{
	humanMoney = humanMoney + (betMoneySecondHand * 2); //second hand win
	betMoneySecondHand = 0;
}

/**
 * @brief When the player has lost, resets the amount the player has bet to 0 for subsequent rounds. 
 * @return Void.
 * The amount of the bet is set back to 0. No money is added to the player's hand.
 */
void Betting ::loseMoney()
{
	betMoney = 0;
}

/**
 * @brief When the player has lost for their second hand, resets the amount the player has bet to 0 for subsequent rounds.
 * @return Void.
 * The amount of the bet for the second hand is set back to 0. No money is added to the player's second hand.
 */
void Betting ::loseMoneySecondHand()
{
	betMoneySecondHand = 0;
}
