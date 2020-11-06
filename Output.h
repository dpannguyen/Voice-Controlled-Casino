#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Output {
	private:
		string output;

	public:
		Output();

		string getOutput { return output; }
		void talkTalk(string talk);

		~Output();
}
