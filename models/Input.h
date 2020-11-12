#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input {
	private:
		std::string command;

	public:
		// constructor
		Input();

		std::string getCommand() { return command; }
		void inputFromString();
		void inputFromVoice();

		//destructor
		~Input();
};
#endif
