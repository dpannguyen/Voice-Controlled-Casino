/**
 * @file Table.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Table that automatically shuffles the deck. Contains a constructor that facillitates Betting.
 * Contains methods that run the game and deal cards to Players and Dealer.
 * Contains methods that allow a Player to Hit, Bet, play their Hand, and Split their Hand.
 * Contains a method that allows the Dealer to play.
 * Contains a method that returns the cards a Player has in their Hand.
 */

#include "Table.h"

using namespace std;

/**
 * Constructor for a Table object. Shuffles the deck of cards.
 */
Table::Table()
{
	cardDeck = cardDeck->instance();
}

/**
 * Shuffles the deck of cards and initializes the bet value.
 * @param betting A pointer to the Betting object that represents the amount of money a Player is betting in a round of Blackjack.
 */
Table::Table(Betting *betting)
{
	cardDeck = cardDeck->instance();
	bet = betting;
}

/**
 * Destructor for a Table object.
 */
Table::~Table() {}

/**
 * Adds a card to the player's hand.
 * @param player A pointer to the Player object whose Hand is to be added to.
 */
void Table::doHit(Player *player)
{
	player->addCardToHand(cardDeck->getNextCard());
}

/**
 * Converts the face cards from their respective number values to J, Q, or K to more accurately represent a Deck of Cards.
 * Loops through the Player's Hand until all Cards have been accounted for.
 * Adds all of the Cards to a string. That string is then converted into speech output via the outputAsVoice method.
 * @param player A pointer to the Player object whose Hand contents are to be returned.
 * @return Void.
 */
void Table ::getCardsInHand(Player *player)
{
	vector<Card> handCards = player->getHandCards();
	string handName = player->getHandName();
	string handString;

	/** Loops through all of the cards in the hand */
	for (int counter = 0; counter < handCards.size(); counter++)
	{
		string number = to_string(handCards.at(counter).getNumber());

		/** Converts face cards from number to letter values */
		if (number == "11")
			handString = handString + "J ";
		else if (number == "12")
			handString = handString + "Q ";
		else if (number == "13")
			handString = handString + "K ";
		else
			handString = handString + number + " ";
	}
	/** Outputs the player's hand name and the cards in the hand as voice */
	output.outputAsVoice("In your " + handName + ", there are: " + handString);
}

/**
 * Tells the Player their total money via speech output, asks how much they would like to bet, checks to see if they have 
 * enough money to place the desired bet, and if so, adds the money to the bet and speaks the amount they have bet.
 * If not, informs the Player via speech that they cannot place the requested bet.
 * Handles errors if the speech is unclear or invalid and therefore cannot be processed. 
 * @param handName A string that signifies which Hand they are placing a bet for.
 * @return Void.
 */
void Table::doBet(string handName)
{
	/** Outputs as voice the total money in the player's hand */
	output.outputAsVoice("Your total money is " + to_string(bet->getHumanMoney()) + "!");
	/** Asks user how much they would like to bet */
	output.outputAsVoice("How much would you like to bet for your " + handName + "?");
	output.outputAsVoice("Say 1 for 100, 2 for 500, 3 for 1000, and 0 for 0");

	int humanBet = -1;
	int betMoney = 0;
	while (true)
	{
		try
		{
			string betOption = input.inputFromVoice();
			betOption.erase(betOption.find_last_not_of(".") + 1);
			humanBet = stoi(betOption);

			/** If the user input is within the acceptable range, put the corresponding amount of money into the betMoney variable */
			if (humanBet >= 0 && humanBet <= 3)
			{
				if (humanBet == 1)
					betMoney = 100;
				else if (humanBet == 2)
					betMoney = 500;
				else if (humanBet == 3)
					betMoney = 1000;

				/** Method checkBetMoney will determine if they have enough money to place the desired bet */
				if (bet->checkBetMoney(betMoney))
					break;
				/** If they do not have enough, notify them via speech output that it isn't possible */
				else
					output.outputAsVoice("You do not have enough money for that bet.");
			}
		}
		catch (invalid_argument const &e)
		{
		}

		/** Error handling in case the speech is not one of the aforementioned options, or is unintelligible */
		output.outputAsVoice("Sorry! Please speak your command again.");
		/** Gives the user another chance to speak an acceptable response */
		output.outputAsVoice("How much would you like to bet?");
		output.outputAsVoice("Say 1 for 100, 2 for 500, 3 for 1000, and 0 for 0");
	}

	/** Handles the bet for the second hand */
	if (handName == "second hand")
		bet->betDatMoneySecondHand(betMoney);
	else
		bet->betDatMoney(betMoney);
	/** Notifies the user via speech output how much they have bet for the specific hand */
	output.outputAsVoice("You have bet " + to_string(betMoney) + " for your " + handName + ".");
}

