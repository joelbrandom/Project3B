#include "stdafx.h"
#include <iostream>
#include <string>
#include "Morse.h"

int main()
{
	// encodeInput will be encoded and outputted in Morse
	// decodeInput will be decoded and outputted with corresponding alphabetical characters
	std::string encodeInput = "HelloWorld", decodeInput = "... _ ._ _.__";
	Morse morse;
	morse.populateMapAndTree("morse.txt");
	std::cout << encodeInput << " encoded: " << morse.encodeMessage(encodeInput) << '\n';
	std::cout << decodeInput << " decoded: " << morse.decodeMessage(decodeInput) << '\n';
	// Set a breakpoint here to pause program
	return 0;
}
