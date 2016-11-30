#ifndef Morse_h
#define Morse_h

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Binary_Tree.h"

class Morse
{
private:
	std::map<const char, std::string> encoder;
	Binary_Tree<std::string> decoder;
public:
	Morse();
	std::string encodeMessage(const std::string&);
	std::string decodeMessage(const std::string&);
	void populateMapAndTree(const std::string&);
};

/* Constructor for Morse class
When constructor is called, encoder and decoder will be populated with
populateEncodeMap() and populateDecodeTree()
*/
Morse::Morse()
{
}

/* Encodes string of alphabetical characters to Morse and returns as string
@param input String to be encoded
*/
std::string Morse::encodeMessage(const std::string& input)
{
	std::string result;
	// Go through input string character by character
	for (size_t i = 0; i < input.length(); ++i)
	{
		// Assign current letter (input[i]) to current_letter
		// This is the letter we're currently working with
		char current_letter = input.at(i);

		// If letter is not alphabetical, return error
		if (!isalpha(current_letter))
			return "Error: a non-alphabetical character was found.\n";

		// Get the corresponding Morse from encoder map using current letter
		// tolower() in case user inputs any capital letters
		result += encoder[tolower(current_letter)];
		// If there's more characters to be encoded, add a space before next loop
		if (i + 1 < input.length())
			result += " ";
	}
	return result;
}

/* Decodes string of Morse (. and _) and returns string of corresponding alphabetical values
@param input String to be decoded
*/
std::string Morse::decodeMessage(const std::string& input)
{
	std::string output;
	// Create local_root at the root of decoder tree
	BTNode<std::string>* local_root = decoder.getRoot();
	// Go through input character by character
	for (size_t i = 0; i < input.length(); ++i)
	{
		// If we encounter a ., go left
		if (input.at(i) == '.')
		{
			// If left of local_root is NULL, return error
			if (local_root->left == NULL)
				return "Error: Invalid code (no corresponding letter, too far left).\n";
			local_root = local_root->left;
		}
		// If we encounter a _, go right
		if (input.at(i) == '_')
		{
			// If right of local_root is NULL, return error
			if (local_root->right == NULL)
				return "Error: Invalid code (no corresponding letter, too far right).\n";
			local_root = local_root->right;
		}
		// If we encounter a space or end of input, append local_root's data to output
		// and reset local_root to the root of decoder tree
		if (input.at(i) == ' ' || input[i + 1] == '\0')
		{
			output += local_root->data;
			local_root = decoder.getRoot();
		}
	}
	return output;
}

/* Populates binary tree for decoding and map for encoding
@param source Source file with alphabetical characters and their corresponding Morse
*/
void Morse::populateMapAndTree(const std::string& source)
{
	Binary_Tree<std::string> decode("");
	std::ifstream ifs(source);
	if (ifs)
	{
		std::string line, code;
		char letter;
		while (getline(ifs, line))
		{
			// Create local_root at root of decode tree
			BTNode<std::string>* local_root = decode.getRoot();
			// The alphabetical character (letter) will be the first character in the line
			letter = line.at(0);

			// Populate encoder map at letter with corresponding Morse (the rest of the line = code)
			encoder[letter] = line.substr(1, line.length() - 1);

			// Go through line character by character after letter (0)
			for (size_t i = 1; i < line.length(); ++i)
			{
				// code is the value we're checking against, our current character of line
				code = line[i];
				// If code is ., go left
				if (code == ".")
				{
					// If left of local_root is NULL, create a node there with a temp value
					if (local_root->left == NULL)
						local_root->left = new BTNode<std::string>("");
					local_root = local_root->left;
				}
				// If code is _, go right
				if (code == "_")
				{
					// If right of local_root is NULL, create a node there with a temp value
					if (local_root->right == NULL)
						local_root->right = new BTNode<std::string>("");
					local_root = local_root->right;
				}
			}
			// If we reached this point, local_root is pointing to the node we want to assign letter to
			local_root->data = letter;
		}
		ifs.close();
	}
	// Assign decode (the tree we worked with in this function) to decoder (private tree of Morse class)
	decoder = decode;
}

#endif