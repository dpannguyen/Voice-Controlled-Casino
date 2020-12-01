#include "Betting.h"

Betting :: Betting(){
	humanMoney = 5000;	//the money user currently have, we set 5000 as our initial player money
	betMoney = 0;		//the money player is betting for
	betMoneySecondHand = 0;	//the money second hand is betting for
}

Betting :: ~Betting() {}

int Betting :: getHumanMoney(){		//a getter method for in case humanMoney is requested
	return humanMoney;
}

int Betting :: getBetMoney(){		//a getter method for in case money on the line is requested
	return betMoney;
}

int Betting :: getBetMoneySecondHand(){	//a getter method for in second hand bet is requested
	return betMoneySecondHand;
}

bool Betting :: checkBetMoney(int money) {
	if ((humanMoney - money) < 0) return false;
	return true;
}

void Betting :: betDatMoney(int datMoney){	//the human bet datMoney amount of money
	betMoney = datMoney;			//into the game, it will subtract from
	humanMoney = humanMoney - betMoney;	//human money and store it into betMoney
}

void Betting :: betDatMoneySecondHand(int datMoney){	//the human bet datMoney amount of money
	betMoneySecondHand = datMoney;			//on second hand,  it will subtract from
	humanMoney = humanMoney - betMoneySecondHand;	//human money and store it into betMoney
}

void Betting :: winMoney(){
	humanMoney = humanMoney + (betMoney * 2);	//if the human wins, they get double the
	betMoney = 0;					//amount they bet for then reset the
}							//game betMoney

void Betting :: winMoneySecondHand(){
	humanMoney = humanMoney + (betMoneySecondHand * 2);	//second hand win
	betMoneySecondHand = 0;
}

void Betting :: loseMoney(){
	betMoney = 0;	//if the human loses, they lose their bet money
}

void Betting :: loseMoneySecondHand(){
	betMoneySecondHand = 0;	//if the human loses on second hand, they lose their bet money
}
