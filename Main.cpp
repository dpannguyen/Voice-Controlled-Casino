#include <string>
#include "models/Betting.h"
#include "models/Input.h"
#include "models/Output.h"
#include "models/Table.h"

using namespace std;

int main() {
    Input input;
    Output output;

    output.outputAsVoice("Welcome! Please speak your command.");
    string command = input.inputFromVoice();

    while (command.find("blackjack") == string::npos) {
        output.outputAsVoice("Sorry! The application is only meant to play Blackjack.");
        output.outputAsVoice("Please speak your command again.");
        command = input.inputFromVoice();
    }

    Betting *bet = new Betting();
    Table table(bet);
    command = "yes";

    while (command.find("yes") != string::npos) {
        table.runGame();
        output.outputAsVoice("Would you like to play again?");
        command = input.inputFromVoice();
        while (command.find("yes") == string::npos && command.find("no") == string::npos) {
            output.outputAsVoice("Sorry! Please speak your command again.");
            output.outputAsVoice("Would you like to play again?");
            command = input.inputFromVoice();
        }
    }

    delete bet;
    output.outputAsVoice("Application has ended. Thank you for playing!");
    return 0;
}