/**
 * Deals two cards to the Player's first hand. If those Cards have the same value, the Player has the option to split the Cards
 * into two Hands and add a second card to each Hand. If this option is chosen, then the second Card dealt is removed from the first 
 * Hand and is added to the second Hand, and an additional Card is added to each. Then, two Cards are dealt to the Dealer.
 * @param firstHand A pointer to the Hand object that is the Player's first Hand
 * @param secondHand A pointer to the Hand object that is the Player's second Hand
 * @param dealer A poitner to the Hand object that is the Dealer's hand
 * @return Void.
 */
void Table::dealCards(Player *firstHand, Player *secondHand, Player *dealer)
{
	Hand hand1;
	firstHand->setHand(hand1);
	Card card1 = cardDeck->getNextCard();
	Card card2 = cardDeck->getNextCard();
	firstHand->addCardToHand(card1);
	firstHand->addCardToHand(card2);
	getCardsInHand(firstHand);

	/** If the cards have the same value, then the Player has the option to split the cards into two hands */
	if (card1.getNumber() == card2.getNumber())
	{
		/** Asks if the user would like to do this */
		output.outputAsVoice("Would you like to split your cards into two hands?");
		/** Accepts speech response as answer to above question */
		string split = input.inputFromVoice();

		/** If the answer is invalid, ask again and give the user another chance to speak a valid response */
		while (split.find("yes") == string::npos && split.find("no") == string::npos)
		{
			output.outputAsVoice("Sorry! Please speak your command again.");
			output.outputAsVoice("Would you like to split your cards into two hands?");
			split = input.inputFromVoice();
		}

		if (split.find("yes") != string::npos)
		{ /** create a "second" player and add additional cards to human and player's hands */

			secondHandExists = true;

			firstHand->setHandName("first hand");
			/** Remove the previously added card from the first hand */
			firstHand->removeLastCardFromHand(card2);
			firstHand->addCardToHand(cardDeck->getNextCard());
			getCardsInHand(firstHand);

			Hand hand2("second hand");
			secondHand->setHand(hand2);
			/** Add the card that was removed from the first hand to the second hand */
			secondHand->addCardToHand(card2);
			secondHand->addCardToHand(cardDeck->getNextCard());
			getCardsInHand(secondHand);
		}
	}

	/** Deal two cards to the dealer */
	Hand dealerHand("dealer's hand");
	dealer->setHand(dealerHand);
	dealer->addCardToHand(cardDeck->getNextCard());
	dealer->addCardToHand(cardDeck->getNextCard());
	getCardsInHand(dealer);
}

/**
 * Method that notifies the Player it is their turn to play via voice output, specifies if it is their second Hand that is playing,
 * places the desired bet, asks them if they would like to stand (end their turn) or hit (be dealt another card), accepts voice input
 * to determine which option they have picked, continues dealing cards until they have Busted, won Blackjack, or have chosen
 * to Stand. A boolean variable keeps track of whether or not the game is over in the case of Busting or winning Blackjack.
 * @param hand A pointer to the Player object representing the Hand that is to be played.
 * @return bool. True if the Player has won Blackjack or has Busted and the game is over, false if not.
 */
