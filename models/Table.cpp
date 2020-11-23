#include "Table.h"

using namespace std;

// Assembles a table, shuffles the deck of cards, and initializes so that no one has won.
Table::Table() {
	cardDeck.shuffleDeck();
	win = 0;
}

Table::~Table() {}

// Takes another card from the top of the deck.
// Not currently used
void Table::doHit(Player player) {
	Card c;
	c = cardDeck.getNextCard();
	player.addCardToHand(c);
}

// Allows a player to hold their total and end their turn. Do nothing.
// Not currently used
void Table::doStand(Player player) {}

// Splits the hand into two hands. 
// Not currently used
void Table::doSplit(Player player) {
	Card c1, c2;
	c1 = cardDeck.getNextCard();
	c2 = cardDeck.getNextCard();
	if (c1.getNumber() == c2.getNumber()) {
		player.addCardToHand(c1);
		player.addHand();
		player.addCardToHand2(c2);	
	}
}

// Returns a human's hand.
string Table :: getHumanHand(){
	string humanHandString;
	for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
		if( human.getHand().getCards().at(counter).getNumber() == 11 ){
			humanHandString = humanHandString + "J ";
		} else if (human.getHand().getCards().at(counter).getNumber() == 12) {
			humanHandString = humanHandString + "Q ";
		} else if (human.getHand().getCards().at(counter).getNumber() == 13) {
			humanHandString = humanHandString + "K ";
		} else {
			humanHandString = humanHandString + to_string(human.getHand().getCards().at(counter).getNumber()) + " ";
		}
	}
	return humanHandString;
}

// Returns a human's second hand.
string Table :: getPlayerHand(){
	string playerHandString;
	for(int counter = 0; counter < player.getHand().getCards().size(); counter++){
		if( player.getHand().getCards().at(counter).getNumber() == 11 ){
			playerHandString = playerHandString + "J ";
		} else if (player.getHand().getCards().at(counter).getNumber() == 12) {
			playerHandString = playerHandString + "Q ";
		} else if (player.getHand().getCards().at(counter).getNumber() == 13) {
			playerHandString = playerHandString + "K ";
		} else {
			playerHandString = playerHandString + to_string(player.getHand().getCards().at(counter).getNumber()) + " ";
		}
	}
	return playerHandString;
}

// Returns the dealer's hand.
string Table :: getDealerHand(){
	string dealerHandString;
	for(int counter = 0; counter < dealer.getHand().getCards().size(); counter++){
		if( dealer.getHand().getCards().at(counter).getNumber() == 11 ){
			dealerHandString = dealerHandString + "J ";
		} else if (dealer.getHand().getCards().at(counter).getNumber() == 12) {
			dealerHandString = dealerHandString + "Q ";
		} else if (dealer.getHand().getCards().at(counter).getNumber() == 13) {
			dealerHandString = dealerHandString + "K ";
		} else {
			dealerHandString = dealerHandString + to_string(dealer.getHand().getCards().at(counter).getNumber()) + " ";
		}
	}
	return dealerHandString;
}

// Checks if a player or dealer has won; returns true if they have, false if not.
// Not currently used
int Table::checkWin() {
	if (dealer.checkBlackjack() == true || human.checkBlackjack() == true) {
		return true;
	}
	else {
		return false;
	}
}

