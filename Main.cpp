#include <iostream>
#include <string>

#include "models/Input.h"
#include "models/Output.h"
#include "models/Card.h"
#include "models/Deck.h"
#include "models/Hand.h"
#include "models/Human.h"
#include "models/Dealer.h"
#include "models/Player.h"
#include "models/Table.h"

using namespace std;

int main() {
    Input input;
    Output output;

    string command = input.inputFromVoice();
    for (unsigned int i = 0; i < command.size(); i++) {
        command[i] = tolower(command[i]);
    }
    if (command.find("blackjack") == string::npos) {
        cout << "The application is only meant to play Blackjack.\n";
        cout << endl;
        exit(1);
    }

    output.outputAsString("What would you like to know?");
    output.outputAsVoice("What would you like to know?");

    command = input.inputFromVoice();
    for (unsigned int i = 0; i < command.size(); i++) {
        command[i] = tolower(command[i]);
    }

    Table table;
    table.runGame();
    
    if ((command.find("what") != string::npos) && (command.find("my card") != string::npos)) {
        string human_hand = table.getHumanHand();
        output.outputAsVoice("Your hand contains");
        output.outputAsVoice(human_hand);

    } else if ((command.find("what") != string::npos) && (command.find("your card") != string::npos)) {
        string dealer_hand = table.getDealerHand();
        output.outputAsVoice("Dealer's hand contains");
        output.outputAsVoice(dealer_hand);

    } else if ((command.find("what") != string::npos) && ((command.find("dealer's card") != string::npos) || (command.find("dealers card") != string::npos))) {
        string dealer_hand = table.getDealerHand();
        output.outputAsVoice("Dealer's hand contains");
        output.outputAsVoice(dealer_hand);
    
    } else {
        cout << "The application could not process your voice command properly.\n";
		exit(1);
    }

}
