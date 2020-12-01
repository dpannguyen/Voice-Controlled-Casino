#include "Table.h"

using namespace std;

// Assembles a table, shuffles the deck of cards, and initializes so that no one has won.
Table::Table()
{
	cardDeck.shuffleDeck();
}

Table::Table(Betting *betting) {
	cardDeck.shuffleDeck();
	bet = betting;
}

Table::~Table() {}

// Takes another card from the top of the deck.
void Table::doHit(Player *player)
{
	player->addCardToHand(cardDeck.getNextCard());
}

// Returns a player's hand.
void Table ::getCardsInHand(Player *player)
{
	vector<Card> handCards = player->getHandCards();
	string handName = player->getHandName();
	string handString;

	for (int counter = 0; counter < handCards.size(); counter++)
	{
		string number = to_string(handCards.at(counter).getNumber());

		if (number == "11") handString = handString + "J ";
		else if (number == "12") handString = handString + "Q ";
		else if (number == "13") handString = handString + "K ";
		else handString = handString + number + " ";
	}
	output.outputAsVoice("In your " + handName + ", there are: " + handString);
}

void Table::doBet(string handName) {
	output.outputAsVoice("Your total money is " + to_string(bet->getHumanMoney()) + "!");
	output.outputAsVoice("How much would you like to bet for your " + handName + "?");
	output.outputAsVoice("Say 1 for 100, 2 for 500, 3 for 1000, and 0 for 0");

	int humanBet = -1;
	int betMoney = 0;
	while (true) {
		try {
			string betOption = input.inputFromVoice();
			betOption.erase(betOption.find_last_not_of(".") + 1);
			humanBet = stoi(betOption);

			if (humanBet >= 0 && humanBet <= 3) {
				if (humanBet == 1) betMoney = 100;
				else if (humanBet == 2) betMoney = 500; 
				else if (humanBet == 3) betMoney = 1000; 

				if (bet->checkBetMoney(betMoney)) break;
				else output.outputAsVoice("You do not have enough money for that bet.");
			}
		} catch (invalid_argument const &e) {}

		output.outputAsVoice("Sorry! Please speak your command again.");
		output.outputAsVoice("How much would you like to bet?");
		output.outputAsVoice("Say 1 for 100, 2 for 500, 3 for 1000, and 0 for 0");
	}

	if (handName == "second hand") bet->betDatMoneySecondHand(betMoney);
	else bet->betDatMoney(betMoney);
	output.outputAsVoice("You have bet " + to_string(betMoney) + " for your " + handName + ".");
}

void Table::dealCards(Player *firstHand, Player *secondHand, Player *dealer) {
	Hand hand1;
	firstHand->setHand(hand1);
	Card card1 = cardDeck.getNextCard();
	Card card2 = cardDeck.getNextCard();
	firstHand->addCardToHand(card1);
	firstHand->addCardToHand(card2);
	getCardsInHand(firstHand);
	

	if (card1.getNumber() == card2.getNumber())
	{
		output.outputAsVoice("Would you like to split your cards into two hands?");
		string split = input.inputFromVoice();

		while (split.find("yes") == string::npos && split.find("no") == string::npos) {
			output.outputAsVoice("Sorry! Please speak your command again.");
			output.outputAsVoice("Would you like to split your cards into two hands?");
			split = input.inputFromVoice();
		}

		if (split.find("yes") != string::npos)
		{ // create a "second" player and add additional cards to human and player's hands

			secondHandExists = true;

			firstHand->setHandName("first hand");
			firstHand->removeLastCardFromHand(card2);
			firstHand->addCardToHand(cardDeck.getNextCard());
			getCardsInHand(firstHand);

			Hand hand2("second hand");
			secondHand->setHand(hand2);
			secondHand->addCardToHand(card2);
			secondHand->addCardToHand(cardDeck.getNextCard());
			getCardsInHand(secondHand);
		}
	}

	Hand dealerHand("dealer's hand");
	dealer->setHand(dealerHand);
	dealer->addCardToHand(cardDeck.getNextCard());
	dealer->addCardToHand(cardDeck.getNextCard());
	getCardsInHand(dealer);
}