bool Table::playHand(Player *hand)
{
	/** Notify user it is their turn to play, and specify if they are playing their second hand */
	output.outputAsVoice("It is your turn to play.");
	string handName = hand->getHandName();
	if (secondHandExists)
		output.outputAsVoice("You are playing " + handName + ".");

	getCardsInHand(hand);
	doBet(handName);
	int betMoney;
	/** Bet for the first or second hand */
	if (handName == "second hand")
		betMoney = bet->getBetMoneySecondHand();
	else
		betMoney = bet->getBetMoney();

	/** Prompt user player for their move */
	output.outputAsVoice("Would you like to stand or hit?");
	string action = input.inputFromVoice();

	/** Error handling if user response is unintelligible or invalid, with option for them to try again */
	while (action.find("hit") == string::npos && action.find("stand") == string::npos)
	{
		output.outputAsVoice("Sorry! Please speak your command again.");
		output.outputAsVoice("Would you like to stand or hit?");
		action = input.inputFromVoice();
	}

	/** player recieves cards (hit) unitl they decide to stand */
	while (action.find("hit") != string::npos)
	{
		doHit(hand);
		getCardsInHand(hand);

		/** Check if the player has busted, if so, notify them the relevant hand has busted, the amount of money they have lost, and 
		 * return boolean true because the game is over for this hand */
		if (hand->checkBust())
		{
			output.outputAsVoice("Sorry! Your " + handName + " is a bust.");
			output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand")
				bet->loseMoneySecondHand();
			else
				bet->loseMoney();
			return true;
		}
		/** Check if the player has won Blackjack, if so, notify them of this, the amount of money they have won, and 
		 * return boolean true because the game is over for this hand */
		else if (hand->checkBlackjack())
		{
			output.outputAsVoice("Coungratulations! Your " + handName + " has hit blackjack! You win!");
			output.outputAsVoice("You won " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand")
				bet->winMoneySecondHand();
			else
				bet->winMoney();
			return true;
		}
		/** Otherwise, keep asking if the player would like to stand or hit */
		else
		{
			output.outputAsVoice("Would you like to stand or hit?");
			action = input.inputFromVoice();
			while (action.find("hit") == string::npos && action.find("stand") == string::npos)
			{
				output.outputAsVoice("Sorry! Please speak your command again.");
				output.outputAsVoice("Would you like to stand or hit?");
				action = input.inputFromVoice();
			}
		}
	}
	return false;
}

/**
 * Method that notifies the Player it is the Dealer's turn to play. Places the desired bet. Continues to deal cards to the Dealer (hit)
 * as long as the Dealer hasn't Busted or won Blackjack. If the Dealer has won or lost, the user is notified of this via speech output.
 * In this case, the game is over.
 * Otherwise, compares the total of the Player's Hand to the Dealer's Hand. If the Dealer's Hand has a higher value, 
 * they have won and the game is over and the user is notified of such. Adjusts the Player's bet according to a win or a loss. 
 * @param dealer A pointer to the dealer Player object
 * @param player A pointer to the user Player object
 * @return Void.
 */
void Table::playDealer(Player *dealer, Player *player)
{
	/** Voice output that notifies it is the dealer's turn to play, and outputs the cards in the dealer's hand */
	output.outputAsVoice("It is dealer's turn to play.");
	getCardsInHand(dealer);

	string handName = player->getHandName();
	int betMoney;
	if (handName == "second hand")
		betMoney = bet->getBetMoneySecondHand();
	else
		betMoney = bet->getBetMoney();

	/** While dealer hasn't won or lost, continue to hit */
	while (!(dealer->checkBust() || dealer->checkBlackjack()))
	{
		int dealerHandTotal = dealer->getHandTotal();
		int playerHandTotal = player->getHandTotal();
		/** Compare the dealer's hand to the player's hand
		 * If the dealer's hand total is greater, notify the player they have lost via speech output
		 * Notify them of the amount of money they have lost via speech output */
		if (dealerHandTotal > playerHandTotal)
		{
			output.outputAsVoice("Sorry! Dealer has greater total. Dealer wins!");
			output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
			if (handName == "second hand")
				bet->loseMoneySecondHand();
			else
				bet->loseMoney();
			return;
		}

		output.outputAsVoice("Dealer decides to hit.");
		doHit(dealer);
		getCardsInHand(dealer);
	}
	/** Every time a card is dealt to the Dealer, checks if the Dealer has Blackjack or has Busted. If so, game is over. 
	 * Notify the user that they have won or lost, and of the amount of money they have gained or lost, respectively. */
	if (dealer->checkBust())
	{
		output.outputAsVoice("Dealer busts. Congratulations! You win!");
		output.outputAsVoice("You won " + to_string(betMoney) + " from your " + handName + "!");
		if (handName == "second hand")
			bet->winMoneySecondHand();
		else
			bet->winMoney();
	}
	else if (dealer->checkBlackjack())
	{
		output.outputAsVoice("Sorry! Dealer has hit blackjack! Dealer wins!");
		output.outputAsVoice("You lost " + to_string(betMoney) + " from your " + handName + "!");
		if (handName == "second hand")
			bet->loseMoneySecondHand();
		else
			bet->loseMoney();
	}
}

/**
 * Method that overrides the previous playDealer method in the case that a Player has split their hand and has 2 hands.
 * It notifies the Player it is the Dealer's turn to play. Places the desired bets for both hands. 
 * Continues to deal cards to the Dealer (hit) as long as the Dealer hasn't Busted or won Blackjack. 
 * If the Dealer has won or lost, the user is notified of this via speech output. In this case, the game is over.
 * Otherwise, compares the total of each of the Player's Hand to the Dealer's Hand. If the Dealer's Hand has a higher value, 
 * they have won and the game is over for that hand and the user is notified of such. 
 * Plays through until both hands have either won or lost. 
 * Adjusts the Player's bets for each hand according to a win or a loss. 
 * @param dealer A pointer to the dealer Player object
 * @param hand1 A pointer to the Player's first hand
 * @param hand2 A poitner to the Player's second hand
 * @return Void.
 */
void Table::playDealer(Player *dealer, Player *hand1, Player *hand2)
{
	/** Voice output that notifies it is the dealer's turn to play, and outputs the cards in the dealer's hand */
	output.outputAsVoice("It is dealer's turn to play.");
	getCardsInHand(dealer);

	/** Boolean variables to determine if the method should keep playing through for each hand; while false, continue */
	bool firstHandLost = false;
	bool secondHandLost = false;

	/** While dealer hasn't won or lost, continue to hit (deal cards) */
	while (!(dealer->checkBust() || dealer->checkBlackjack()))
	{
		int dealerHandTotal = dealer->getHandTotal();
		int playerHand1Total = hand1->getHandTotal();
		int playerHand2Total = hand2->getHandTotal();

		/** While the first hand hasn't lost, compare the dealer's hand to the player's hand
		 * If the dealer's hand total is greater, notify the player they have lost via speech output
		 * Notify them of the amount of money they have lost via speech output
		 * Change the firstHandLost flag to true, so this hand will not be compared against again */
		if (!firstHandLost && (dealerHandTotal > playerHand1Total))
		{
			output.outputAsVoice("Sorry! Dealer has greater total than your first hand. First hand loses.");
			output.outputAsVoice("You lost " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->loseMoney();
			firstHandLost = true;
		}

		/** While the second hand hasn't lost, compare the dealer's hand to the player's hand
		 * If the dealer's hand total is greater, notify the player they have lost via speech output
		 * Notify them of the amount of money they have lost via speech output
		 * Change the secondHandLost flag to true, so this hand will not be compared against again */
		if (!secondHandLost && (dealerHandTotal > playerHand2Total))
		{
			output.outputAsVoice("Sorry! Dealer has greater total than your second hand. Second hand loses.");
			output.outputAsVoice("You lost " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->loseMoneySecondHand();
			secondHandLost = true;
		}

		/** return from the method if both hands have lost */
		if (firstHandLost & secondHandLost)
			return;
		/** otherwise, keep dealing cards to dealer and notify the user of this */
		else
		{
			output.outputAsVoice("Dealer decides to hit.");
			doHit(dealer);
			getCardsInHand(dealer);
		}
	}

	/** Check if the dealer has busted, if so, game over. Notify the user of win via speech output and amount of money they won */
	if (dealer->checkBust())
	{
		output.outputAsVoice("Dealer busts. Congratulations! You win!");
		if (!firstHandLost)
		{
			output.outputAsVoice("You won " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->winMoney();
		}
		if (!secondHandLost)
		{
			output.outputAsVoice("You won " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->winMoneySecondHand();
		}
		return;
	}
	/** Check if the dealer has won, if so, game over. Notify the user of loss via speech output and amount of money they lost */
	else if (dealer->checkBlackjack())
	{
		output.outputAsVoice("Sorry! Dealer has hit blackjack! Dealer wins!");
		if (!firstHandLost)
		{
			output.outputAsVoice("You lost " + to_string(bet->getBetMoney()) + " from your first hand!");
			bet->loseMoney();
		}
		if (!secondHandLost)
		{
			output.outputAsVoice("You lost " + to_string(bet->getBetMoneySecondHand()) + " from your second hand!");
			bet->loseMoneySecondHand();
		}
		return;
	}
}

/**
 * Method that initiates Blackjack.
 * @return Void. 
 */
void Table::runGame()
{
	/** Voice output that welcomes the user to the game and notifies them the deck has been shuffled */
	output.outputAsVoice("Welcome to the game!");
	output.outputAsVoice("Deck has been shuffled!");
	cardDeck->shuffleDeck();

	/** initialize Player objects representing the first hand, second hand (in the event of a split), and Dealer */
	Player firstHand;
	Player secondHand;
	Player dealer;

	/** Distribute cards to the Players using dealCards method */
	dealCards(&firstHand, &secondHand, &dealer);

	/** Use a boolean value returned by the playHand method to determine if the hand has won or lost.
	 * If true, the game is over. If false, continue.
	 */
	bool hand1done = playHand(&firstHand);

	/** Use helper method secondHandExists to determine if the player has split their cards into two hands 
	 * If not, and the game isn't over as determined by the boolean hand1done variable, let the dealer play
	*/
	if (!secondHandExists)
	{
		if (!hand1done)
			playDealer(&dealer, &firstHand);
	}

	else
	{
		/** Use boolean variable to determine if second hand has won or lost, or if game continues */
		bool hand2done = playHand(&secondHand);
		/** If hand 1 is done and hand 2 isn't, play the dealer against the second hand */
		if (hand1done && !hand2done)
			playDealer(&dealer, &secondHand);
		/** If hand 1 isn't done and hand 2 is, play the dealer against the first hand */
		else if (!hand1done && hand2done)
			playDealer(&dealer, &firstHand);
		/** If hand 1 isn't done and hand 2 also isn't, play the dealer against both hands */
		else if (!hand1done && !hand2done)
			playDealer(&dealer, &firstHand, &secondHand);
	}

	/** Output as voice command the total money the player has at the end of the game */
	output.outputAsVoice("Your total money is now " + to_string(bet->getHumanMoney()) + "!");
}
