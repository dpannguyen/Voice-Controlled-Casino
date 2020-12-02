/**
 * @file Input.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Input, and uses Microsoft's Speech API to process user input in the form of speech.
 * This ultimately allows a user to play Blackjack using voice commands as input.
 * It also contains a method that uses standard cout/cin to process text commands as input.
 */

#include "Input.h"

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

/**
 * Constructor for a Input object. 
 */
Input::Input() {}

/**
 * Destructor for a Input object. 
 */
Input::~Input() {}

/**
 * Uses the Microsoft Speech API to recognize a human voice, 
 * and processes that sound into words that are outputted in the form of a string.
 * @return string
 */
string Input::inputFromVoice()
{
	setlocale(LC_ALL, "");
	auto config = SpeechConfig::FromSubscription("023548ea8c1e485a9ef13557bb98d402", "canadacentral");
	auto recognizer = SpeechRecognizer::FromConfig(config);

	cout << "Speak your command: \n";
	auto result = recognizer->RecognizeOnceAsync().get();

	if (result->Reason == ResultReason::RecognizedSpeech)
	{
		cout << "You said: " << result->Text << endl;
		cout << endl;
		command = result->Text;
	}
	else if (result->Reason == ResultReason::NoMatch)
	{
		cout << "The application could not process your voice command properly.\n";
		return "";
	}
	else if (result->Reason == ResultReason::Canceled)
	{
		auto cancellation = CancellationDetails::FromResult(result);
		cout << "The speech recognition process was cancelled.\n";
		cout << "Please verify the subscription details or connection to host.\n"
			 << endl;

		cout << "Reason: " << (int)cancellation->Reason << endl;

		if (cancellation->Reason == CancellationReason::Error)
		{
			cout << "ErrorCode = " << (int)cancellation->ErrorCode << endl;
			cout << "ErrorDetails =" << cancellation->ErrorDetails << endl;
		}
		exit(1);
	}

	for (unsigned int i = 0; i < command.size(); i++)
	{
		command[i] = tolower(command[i]);
	}
	return command;
}

/**
 * Uses standard cin to collect input from the command line from a user, and return it as a string.
 * @return string
 */
string Input::inputFromString()
{
	cout << "Enter your command: ";
	getline(cin, command);
	return command;
}
