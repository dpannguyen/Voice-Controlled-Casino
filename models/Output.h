#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
#include <MicrosoftCognitiveServicesSpeech/speechapi_cxx.h>

class Output {
	public:
		Output();
		~Output();
		void outputAsVoice(std::string output);
		void outputAsString(std::string output);
};

#endif