bool Table::playHand(Player *hand)
{
	output.outputAsVoice("It is your turn to play.");
	string handName = hand->getHandName();
	if (secondHandExists) output.outputAsVoice("You are playing " + handName + ".");
	
	getCardsInHand(hand);
	doBet(handName);
	int betMoney;
	if (handName == "second hand") betMoney = bet->getBetMoneySecondHand();
	else betMoney = bet->getBetMoney();

	output.outputAsVoice("Would you like to stand or hit?");
	string action = input.inputFromVoice();

	while (action.find("hit") == string::npos && action.find("stand") == string::npos) {
		output.outputAsVoice("Sorry! Please speak your command again.");
		output.outputAsVoice("Would you like to stand or hit?");
		action = input.inputFromVoice();
	}

	// player recieves cards (hit) unitl they decide to stand
	while (action.find("hit") != string::npos)
	{
		doHit(hand);
		getCardsInHand(hand);

		if (hand->checkBust())
		{
			output.outputAsVoice("Sorry! Your " + handName + " is a bust.");
			output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand") bet->loseMoneySecondHand();
			else bet->loseMoney();
			return true;
		}
		else if (hand->checkBlackjack())
		{
			output.outputAsVoice("Coungratulations! Your " + handName + " has hit blackjack! You win!");
			output.outputAsVoice("You won " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand") bet->winMoneySecondHand();
			else bet->winMoney();
			return true;
		}
		else
		{
			output.outputAsVoice("Would you like to stand or hit?");
			action = input.inputFromVoice();
			while (action.find("hit") == string::npos && action.find("stand") == string::npos) {
				output.outputAsVoice("Sorry! Please speak your command again.");
				output.outputAsVoice("Would you like to stand or hit?");
				action = input.inputFromVoice();
			}
		}
	}
	return false;
}

void Table::playDealer(Player *dealer, Player *player)
{
	output.outputAsVoice("It is dealer's turn to play.");
	getCardsInHand(dealer);

	string handName = player->getHandName();
	int betMoney;
	if (handName == "second hand") betMoney = bet->getBetMoneySecondHand();
	else betMoney = bet->getBetMoney();

	//While dealer hasn't won or lost, continue to hit
	while (!(dealer->checkBust() || dealer->checkBlackjack()))
	{
		int dealerHandTotal = dealer->getHandTotal();
		int playerHandTotal = player->getHandTotal();
		if (dealerHandTotal > playerHandTotal)
		{
			output.outputAsVoice("Sorry! Dealer has greater total. Dealer wins!");
			output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand") bet->loseMoneySecondHand();
			else bet->loseMoney();
			return;
		}

		output.outputAsVoice("Dealer decides to hit.");
		doHit(dealer);
		getCardsInHand(dealer);
	}

	if (dealer->checkBust())
	{
		output.outputAsVoice("Dealer busts. Congratulations! You win!");
		output.outputAsVoice("You won " + to_string(betMoney) + " from your " + handName + "!");
		if (handName == "second hand") bet->winMoneySecondHand();
		else bet->winMoney();
	}
	else if (dealer->checkBlackjack())
	{
		output.outputAsVoice("Sorry! Dealer has hit blackjack! Dealer wins!");
		output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
		if (handName == "second hand") bet->loseMoneySecondHand();
		else bet->loseMoney();
	}
}

void Table::playDealer(Player *dealer, Player *hand1, Player *hand2)
{
	output.outputAsVoice("It is dealer's turn to play.");
	getCardsInHand(dealer);

	//Output initial dealer cards
	bool firstHandLost = false;
	bool secondHandLost = false;

	//While dealer hasn't won or lost, continue to hit
	while (!(dealer->checkBust() || dealer->checkBlackjack()))
	{
		int dealerHandTotal = dealer->getHandTotal();
		int playerHand1Total = hand1->getHandTotal();
		int playerHand2Total = hand2->getHandTotal();

		if (!firstHandLost && (dealerHandTotal > playerHand1Total))
		{
			output.outputAsVoice("Sorry! Dealer has greater total than your first hand. First hand loses.");
			output.outputAsVoice("You lost " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->loseMoney();
			firstHandLost = true;
		}

		if (!secondHandLost && (dealerHandTotal > playerHand2Total))
		{
			output.outputAsVoice("Sorry! Dealer has greater total than your second hand. Second hand loses.");
			output.outputAsVoice("You lost " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->loseMoneySecondHand();
			secondHandLost = true;
		}

		if (firstHandLost & secondHandLost) return;
		else
		{
			output.outputAsVoice("Dealer decides to hit.");
			doHit(dealer);
			getCardsInHand(dealer);
		}
	}

	if (dealer->checkBust())
	{
		output.outputAsVoice("Dealer busts. Congratulations! You win!");
		if (!firstHandLost) {
			output.outputAsVoice("You won " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->winMoney();
		}
		if (!secondHandLost) {
			output.outputAsVoice("You won " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->winMoneySecondHand();
		}
		return;
	}
	else if (dealer->checkBlackjack())
	{
		output.outputAsVoice("Sorry! Dealer has hit blackjack! Dealer wins!");
		if (!firstHandLost) {
			output.outputAsVoice("You lost " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->loseMoney();
		}
		if (!secondHandLost) {
			output.outputAsVoice("You lost " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->loseMoneySecondHand();
		}
		return;
	}
}


// Starts the game, configures the cards for dealer and players, provides narration of game updates as the game progresses.
void Table::runGame()
{
	output.outputAsVoice("Welcome to the game!");
	output.outputAsVoice("Deck has been shuffled!");
	cardDeck.shuffleDeck();
	
	Player firstHand;
	Player secondHand;
	Player dealer;

	dealCards(&firstHand, &secondHand, &dealer);

	bool hand1done = playHand(&firstHand);
	
	//Only let dealer play if human's first hand hasn't already won or lost
	if (!secondHandExists) {
		if (!hand1done) playDealer(&dealer, &firstHand);
	
	//Only let dealer play if human hasn't already won or lost
	} else {
		bool hand2done = playHand(&secondHand);
		if (hand1done && !hand2done) playDealer(&dealer, &secondHand);
		else if (!hand1done && hand2done) playDealer(&dealer, &firstHand);
		else if (!hand1done && !hand2done) playDealer(&dealer, &firstHand, &secondHand);
	}

	output.outputAsVoice("Your total money is now " + to_string(bet->getHumanMoney()) + "!");
}
