#ifndef BETTING_H
#define BETTING_H

class Betting{
    private:
        int humanMoney;		//money player currently have
        int betMoney;		//money that is on the bet
        int betMoneySecondHand;	//money that is on the bet for second hand
    
    public:
        Betting();
        ~Betting();

        int getHumanMoney();  //a getter method for in case humanMoney is requested
        int getBetMoney();  //a getter method for in case betMoney is requested
        int getBetMoneySecondHand();	//a getter moethod for in case betMoneySecondHand is requested
        bool checkBetMoney(int money);
        void betDatMoney(int datMoney);	//ask player how much money they want to bet
        void betDatMoneySecondHand(int datMoney);	//ask player how muh money they want to bet on second hand
        void winMoney();	//if player wins the game, winMoney deals with betting
        void winMoneySecondHand();	//if player wins the second hand
        void loseMoney();	//if player loses the game, loseMoney deals with betting
        void loseMoneySecondHand();	//if player loses second hand
};

#endif
