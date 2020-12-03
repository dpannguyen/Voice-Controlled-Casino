/**
 * @file Betting.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Betting, contains setters and getters for betting money for a player's 
 * first and second hands, methods that allow a specified amount of money to be allocated to a bet in each round, 
 * and methods that add or deduct money from the hands corresponding to wins and losses.
 */

#include "Betting.h"

/**
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

/** Betting object destructor */
Betting ::~Betting() {}

/**
 * Getter method that returns the amount of money a player has.
 * @return Int. The amount of money a player has, as an integer.
 */
int Betting ::getHumanMoney()
{
	return humanMoney;
}

/**
 * Getter method that returns the amount of money a player places as a bet.
 * @return Int. The amount of money a player places as a bet, as an integer.
 */
int Betting ::getBetMoney()
{
	return betMoney;
}

/**
 * Getter method that returns the amount of money a player places as a bet for their second hand.
 * @return The amount of money a player places as a bet for their second hand.
 */
int Betting ::getBetMoneySecondHand()
{
	return betMoneySecondHand;
}

/**
 * Checks if the amount of money a player wants to bet is less than the amount of money they have available.
 * @param money Takes in the player's amount of money left as input.
 * @return Bool. True if the player has enough money to place the bet, false if they do not have enough money to place the bet.
 */
bool Betting ::checkBetMoney(int money)
{
	if ((humanMoney - money) < 0)
		return false;
	return true;
}

/**
 * Subtracts the desired bet from the total amount of money the player has.
 * @param datMoney Input is the desired denomination of money to be used as a bet.
 * @return Void.
 */
void Betting ::betDatMoney(int datMoney)
{
	betMoney = datMoney;
	humanMoney = humanMoney - betMoney;
}

/**
 * Assigns the amount of money to be bet for the second hand to the input value datMoney.
 * Subtracts the desired bet from the total amount of money the player has.
 * @param datMoney Input is the desired denomination of money to be used as a bet for the player's second hand.
 * @return Void.
 */
void Betting ::betDatMoneySecondHand(int datMoney)
{
	betMoneySecondHand = datMoney;
	humanMoney = humanMoney - betMoneySecondHand;
}

/**
 * When a player wins, twice the amount that they bet is added to their total.
 * This method also resets the betting amount for subsequent rounds.
 * @return Void.
 */
void Betting ::winMoney()
{
	humanMoney = humanMoney + (betMoney * 2);
	betMoney = 0;
}

/**
 * When a player wins for their second hand, twice the amount that they bet is added to their total for their second hand. 
 * This method also resets the betting amount for the second hand for subsequent rounds.
 * @return Void.
 */
void Betting ::winMoneySecondHand()
{
	humanMoney = humanMoney + (betMoneySecondHand * 2); //second hand win
	betMoneySecondHand = 0;
}

/**
 * The amount of the bet is set back to 0. No money is added to the player's hand.
 * @return Void.
 */
void Betting ::loseMoney()
{
	betMoney = 0;
}

/**
 * The amount of the bet for the second hand is set back to 0. No money is added to the player's second hand.
 * @return Void.
 */
void Betting ::loseMoneySecondHand()
{
	betMoneySecondHand = 0;
}
