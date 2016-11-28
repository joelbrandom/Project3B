#ifndef Morse_h
#define Morse_h

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include "Binary_Tree.h"

class Morse
{
private:
	std::map<const char, std::string> encode;
	Binary_Tree<std::string> decoder;
public:
	Morse();
	std::string encodeMessage(const std::string&);
	std::string decodeMessage(const std::string&);
	void populateEncodeMap();
	void populateDecodeTree(const std::string&);
	void populateDecodeTree2(const std::string&);
};

Morse::Morse()
{
	populateEncodeMap();
	populateDecodeTree("/Users/joel/Documents/School/UMKC Fall 2016/Data Structures/Projects/morse.txt");
}

std::string Morse::encodeMessage(const std::string& input)
{
	std::string result;
	for (int i = 0; i < input.length(); ++i)
	{
		result += encode[tolower(input.at(i))];
		if (i + 1 < input.length())
			result += " ";
	}
	return result;
}

std::string Morse::decodeMessage(const std::string& input)
{
	std::string output;
	BTNode<std::string>* local_root = decoder.getRoot();
	for (int i = 0; i < input.length(); ++i)
	{
		if (input.at(i) == '.')
		{
			if (local_root->left == NULL)
				return "Error: Invalid code (no corresponding letter, too far left).\n";
			local_root = local_root->left;
		}
		if (input.at(i) == '_')
		{
			if (local_root->right == NULL)
				return "Error: Invalid code (no corresponding letter, too far right).\n";
			local_root = local_root->right;
		}
		if (input.at(i) == ' ' || input[i + 1] == '\0')
		{
			output += local_root->data;
			local_root = decoder.getRoot();
		}
	}
	return output;
}

void Morse::populateEncodeMap()
{
	encode['a'] = "._";
	encode['b'] = "_...";
	encode['c'] = "_._.";
	encode['d'] = "_..";
	encode['e'] = ".";
	encode['f'] = ".._.";
	encode['g'] = "__.";
	encode['h'] = "....";
	encode['i'] = "..";
	encode['j'] = ".___";
	encode['k'] = "_._";
	encode['l'] = "._..";
	encode['m'] = "__";
	encode['n'] = "_.";
	encode['o'] = "___";
	encode['p'] = ".__.";
	encode['q'] = "__._";
	encode['r'] = "._.";
	encode['s'] = "...";
	encode['t'] = "_";
	encode['u'] = ".._";
	encode['v'] = "..._";
	encode['w'] = ".__";
	encode['x'] = "_.._";
	encode['y'] = "_.__";
	encode['z'] = "__..";
	//encode[' '] = " ";
}

void Morse::populateDecodeTree(const std::string& source)
{
	Binary_Tree<std::string> decode("");
	std::ifstream ifs(source);
	if (ifs)
	{
		std::string letter, line, code;
		while (getline(ifs, line))
		{
			BTNode<std::string>* local_root = decode.getRoot();
			letter = line[0];
			for (int i = 1; i < line.length(); ++i)
			{
				code = line[i];
				if (code == ".")
				{
					if (local_root->left == NULL)
						local_root->left = new BTNode<std::string>("");
					local_root = local_root->left;
				}
				if (code == "_")
				{
					if (local_root->right == NULL)
						local_root->right = new BTNode<std::string>("");
					local_root = local_root->right;
				}
			}
			local_root->data = letter;
		}
		ifs.close();
	}
	decoder = decode;
}

#endif