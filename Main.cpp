/**
 * @file Main.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Main file that initializes a game of Blackjack when the user asks it to.
 */

#include <string>
#include "models/Betting.h"
#include "models/Input.h"
#include "models/Output.h"
#include "models/Table.h"

using namespace std;

int main()
{
    Input input;
    Output output;

    /** The application welcomes the user to the game. The application recognizes the user's speech input and starts the game when 
     * the user says "blackjack". Other speech is regarded as invalid. */
    output.outputAsVoice("Welcome! Please speak your command.");
    string command = input.inputFromVoice();

    while (command.find("blackjack") == string::npos)
    {
        output.outputAsVoice("Sorry! The application is only meant to play Blackjack.");
        output.outputAsVoice("Please speak your command again.");
        command = input.inputFromVoice();
    }

    /** Initializes the user's bet for the game */
    Betting *bet = new Betting();
    Table table(bet);
    command = "yes";

    /** The game will be run as long as the user's voice input is "yes", signaling they would like to keep playing */
    while (command.find("yes") != string::npos)
    {
        /** The game is run via the rungame method of the table class */
        table.runGame();
        /** When the user has played through, they are given the option to play again */
        output.outputAsVoice("Would you like to play again");
        command = input.inputFromVoice();
        while (command.find("yes") == string::npos && command.find("no") == string::npos)
        {
	    output.outputAsVoice("Sorry! Please speak your command again.");
            output.outputAsVoice("Would you like to play again");
            command = input.inputFromVoice();
        }
    }

    /** When the user decides to stop playing (i.e. does not say "yes" when asked to keep playing), the application says
     * via voice output that the application has ended. */
    delete bet;
    output.outputAsVoice("Application has ended. Thank you for playing!");
    return 0;
}
