#include "Input.h"

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

Input::Input() {}

Input::~Input() {}

// Allows a human to play blackjack using input via voice commands.
string Input::inputFromVoice() {
	setlocale(LC_ALL, "");
	auto config = SpeechConfig::FromSubscription("ef38dbb1561f43b49632d58e29398f28", "canadacentral");
	auto recognizer = SpeechRecognizer::FromConfig(config);
	string command;

	cout << "Speak your command: \n";
	auto result = recognizer->RecognizeOnceAsync().get();
	
	if (result->Reason == ResultReason::RecognizedSpeech) {
		cout << "You said: " << result->Text << endl;
		command = result->Text;

	} else if (result->Reason == ResultReason::NoMatch) {
        cout << "The application could not process your voice command properly.\n";
		exit(1);
		
	} else if (result->Reason == ResultReason::Canceled) {
        auto cancellation = CancellationDetails::FromResult(result);
		cout << "The speech recognition process was cancelled.\n";
		cout << "Please verify the subscription details or connection to host.\n" << endl;

        cout << "Reason: " << (int) cancellation->Reason << endl;

        if (cancellation->Reason == CancellationReason::Error) {
            cout << "ErrorCode = " << (int) cancellation->ErrorCode << endl;
            cout << "ErrorDetails =" << cancellation->ErrorDetails << endl;
        }
		exit(1);
    }
	return command;
}

// Allows a human to play blackjack using input via text commands.
string Input::inputFromString() {
	string command;
	cout << "Enter your command: ";
    getline(cin, command);
	return command;
}
