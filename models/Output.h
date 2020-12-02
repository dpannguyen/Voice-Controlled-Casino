/**
 * @file Output.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header file containing declarations for the Output class, which uses the Microsoft Speech API to provide speech output as voice updates regarding game status.
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
#include <speechapi_cxx.h>

class Output
{
public:
	/** @brief Constructor for a Output object. */
	Output();
	/** @brief Destructor for a Output object. */
	~Output();
	
	/** @brief Method that processes a string and outputs in the form of automated speech. */
	void outputAsVoice(std::string output);
	/** @brief Method that outputs a string in the command line. */
	void outputAsString(std::string output);
};

#endif