// Starts the game, configures the cards for dealer and players, provides narration of game updates as the game progresses.
void Table::runGame() {
	Output output;

	output.outputAsString("Welcome to the game!");
	output.outputAsVoice("Welcome to the game!");

	output.outputAsString("Deck has been shuffled!");
	output.outputAsVoice("Deck has been shuffled!");

	cardDeck.shuffleDeck();

	Card c1 = cardDeck.getNextCard();
	human.addCardToHand(c1);
	dealer.addCardToHand(cardDeck.getNextCard());
	Card c2 = cardDeck.getNextCard();
	Hand hand2;
	Player player(hand2);

	if (c1.getNumber() == c2.getNumber()) {
		output.outputAsString("Would you like to split your cards into two hands? ");
		output.outputAsVoice("Would you like to split your cards into two hands? ");
		string split;
		cin >> split;
		if (split == "yes") { // create a "second" player and add additional cards to human and player's hands
			player.addCardToHand(c2);
			human.addCardToHand(cardDeck.getNextCard());
			player.addCardToHand(cardDeck.getNextCard());
		}
	} 
	else {
		human.addCardToHand(c2);
	}
	dealer.addCardToHand(cardDeck.getNextCard());


	//while(!checkWin()){
	// Output initial cards in both human hand
	output.outputAsString("In your hand, you have: ");
	output.outputAsVoice("In your hand, you have: ");

	for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
		if(human.getHand().getCards().at(counter).getNumber() == 11 ){
			output.outputAsString("J");
			output.outputAsVoice("J");
		} else if (human.getHand().getCards().at(counter).getNumber() == 12) {
			output.outputAsString("Q");
			output.outputAsVoice("Q");
		} else if (human.getHand().getCards().at(counter).getNumber() == 13) {
			output.outputAsString("K");
			output.outputAsVoice("K");
		} else {
			string number = to_string(human.getHand().getCards().at(counter).getNumber());
			output.outputAsString(number);
			output.outputAsVoice(number);
		}
	}
	cout << endl;

	if (player.getHandTotal() > 0) {
		output.outputAsString("In your second hand, you have: ");
		output.outputAsVoice("In your second hand, you have: ");

		for(int counter = 0; counter < player.getHand().getCards().size(); counter++){
			if(player.getHand().getCards().at(counter).getNumber() == 11 ){
				output.outputAsString("J ");
				output.outputAsVoice("J ");
			} else if (player.getHand().getCards().at(counter).getNumber() == 12) {
				output.outputAsString("Q ");
				output.outputAsVoice("Q ");
			} else if (player.getHand().getCards().at(counter).getNumber() == 13) {
				output.outputAsString("K ");
				output.outputAsVoice("K ");
			} else {
				string number = to_string(player.getHand().getCards().at(counter).getNumber());
				output.outputAsString(number);
				output.outputAsVoice(number);
			}
		}
		cout << endl;
	}

	//Output first card in dealer's hand
	output.outputAsString("In dealer's hand, it has: ");
	output.outputAsVoice("In dealer's hand, it has: ");

	//for(int counter = 0; counter < human.getHand().getCards().size(); counter++){
	if(dealer.getHand().getCards().at(0).getNumber() == 11 ){
		output.outputAsString("J ");
		output.outputAsVoice("J ");
	} else if (dealer.getHand().getCards().at(0).getNumber() == 12) {
		output.outputAsString("Q ");
		output.outputAsVoice("Q ");
	} else if (dealer.getHand().getCards().at(0).getNumber() == 13) {
		output.outputAsString("K ");
		output.outputAsVoice("K ");
	} else {
		string number = to_string(dealer.getHand().getCards().at(0).getNumber());
		output.outputAsString(number);
		output.outputAsVoice(number);
	}
	//}
	cout << endl;


	string action;

	output.outputAsString("Would you like to stand or hit? ");
	output.outputAsVoice("Would you like to stand or hit? ");
	cin >> action;

	// Human recieves cards (hit) unitl they decide to stand
	while(action != "stand") {
		human.addCardToHand(cardDeck.getNextCard());
		output.outputAsString("In your hand, you have: ");
		output.outputAsVoice("In your hand, you have: ");

		cout << getHumanHand();
		cout << endl;

		if(human.checkBust() && (player.getHandTotal() == 0)) {
			output.outputAsString("Sorry it's a bust. Dealer Wins!");
			output.outputAsVoice("Sorry it's a bust. Dealer Wins!");
			return;
		}
		else if (human.checkBust() && (player.getHandTotal() > 0)) {
			output.outputAsString("Your first hand has busted. Continuing with second hand");
			output.outputAsVoice("Your first hand has busted. Continuing with second hand");
			action = "stand";
		}
		else if(human.checkBlackjack() && (player.getHandTotal() == 0)) {
			output.outputAsString("Coungratulations! You win!");
			output.outputAsVoice("Coungratulations! You win!");
			return;
		}

		else if (human.checkBlackjack() && (player.getHandTotal() > 0)) {
			output.outputAsString("Your first hand has won blackjack! Continuing with second hand");
			output.outputAsVoice("Your first hand has won blackjack! Continuing with second hand");
			action = "stand";
		}
		
		else {
			output.outputAsString("Would you like to stand or hit? ");
			output.outputAsVoice("Would you like to stand or hit? ");
			cin >> action;
		}

	}
	
	if (!(human.checkBust() || human.checkBlackjack())) {
		//Output initial dealer cards
		output.outputAsString("The dealer's hand has: ");
		output.outputAsVoice("The dealer's hand has: ");
		cout << getDealerHand();
		cout << endl;

		//While dealer hasn't won or lost, continue to hit
		while (!(dealer.checkBust() || dealer.checkBlackjack())) {
			if (dealer.getHand().getTotalValue() > human.getHand().getTotalValue()) {
				output.outputAsString("Sorry Dealer has greater total. Dealer wins!");
				output.outputAsVoice("Sorry Dealer has greater total. Dealer wins!");
				cout << endl;
				return;
			}

			dealer.addCardToHand(cardDeck.getNextCard());

			output.outputAsString("In dealer's hand, it has: ");
			output.outputAsVoice("In dealer's hand, it has: ");

			cout << getDealerHand();
			cout << endl;
		}

		if(dealer.checkBust()) {
			cout << "Dealer Busts. Congratulations you win!" << endl;
		}
		else if(dealer.checkBlackjack()) {
			cout << "Dealer has a Blackjack. Dealer Wins!" << endl;
		}
	}

	if (player.getHandTotal() > 0) {
		string hand2action;
		output.outputAsString("Would you like to stand or hit for your second hand? ");
		output.outputAsVoice("Would you like to stand or hit for your second hand? ");
		cin >> hand2action;

		while(hand2action != "stand") {
			player.addCardToHand(cardDeck.getNextCard());
			output.outputAsString("In your second hand, you have: ");
			output.outputAsVoice("In your second hand, you have: ");
			cout << getPlayerHand();
			cout << endl;

			if(player.checkBlackjack()) {
				output.outputAsString("Your second hand has blackjack. Congratulations! You win!");
				output.outputAsVoice("Your second hand has blackjack. Congratulations! You win!");
				return;
			}
			else if(player.checkBust()) {
				output.outputAsString("Your second hand has busted. Game over.");
				output.outputAsVoice("Your second hand has busted. Game over.");
				return;
			}
			
			output.outputAsString("Would you like to stand or hit for your second hand? ");
			output.outputAsVoice("Would you like to stand or hit for your second hand? ");
			cin >> hand2action;
		}
	}

	//Only let dealer play if human hasn't already won or lost
	if (!(player.checkBust()) || player.checkBlackjack()) {
		//Output initial dealer cards
		output.outputAsString("The dealer's hand has: ");
		output.outputAsVoice("The dealer's hand has: ");
		cout << getDealerHand();
		cout << endl;

		//While dealer hasn't won or lost, continue to hit
		while (!(dealer.checkBust() || dealer.checkBlackjack())) {
			if (dealer.getHand().getTotalValue() > player.getHand().getTotalValue()) {
				output.outputAsString("Sorry Dealer has greater total. Dealer wins!");
				output.outputAsVoice("Sorry Dealer has greater total. Dealer wins!");
				cout << endl;
				return;
			}

			dealer.addCardToHand(cardDeck.getNextCard());

			output.outputAsString("In dealer's hand, it has: ");
			output.outputAsVoice("In dealer's hand, it has: ");

			cout << getDealerHand();
			cout << endl;
		}

		if(dealer.checkBust()) {
			cout << "Dealer Busts. Congratulations you win!" << endl;
		}
		else if(dealer.checkBlackjack()) {
			cout << "Dealer has a Blackjack. Dealer Wins!" << endl;
		}
	}

	//win = 1;
	//}
}
