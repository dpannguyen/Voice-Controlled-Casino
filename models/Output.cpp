/**
 * @file Output.cpp
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * 
 * This file initializes an object of class Output, and uses Microsoft's Speech API to provide speech output.
 * This ultimately allows a user to play Blackjack and receive voice updates throughout the game.
 * It also contains a method that uses standard cout to provide updates in the form of command line text.
 */

#include "Output.h"

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

/**
 * Constructor for a Output object. 
 */
Output::Output() {}

/**
 * Destructor for a Output object. 
 */
Output::~Output() {}

/**
 * Uses the Microsoft Speech API to output text commands in the form of speech.
 * @param output The string to be processed into speech.
 * @return Void.
 */
void Output::outputAsVoice(string output)
{
	setlocale(LC_ALL, "");
	auto config = SpeechConfig::FromSubscription("023548ea8c1e485a9ef13557bb98d402", "canadacentral");
	auto synthesizer = SpeechSynthesizer::FromConfig(config);

	auto result = synthesizer->SpeakTextAsync(output).get();

	if (result->Reason == ResultReason::SynthesizingAudioCompleted)
	{
		cout << "The application said: " << output << endl;
		cout << endl;
	}
	else if (result->Reason == ResultReason::Canceled)
	{
		auto cancellation = SpeechSynthesisCancellationDetails::FromResult(result);
		cout << "The speech synthesizing process was cancelled.\n";
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
}

/**
 * Uses standard cout to process a string and output to the command line.
 * @param output The string to be outputted via cout.
 * @return Void
 */
void Output::outputAsString(string output)
{
	cout << output << endl;
	cout << endl;
}
