#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <MicrosoftCognitiveServicesSpeech/speechapi_cxx.h>

class Input {
	public:
		Input();
		~Input();
		std::string inputFromVoice();
		std::string inputFromString();
};

#endif
