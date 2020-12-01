#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <speechapi_cxx.h>

class Input {
	private:
		std::string command;
		
	public:
		Input();
		~Input();
		
		std::string inputFromVoice();
		std::string inputFromString();
};

#endif
