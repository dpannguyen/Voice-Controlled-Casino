#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Output {
	private:
		std::string output;

	public:
		Output();

		std::string getOutput() { return output; }
		void talkTalk(std::string talk);

		~Output();
};
#endif
