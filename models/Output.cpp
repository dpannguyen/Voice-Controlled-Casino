#include "Output.h"

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

Output::Output() {}

Output::~Output() {}

void Output::outputAsVoice(string output) {
	setlocale(LC_ALL, "");
	auto config = SpeechConfig::FromSubscription("ef38dbb1561f43b49632d58e29398f28", "canadacentral");
	auto synthesizer = SpeechSynthesizer::FromConfig(config);

	auto result = synthesizer->SpeakTextAsync(output).get();

	if (result->Reason == ResultReason::SynthesizingAudioCompleted) {
		cout << "The application said: " << output << endl;
		cout << endl;
	
	} else if (result->Reason == ResultReason::Canceled) {
		auto cancellation = SpeechSynthesisCancellationDetails::FromResult(result);
		cout << "The speech synthesizing process was cancelled.\n";
		cout << "Please verify the subscription details or connection to host.\n" << endl;

		cout << "Reason: " << (int) cancellation->Reason << endl;

		if (cancellation->Reason == CancellationReason::Error) {
            cout << "ErrorCode = " << (int) cancellation->ErrorCode << endl;
            cout << "ErrorDetails =" << cancellation->ErrorDetails << endl;
        }
		exit(1);		
	}
}

void Output::outputAsString(string output) {
	cout << output << endl;
	cout << endl;
}


