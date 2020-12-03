/**
 * @file Input.h
 * @author Bridget Aine Hart , Zheng Frank Jiao , An Nguyen , Xuanran Qi , Christine Yang
 * @date December 2, 2020
 * @brief Header file containing declarations for the Input class, which involves processing user input in the forms of speech and text.
 */

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <speechapi_cxx.h>

class Input
{
private:
	std::string command; /**< string containing the user's input */

public:
	/** @brief Constructor for a Input object. */
	Input();
	/** @brief Destructor for a Input object. */
	~Input();
	
	/** @brief Method that processes human speech and returns it as a string. */
	std::string inputFromVoice();
	/** @brief Method that processes user text input and returns it as a string. */
	std::string inputFromString();
};

#endif
